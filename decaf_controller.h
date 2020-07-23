#ifndef DECAF_CONTROLLER_H
#define DECAF_CONTROLLER_H

#include "core/DecafBaseListener.h"
#include "core/DecafLexer.h"
#include "core/DecafParser.h"
#include "data_tree.h"
#include <antlr4-runtime/antlr4-common.h>
#include <antlr4-runtime/tree/ParseTreeWalker.h>

using namespace antlr4;
using namespace antlr4::tree;
using namespace decafcore;
using namespace std;

class TreeListener : public DecafBaseListener {
private:
  DecafParser *parser;
  shared_ptr<DataNode> current_node;

public:
  TreeListener(DecafParser *);
  ~TreeListener();
  void enterEveryRule(antlr4::ParserRuleContext *);
  void exitEveryRule(antlr4::ParserRuleContext *);
  shared_ptr<DataNode> get_current();
};

class ErrorItem {
private:
  int line;
  int row;
  string msg;

public:
  ErrorItem(int, int, string);
  ~ErrorItem();
  int get_line();
  int get_row();
  string get_msg();
};

class CustomErrorListener : public BaseErrorListener {
private:
  vector<ErrorItem> error_list;

public:
  void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line,
                   size_t charPositionInLine, const std::string &msg,
                   std::exception_ptr e);
  vector<ErrorItem> get_errors();
};

class DecafController {
private:
  ifstream file_stream;
  shared_ptr<DataNode> tree_root;
  vector<ErrorItem> error_list;

public:
  DecafController();
  void load_file(string &);
  shared_ptr<DataNode> get_parse_root();
  vector<ErrorItem> get_errors();
};

#endif