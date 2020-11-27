#include "triple.h"
#include <algorithm>
#include <map>
#include <set>
#include <stack>

Address::Address(int value) : a_value(value) {}
int Address::value() { return a_value; }
void Address::change(int new_value) { a_value = new_value; }

Literal::Literal(string type, string value)
    : Address(-1), l_type(type), l_value(value) {}
Literal::~Literal() {}
string Literal::type() { return l_type; }
string Literal::value() { return l_value; }

Triple::Triple(Operator op, shared_ptr<Address> arg0, shared_ptr<Address> arg1,
               bool temp_offset)
    : Address(-1), t_op(op), t_arg0(arg0), t_arg1(arg1),
      t_temp_offset(temp_offset) {}
Triple::Triple(Operator op) : Address(-1), t_op(op) {}
Triple::~Triple() {}
Operator Triple::op() { return t_op; }
shared_ptr<Address> &Triple::arg0() { return t_arg0; }
shared_ptr<Address> &Triple::arg1() { return t_arg1; }
void Triple::set_arg0(shared_ptr<Address> new_arg0) { t_arg0 = new_arg0; }
void Triple::set_arg1(shared_ptr<Address> new_arg1) { t_arg1 = new_arg1; }
bool Triple::temp_offset() { return t_temp_offset; }

Temp::Temp(string name) : Address(-1), t_name(name) {}
Temp::~Temp() {}
string Temp::name() { return t_name; }
bool Temp::as_offset() { return t_as_offset; }
void Temp::set_as_offset(bool new_val) { t_as_offset = new_val; }

TACode::TACode() {}
TACode::~TACode() {}
vector<shared_ptr<Triple>> &TACode::code() { return code_vec; }
shared_ptr<Address> TACode::gen(Operator op, shared_ptr<Address> arg0,
                                shared_ptr<Address> arg1, bool temp_offset) {
  auto new_triple = make_shared<Triple>(op, arg0, arg1, temp_offset);
  code_vec.push_back(new_triple);
  return dynamic_pointer_cast<Address>(new_triple);
}

void TACode::optimize_code() {
  // Remove unused labels
  set<string> found;
  set<string> declared;
  map<string, int> declared_indices;

  for (int i = 0; i < code_vec.size(); i++) {
    auto instr = code_vec[i];
    if (instr->op() == Operator::JUMP || instr->op() == Operator::CALL) {
      auto label = dynamic_pointer_cast<Literal>(instr->arg0());
      found.insert(label->value());
    } else if (instr->op() == Operator::LABEL) {
      auto label = dynamic_pointer_cast<Literal>(instr->arg0());
      declared.insert(label->value());
      declared_indices[label->value()] = i;
    }
  }

  vector<string> not_used;
  set_difference(declared.begin(), declared.end(), found.begin(), found.end(),
                 back_inserter(not_used));
  for (int i = 0; i < not_used.size(); i++) {
    auto label_str = not_used[i];
    if (label_str.substr(0, 7) == "_LOCAL_") {
      code_vec.erase(code_vec.begin() + declared_indices[label_str] - i);
    }
  }
}

const string TEMP_NAME = "_tmp_";

string operator_symbol(Operator op) {
  switch (op) {
  case Operator::ASSIGN:
    return "=";
  case Operator::MUL:
    return "*";
  case Operator::DIV:
    return "/";
  case Operator::MOD:
    return "%";
  case Operator::SUM:
    return "+";
  case Operator::MINUS:
    return "-";
  case Operator::LESS:
    return "<";
  case Operator::LESS_EQ:
    return "<=";
  case Operator::GREATER:
    return ">";
  case Operator::GREATER_EQ:
    return ">=";
  case Operator::EQ:
    return "==";
  case Operator::NOT_EQ:
    return "!=";
  case Operator::AND:
    return "&&";
  case Operator::OR:
    return "||";
  case Operator::NOT:
    return "!";
  case Operator::JUMP:
    return "goto";
  case Operator::IF:
    return "if";
  case Operator::CALL:
    return "call";
  case Operator::RET:
    return "ret";
  case Operator::PARAM:
    return "param";
  case Operator::PUSH:
    return "push";
  case Operator::POP:
    return "pop";
  default:
    return "";
  }
}

