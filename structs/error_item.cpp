#include "error_item.h"

ErrorItem::ErrorItem(int e_line, int e_pos, string e_msg)
    : line(e_line), pos(e_pos), msg(e_msg) {}
ErrorItem::~ErrorItem() {}
int ErrorItem::get_line() { return line; }
int ErrorItem::get_pos() { return pos; }
string ErrorItem::get_msg() { return msg; }

ErrorHandler::ErrorHandler() {}
ErrorHandler::~ErrorHandler() {}
void ErrorHandler::add_error(int line, int pos, string msg) {
  error_list.push_back(ErrorItem(line, pos, msg));
}
vector<ErrorItem> &ErrorHandler::errors() { return error_list; }
function<void()> ErrorHandler::get_lambda(ErrorType e_type, int line, int pos,
                                          vector<string> msg_parts) {
  string error_msg = "";
  switch (e_type) {
  case LEX_SYN:
    error_msg = msg_parts[0];
    break;
  case IDENT_DEFINED:
    error_msg = "Identifier " + msg_parts[0] +
                " was already defined in scope " + msg_parts[1];
    break;
  case IDENT_NOT_DEFINED:
    error_msg = "Identifier " + msg_parts[0] + " used before its definition";
    break;
  case NO_MAIN:
    error_msg = "Program doesn't contains a main() function definition";
    break;
  case WRONG_NUM_ARRAY:
    error_msg = "Ilegal use of array size definition, use an integer number "
                "greater than 0 instead";
    break;
  case NO_METHOD_WITH_SIGN: {
    string signature = "(";
    for (int i = 1; i < msg_parts.size(); i++) {
      signature += msg_parts[i] + ", ";
    }
    signature += ")";

    error_msg =
        "Method " + msg_parts[0] + " was defined with signature " + signature;
  }
  case WRONG_RETURN_TYPE:
    error_msg = "Wrong return type of method" + msg_parts[0] + ", " +
                msg_parts[1] + " expected, " + msg_parts[2] + " found";
    break;
  case NO_RETURN_IN_EXPR:
    error_msg = "Method " + msg_parts[0] + " does not return any value";
    break;
  default:
    break;
  }

  return [this, line, pos, error_msg]() { add_error(line, pos, error_msg); };
}