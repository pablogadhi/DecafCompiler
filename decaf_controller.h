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

class DecafController {
private:
  ifstream file_stream;
  shared_ptr<DataNode> tree_root;

public:
  DecafController();
  void load_file(string &);
  shared_ptr<DataNode> get_parse_root();
};

#endif