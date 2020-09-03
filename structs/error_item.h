#ifndef ERROR_ITEM_H
#define ERROR_ITEM_H

#include <functional>
#include <string>
#include <vector>

using namespace std;

class ErrorItem {
private:
  int line;
  int pos;
  string msg;

public:
  ErrorItem(int, int, string);
  ~ErrorItem();
  int get_line();
  int get_pos();
  string get_msg();
};

enum ErrorType {
  LEX_SYN,
  IDENT_DEFINED,
  IDENT_NOT_DEFINED,
  REPEATED_PARAM,
  NO_MAIN,
  WRONG_NUM_ARRAY,
  WRONG_PARAMS,
  WRONG_RETURN,
  TYPE_ERROR
};

class ErrorHandler {
private:
  vector<ErrorItem> error_list;

public:
  ErrorHandler();
  ~ErrorHandler();
  void add_error(int, int, string);
  vector<ErrorItem> &errors();
  function<void()> get_lambda(ErrorType, int, int,
                              vector<string> msg_parts = vector<string>{});
};

#endif