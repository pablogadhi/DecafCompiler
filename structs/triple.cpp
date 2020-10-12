#include "triple.h"
#include <stack>

Address::Address(int value) : a_value(value) {}
// Address::~Address() {}
int Address::value() { return a_value; }
void Address::change(int new_value) { a_value = new_value; }

Literal::Literal(string type, string value)
    : Address(-1), l_type(type), l_value(value) {}
Literal::~Literal() {}
string Literal::type() { return l_type; }
string Literal::value() { return l_value; }

Triple::Triple(Operator op, shared_ptr<Address> arg0, shared_ptr<Address> arg1)
    : Address(-1), t_op(op), t_arg0(arg0), t_arg1(arg1) {}
Triple::~Triple() {}
Operator Triple::op() { return t_op; }
shared_ptr<Address> Triple::arg0() { return t_arg0; }
shared_ptr<Address> Triple::arg1() { return t_arg1; }
void Triple::set_arg0(shared_ptr<Address> new_arg0) { t_arg0 = new_arg0; }

TACode::TACode() {}
TACode::~TACode() {}
vector<shared_ptr<Triple>> &TACode::code() { return code_vec; }
shared_ptr<Address> TACode::gen(Operator op, shared_ptr<Address> arg0,
                                shared_ptr<Address> arg1) {
  auto new_triple = make_shared<Triple>(op, arg0, arg1);
  code_vec.push_back(new_triple);
  return dynamic_pointer_cast<Address>(new_triple);
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
  default:
    return "";
  }
}

string deduct_address(shared_ptr<Address> address_ptr,
                      stack<string> &temp_vars) {
  auto as_literal = dynamic_pointer_cast<Literal>(address_ptr);
  if (as_literal != nullptr) {
    return as_literal->value();
  }
  if (address_ptr->value() != -1) {
    return "_MEM[" + to_string(address_ptr->value()) + "]";
  }

  auto temp = temp_vars.top();
  temp_vars.pop();
  return temp;
}

string new_temp(stack<string> &temp_vars) {
  auto new_temp = TEMP_NAME + to_string(temp_vars.size());
  temp_vars.push(new_temp);
  return new_temp;
}

string TACode::translate() {
  string final_code = "";
  stack<string> temp_vars;

  for (auto &instr : code_vec) {
    string code_line = "";

    switch (instr->op()) {
    case Operator::ASSIGN: {
      auto r_value = deduct_address(instr->arg1(), temp_vars);
      auto l_value = deduct_address(instr->arg0(), temp_vars);
      if (l_value.substr(0, TEMP_NAME.size()) == TEMP_NAME) {
        l_value = "_MEM[" + l_value + "]";
      }
      code_line = l_value + " = " + r_value + "\n";
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
      auto label_literal = dynamic_pointer_cast<Literal>(instr->arg0());
      code_line = label_literal->value() + ":\n";
      break;
    }
    case Operator::IF:
    case Operator::JUMP:
      code_line = operator_symbol(instr->op()) + " " +
                  deduct_address(instr->arg0(), temp_vars) + "\n";
      break;

    unary_op:
      code_line = new_temp(temp_vars) + " = " + operator_symbol(instr->op()) +
                  " " + deduct_address(instr->arg0(), temp_vars) + "\n";
      break;
    binary_op:
      code_line = new_temp(temp_vars) + " = " +
                  deduct_address(instr->arg0(), temp_vars) + " " +
                  operator_symbol(instr->op()) + " " +
                  deduct_address(instr->arg1(), temp_vars) + "\n";
      break;

    default:
      break;
    }

    final_code += code_line;
  }

  return final_code;
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
string TACode::new_label() {
  string label = "_CODE_" + to_string(label_counter);
  label_counter++;
  return label;
}