string deduct_address(shared_ptr<Address> &address_ptr,
                      stack<string> &temp_vars) {
  auto as_literal = dynamic_pointer_cast<Literal>(address_ptr);
  if (as_literal != nullptr) {
    return as_literal->value();
  }

  if (address_ptr->value() != -1) {
    return "_MEM[" + to_string(address_ptr->value()) + "]";
  }

  auto as_triple = dynamic_pointer_cast<Triple>(address_ptr);
  if (as_triple != nullptr) {
    auto temp = temp_vars.top();
    temp_vars.pop();

    auto temp_rep = make_shared<Temp>(temp);
    if (as_triple->temp_offset()) {
      temp = "_MEM[" + temp + "]";
      temp_rep->set_as_offset(true);
    }

    address_ptr = dynamic_pointer_cast<Address>(temp_rep);
    return temp;
  }

  return "";
}

string new_temp(stack<string> &temp_vars) {
  auto new_temp = TEMP_NAME + to_string(temp_vars.size());
  temp_vars.push(new_temp);
  return new_temp;
}

pair<vector<Triple>, string> TACode::translate() {
  vector<Triple> mem_code;
  string final_code = "";
  stack<string> temp_vars;

  optimize_code();

  for (auto &instr : code_vec) {
    string code_line = "    ";
    Triple mem_instr(instr->op());

    switch (instr->op()) {
    case Operator::ASSIGN: {
      auto r_value = deduct_address(instr->arg1(), temp_vars);
      auto l_value = deduct_address(instr->arg0(), temp_vars);
      code_line += l_value + " = " + r_value + "\n";
      mem_instr = *instr;
      break;
    }
    case Operator::MUL:
    case Operator::DIV:
    case Operator::MOD:
    case Operator::SUM:
    case Operator::LESS:
    case Operator::LESS_EQ:
    case Operator::GREATER:
    case Operator::GREATER_EQ:
    case Operator::EQ:
    case Operator::NOT_EQ:
    case Operator::AND:
    case Operator::OR:
      goto binary_op;
    case Operator::MINUS:
      if (instr->arg1() != nullptr) {
        goto binary_op;
      } else {
        goto unary_op;
      }
    case Operator::NOT:
      goto unary_op;
    case Operator::LABEL: {
      code_line = "\n" + deduct_address(instr->arg0(), temp_vars) + ":\n";
      mem_instr = *instr;
      break;
    }
    case Operator::IF:
    case Operator::JUMP:
    case Operator::CALL:
    case Operator::PARAM:
    case Operator::PUSH:
      goto simple_op;
    case Operator::POP:
      code_line +=
          operator_symbol(instr->op()) + " " + new_temp(temp_vars) + "\n";
      mem_instr.set_arg0(make_shared<Temp>(temp_vars.top()));
      break;
    case Operator::RET:
      code_line += operator_symbol(instr->op()) + "\n";
      break;

    unary_op : {
      code_line += new_temp(temp_vars) + " = " + operator_symbol(instr->op()) +
                   " " + deduct_address(instr->arg0(), temp_vars) + "\n";
      auto mem_temp = make_shared<Temp>(temp_vars.top());
      mem_code.push_back(Triple(Operator::ASSIGN, mem_temp, instr->arg0()));
      mem_instr = Triple(instr->op(), mem_temp);
      break;
    }
    binary_op : {
      code_line += new_temp(temp_vars) + " = " +
                   deduct_address(instr->arg0(), temp_vars) + " " +
                   operator_symbol(instr->op()) + " " +
                   deduct_address(instr->arg1(), temp_vars) + "\n";

      auto mem_temp = make_shared<Temp>(temp_vars.top());
      mem_code.push_back(Triple(Operator::ASSIGN, mem_temp, instr->arg0()));
      mem_instr = Triple(instr->op(), mem_temp, instr->arg1());
      break;
    }
    simple_op:
      code_line += operator_symbol(instr->op()) + " " +
                   deduct_address(instr->arg0(), temp_vars) + "\n";
      mem_instr = *instr;
      break;

    default:
      break;
    }

    final_code += code_line;
    mem_code.push_back(mem_instr);
  }

  return make_pair(mem_code, final_code);
}

vector<int> TACode::make_list(int instr_idx) {
  return vector<int>({instr_idx});
}
vector<int> TACode::merge(vector<int> list_0, vector<int> list_1) {
  list_0.insert(list_0.end(), list_1.begin(), list_1.end());
  return list_0;
}
void TACode::back_patch(vector<int> list, int label_idx) {
  auto instr_to_patch = code_vec[label_idx];
  for (auto &i : list) {
    code_vec[i]->set_arg0(instr_to_patch->arg0());
  }
}

int TACode::next_instr() { return code_vec.size(); }
string TACode::new_label(string prefix) {
  string label = prefix + to_string(label_counter);
  label_counter++;
  return label;
}