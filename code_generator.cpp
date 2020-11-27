#include "code_generator.h"
#include <fstream>
#include <iostream>

CodeGenerator::CodeGenerator(vector<Triple> code,
                             shared_ptr<SymbolTable> &table)
    : inter_code(code), symbol_table(table) {
  init_code();
  main_name = dynamic_pointer_cast<Literal>(inter_code[0].arg0())->value();
  end_label = dynamic_pointer_cast<Literal>(inter_code.back().arg0())->value();
  // The fist 2 instructions are useless, so we remove them
  inter_code.erase(inter_code.begin());
  inter_code.erase(inter_code.begin());
}
CodeGenerator::~CodeGenerator() {}

void CodeGenerator::init_code() {
  gen_code += "section .text\n\n";
  gen_code +=
      "extern _alloc_mem, _dealloc_mem, _init_brks, _print_int, _input_int\n";
  gen_code += "extern _last_brk, _current_brk\n\n";
  gen_code += "global _start\n";
}

string get_reg(string temp_name) {
  if (temp_name == "_tmp_0") {
    return "rbx";
  } else if (temp_name == "_tmp_1") {
    return "rcx";
  }
  return "rdx";
}

string CodeGenerator::operand_to_str(shared_ptr<Address> operand,
                                     vector<Triple> &pending) {
  auto as_literal = dynamic_pointer_cast<Literal>(operand);
  if (as_literal != nullptr) {
    string literal_val = as_literal->value();

    if (as_literal->type() == "string") {
      if (literal_val[0] != '_') {
        if (literal_val != main_name) {
          literal_val = "_" + literal_val;
        } else {
          literal_val = "_start";
        }
      } else {
        literal_val = "." + literal_val.substr(1, literal_val.size() - 1);
      }
    } else {
      Type type;
      get_where<Type>(
          symbol_table->types(),
          [&](Type &t) { return t.name() == as_literal->type(); }, &type);
      literal_val = size_prefixes[type.size()] + " " + literal_val;
    }

    return literal_val;
  }

  auto as_temp = dynamic_pointer_cast<Temp>(operand);
  if (as_temp != nullptr) {

    // Add pending pops
    for (auto &p : pending) {
      auto pending_temp = dynamic_pointer_cast<Temp>(p.arg0());
      if (pending_temp->name() == as_temp->name()) {
        for (int i = pending.size() - 1; i >= 0; i--) {
          auto p_temp_name =
              dynamic_pointer_cast<Temp>(pending[i].arg0())->name();
          gen_code += "  pop " + get_reg(p_temp_name) + "\n";
        }
        pending.clear();
        break;
      }
    }

    if (as_temp->as_offset()) {
      return "[" + get_reg(as_temp->name()) + "]";
    } else {
      return get_reg(as_temp->name());
    }
  }

  if (operand->value() != -1) {
    return "[r14+" + to_string(operand->value()) + "]";
  }

  return "";
}

string CodeGenerator::convert_reg(string reg, int size) {
  string base = reg;
  function<string(string)> word_transform;

  if (reg.back() == 'x') {
    base = reg.substr(1, 1);
    word_transform = [](string reg_b) { return "e" + reg_b + "x"; };
  } else {
    word_transform = [](string reg_b) { return reg_b + "d"; };
  }

  if (size == 1) {
    return base + "l";
  } else if (size == 4) {
    return word_transform(base);
  }

  return base;
}

