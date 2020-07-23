#include "decaf_controller.h"

DecafController::DecafController() {}

void DecafController::load_file(string &file_name) {
  file_stream.open(file_name);
  ANTLRInputStream input(file_stream);

  DecafLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  DecafParser parser(&tokens);

  auto draw_listener = TreeListener(&parser);
  // parser.addParseListener(&draw_listener);

  DecafParser::ProgramContext *tree = parser.program();
  ParseTreeWalker::DEFAULT.walk(&draw_listener, tree);
  tree_root = draw_listener.get_current();
  std::cout << "Program parsed!" << std::endl;
}

shared_ptr<DataNode> DecafController::get_parse_root() { return tree_root; }

TreeListener::TreeListener(DecafParser *parser_ptr) {
  parser = parser_ptr;
  current_node = make_shared<DataNode>(DataNode("program"));
}

TreeListener::~TreeListener() {}

shared_ptr<DataNode> TreeListener::get_current() { return current_node; }

void TreeListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
  auto tokens = parser->getRuleNames();
  auto rule_name = tokens[ctx->getRuleIndex()];
  cout << "Entered rule: " << rule_name << endl;

  current_node->set_text(rule_name);

  for (auto &c : ctx->children) {
    auto new_node = DataNode("", current_node);
    if (c->children.size() == 0) {
      new_node.set_text(c->getText());
      new_node.visit();
    }
    current_node->add_child(make_shared<DataNode>(new_node));
  }

  auto next_child = current_node->get_first_not_visited();
  if (next_child != nullptr) {
    current_node = next_child;
  }
}

void TreeListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
  auto tokens = parser->getRuleNames();
  auto rule_name = tokens[ctx->getRuleIndex()];
  cout << "Exited rule: " << rule_name << endl;

  current_node->visit();

  if (current_node->get_parent() != nullptr) {
    auto next_sibling = current_node->get_parent()->get_first_not_visited();
    if (next_sibling == nullptr) {
      current_node = current_node->get_parent();
    } else {
      current_node = next_sibling;
    }
  }
}