void CodeGenerator::translate_to_asm() {
  shared_ptr<SymbolTable> local_table;
  string cond_jump = "";
  vector<Triple> pending;
  bool skip_pop = false;

  for (int i = 0; i < inter_code.size(); i++) {
    Triple &instr = inter_code[i];

    switch (instr.op()) {
    case Operator::ASSIGN: {
      auto l_operand = operand_to_str(instr.arg0(), pending);
      auto r_operand = operand_to_str(instr.arg1(), pending);

      if (dynamic_pointer_cast<Temp>(instr.arg0()) != nullptr &&
          instr.arg1()->value() != -1) {
        Symbol symb;
        get_where<Symbol>(
            local_table->symbols(),
            [&](Symbol &s) { return s.offset() == instr.arg1()->value(); },
            &symb);
        l_operand = convert_reg(l_operand, symb.size());
      } else if (dynamic_pointer_cast<Temp>(instr.arg1()) != nullptr &&
                 instr.arg0()->value() != -1) {
        Symbol symb;
        get_where<Symbol>(
            local_table->symbols(),
            [&](Symbol &s) { return s.offset() == instr.arg0()->value(); },
            &symb);
        r_operand = convert_reg(r_operand, symb.size());
      }

      gen_code += "  mov " + l_operand + ", " + r_operand + "\n";
      break;
    }
    case Operator::MUL: {
      auto l_operand = operand_to_str(instr.arg0(), pending);
      auto r_operand = operand_to_str(instr.arg1(), pending);

      if (dynamic_pointer_cast<Temp>(instr.arg0()) == nullptr) {
        int size = 8;
        if (instr.arg0()->value() != -1) {
          Symbol symb;
          get_where<Symbol>(
              local_table->symbols(),
              [&](Symbol &s) { return s.offset() == instr.arg0()->value(); },
              &symb);
          size = symb.size();
        }
        gen_code +=
            "  mov " + convert_reg("rax", size) + ", " + l_operand + "\n";
      } else {
        gen_code += "  mov rax, " + l_operand + "\n";
      }

      if (dynamic_pointer_cast<Temp>(instr.arg1()) == nullptr) {
        int size = 8;
        if (instr.arg1()->value() != -1) {
          Symbol symb;
          get_where<Symbol>(
              local_table->symbols(),
              [&](Symbol &s) { return s.offset() == instr.arg1()->value(); },
              &symb);
          size = symb.size();
        }
        gen_code +=
            "  mov " + convert_reg("rbx", size) + ", " + r_operand + "\n";
      } else {
        gen_code += "  mov rbx, " + r_operand + "\n";
      }

      gen_code += "  mul rbx\n";
      gen_code += "  mov " + operand_to_str(inter_code[i - 1].arg0(), pending) +
                  ", rax\n";

      break;
    }
    case Operator::SUM:
      gen_code += "  add " + operand_to_str(instr.arg0(), pending) + ", " +
                  operand_to_str(instr.arg1(), pending) + "\n";
      break;
    case Operator::LESS:
      cond_jump = "jl";
      break;
    case Operator::LESS_EQ:
      cond_jump = "jle";
      break;
    case Operator::GREATER:
      cond_jump = "jg";
      break;
    case Operator::GREATER_EQ:
      cond_jump = "jge";
      break;
    case Operator::EQ:
      cond_jump = "je";
      break;
    case Operator::NOT_EQ:
      cond_jump = "jne";
      break;
    case Operator::MINUS:
      if (instr.arg1() != nullptr) {
        gen_code += "  sub " + operand_to_str(instr.arg0(), pending) + ", " +
                    operand_to_str(instr.arg1(), pending) + "\n";
      }
      break;
    case Operator::LABEL: {
      auto alias = dynamic_pointer_cast<Literal>(instr.arg0())->value();
      auto label_str = operand_to_str(instr.arg0(), pending);
      gen_code += "\n" + label_str + ":\n";

      if (label_str[0] == '_') {
        Method method;
        get_where<Method>(
            symbol_table->methods(),
            [=](Method &m) { return m.alias() == alias; }, &method);
        local_table = symbol_table->children()[method];
        auto last_symb = local_table->symbols().back();
        auto mem_to_alloc = last_symb.size() + last_symb.offset();

        // Call _init_brks if label is the main one
        if (alias == main_name) {
          gen_code += "  call _init_brks\n\n";
        }

        // Allocate memory for all variables
        gen_code += "  mov r13, [_last_brk]\n";
        gen_code += "  push r13\n";
        gen_code += "  push " + to_string(mem_to_alloc) + "\n";
        gen_code += "  call _alloc_mem\n";
        gen_code += "  pop r13\n";
        gen_code += "  pop r15\n";
        gen_code += "  mov r14, [_last_brk]\n";

        // Store each param in memory
        auto &symbols = local_table->symbols();
        for (int j = method.param_signature().size() - 1; j >= 0; j--) {
          gen_code += "  pop rbx\n";
          gen_code += "  mov [r14+" + to_string(symbols[j].offset()) + "], " +
                      convert_reg("rbx", symbols[j].size()) + "\n";
        }

        // Init the rest of variables
        for (int j = method.param_signature().size(); j < symbols.size(); j++) {
          Type type;
          recursive_lookup<Type>(
              local_table,
              [&](shared_ptr<SymbolTable> table) { return table->types(); },
              [&](Type &t) { return t.name() == symbols[j].type(); }, &type);
          if (type.type() == "basic") {
            string default_value = basic_init_vals[type.name()];
            gen_code += "  mov [r14+" + to_string(symbols[j].offset()) + "], " +
                        size_prefixes[type.size()] + " " + default_value + "\n";
          }
        }

        // Put back addresses on the vector
        gen_code += "  push r15\n";
        gen_code += "  push r13\n\n";
      } else if (alias == end_label) {
        gen_code += "  mov rax, 60\n";
        gen_code += "  xor rdi, rdi\n";
        gen_code += "  syscall\n";
      }

      break;
    }
    case Operator::IF:
      gen_code += "  cmp " + operand_to_str(instr.arg0(), pending) + ", " +
                  operand_to_str(inter_code[i - 1].arg1(), pending) + "\n";
      break;
    case Operator::JUMP:
      if (cond_jump != "") {
        gen_code += "  " + cond_jump + " " +
                    operand_to_str(instr.arg0(), pending) + "\n";
        cond_jump = "";
      } else {
        gen_code += "  jmp " + operand_to_str(instr.arg0(), pending) + "\n";
      }
      break;
    case Operator::CALL:
      gen_code += "  call " + operand_to_str(instr.arg0(), pending) + "\n";
      gen_code += "  mov r14, [_last_brk]\n";
      if (inter_code[i + 1].op() == Operator::POP) {
        pending.push_back(inter_code[i + 1]);
        skip_pop = true;
      }
      break;
    case Operator::PARAM:
    case Operator::PUSH: {
      if (inter_code[i + 1].op() == Operator::RET) {
        string reg = "r12";

        if (instr.arg0()->value() != -1) {
          Symbol symb;
          get_where<Symbol>(
              local_table->symbols(),
              [&](Symbol &s) { return s.offset() == instr.arg0()->value(); },
              &symb);
          reg = convert_reg(reg, symb.size());
        }

        gen_code += "  mov " + reg + ", " +
                    operand_to_str(instr.arg0(), pending) + "\n";

      } else {
        if (instr.arg0()->value() != -1) {
          Symbol symb;
          get_where<Symbol>(
              local_table->symbols(),
              [&](Symbol &s) { return s.offset() == instr.arg0()->value(); },
              &symb);

          gen_code += "  mov " + convert_reg("rbx", symb.size()) + ", " +
                      operand_to_str(instr.arg0(), pending) + "\n";
          gen_code += "  push rbx\n";
        } else {
          gen_code += "  push " + operand_to_str(instr.arg0(), pending) + "\n";
        }
      }
      break;
    }
    case Operator::POP:
      if (!skip_pop) {
        gen_code += "  pop " + operand_to_str(instr.arg0(), pending) + "\n";
      } else {
        skip_pop = false;
      }
      break;
    case Operator::RET:
      if (inter_code[i + 1].op() != Operator::LABEL ||
          dynamic_pointer_cast<Literal>(inter_code[i + 1].arg0())->value() !=
              end_label) {
        gen_code += "  call _dealloc_mem\n";
        gen_code += "  pop r15\n";
        // TODO Handle void fuctions
        gen_code += "  push r12\n";
        gen_code += "  push r15\n";
        gen_code += "  ret\n";
      }
      break;
    default:
      break;
    }
  }
}

void CodeGenerator::generate(string file_name) {
  auto dot_pos = file_name.find(".");
  auto asm_filename = file_name.substr(0, dot_pos) + ".asm";

  cout << asm_filename << endl;

  ofstream out_file;
  out_file.open(asm_filename);

  translate_to_asm();

  out_file << gen_code;
  out_file.close();
}