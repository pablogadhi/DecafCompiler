
// Generated from Decaf.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


#include "../structs/symb_table.h"
#include "../structs/error_item.h"


namespace decafcore {


class  DecafParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, ID = 38, 
    NUM = 39, CHAR = 40, WS = 41
  };

  enum {
    RuleProgram = 0, RuleDeclaration = 1, RuleVarDeclaration = 2, RuleStructDeclaration = 3, 
    RuleVarType = 4, RuleMethodDeclaration = 5, RuleMethodType = 6, RuleParameter = 7, 
    RuleParameterType = 8, RuleBlock = 9, RuleStatement = 10, RuleLocation = 11, 
    RuleExpression = 12, RuleMethodCall = 13, RuleArg = 14, RuleArith_op = 15, 
    RuleArith_high_precedence = 16, RuleArith_low_precedence = 17, RuleRel_op = 18, 
    RuleEq_op = 19, RuleCond_and = 20, RuleCond_or = 21, RuleLiteral = 22, 
    RuleInt_literal = 23, RuleChar_literal = 24, RuleBool_literal = 25
  };

  DecafParser(antlr4::TokenStream *input);
  ~DecafParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  SymbolTable symbol_table();
  void set_error_handler(ErrorHandler*);


  class ProgramContext;
  class DeclarationContext;
  class VarDeclarationContext;
  class StructDeclarationContext;
  class VarTypeContext;
  class MethodDeclarationContext;
  class MethodTypeContext;
  class ParameterContext;
  class ParameterTypeContext;
  class BlockContext;
  class StatementContext;
  class LocationContext;
  class ExpressionContext;
  class MethodCallContext;
  class ArgContext;
  class Arith_opContext;
  class Arith_high_precedenceContext;
  class Arith_low_precedenceContext;
  class Rel_opContext;
  class Eq_opContext;
  class Cond_andContext;
  class Cond_orContext;
  class LiteralContext;
  class Int_literalContext;
  class Char_literalContext;
  class Bool_literalContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table);
    virtual size_t getRuleIndex() const override;
    StructDeclarationContext *structDeclaration();
    VarDeclarationContext *varDeclaration();
    MethodDeclarationContext *methodDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration(shared_ptr<SymbolTable> table);

  class  VarDeclarationContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    int * struct_size;
    string name;
    string d_type;
    int size;
    int line;
    int pos;
    DecafParser::VarTypeContext *varTypeContext = nullptr;;
    antlr4::Token *idToken = nullptr;;
    antlr4::Token *numToken = nullptr;;
    VarDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    VarDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table, int * struct_size);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NUM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclarationContext* varDeclaration(shared_ptr<SymbolTable> table,int * struct_size);

  class  StructDeclarationContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    string d_type;
    int size;
    shared_ptr<SymbolTable> new_table;
    int l_size = 0;
    antlr4::Token *idToken = nullptr;;
    StructDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    StructDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<VarDeclarationContext *> varDeclaration();
    VarDeclarationContext* varDeclaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructDeclarationContext* structDeclaration(shared_ptr<SymbolTable> table);

  class  VarTypeContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    string d_type;
    int size;
    antlr4::Token *idToken = nullptr;;
    DecafParser::StructDeclarationContext *structDeclarationContext = nullptr;;
    VarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    VarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    StructDeclarationContext *structDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarTypeContext* varType(shared_ptr<SymbolTable> table);

  class  MethodDeclarationContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    vector<string> params;
    shared_ptr<SymbolTable> new_table;
    DecafParser::MethodTypeContext *methodTypeContext = nullptr;;
    antlr4::Token *idToken = nullptr;;
    MethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    MethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table);
    virtual size_t getRuleIndex() const override;
    MethodTypeContext *methodType();
    antlr4::tree::TerminalNode *ID();
    BlockContext *block();
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodDeclarationContext* methodDeclaration(shared_ptr<SymbolTable> table);

  class  MethodTypeContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    MethodTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodTypeContext* methodType();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    vector<string> * meth_params;
    DecafParser::ParameterTypeContext *parameterTypeContext = nullptr;;
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState, vector<string> * meth_params);
    virtual size_t getRuleIndex() const override;
    ParameterTypeContext *parameterType();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter(vector<string> * meth_params);

  class  ParameterTypeContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    ParameterTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterTypeContext* parameterType();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    string method_name;
    shared_ptr<SymbolTable> new_table;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table, string method_name);
    virtual size_t getRuleIndex() const override;
    std::vector<VarDeclarationContext *> varDeclaration();
    VarDeclarationContext* varDeclaration(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block(shared_ptr<SymbolTable> table,string method_name);

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    MethodCallContext *methodCall();
    LocationContext *location();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement(shared_ptr<SymbolTable> table);

  class  LocationContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    string d_type;
    antlr4::Token *idToken = nullptr;;
    LocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    LocationContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ExpressionContext *expression();
    LocationContext *location();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocationContext* location(shared_ptr<SymbolTable> table);

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    DecafParser::LiteralContext *literalContext = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    LiteralContext *literal();
    Arith_high_precedenceContext *arith_high_precedence();
    Arith_low_precedenceContext *arith_low_precedence();
    Rel_opContext *rel_op();
    Eq_opContext *eq_op();
    Cond_andContext *cond_and();
    Cond_orContext *cond_or();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  MethodCallContext : public antlr4::ParserRuleContext {
  public:
    shared_ptr<SymbolTable> table;
    vector<string> arg_types;
    MethodCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    MethodCallContext(antlr4::ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<ArgContext *> arg();
    ArgContext* arg(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodCallContext* methodCall(shared_ptr<SymbolTable> table);

  class  ArgContext : public antlr4::ParserRuleContext {
  public:
    vector<string> * method_arg_types;
    shared_ptr<SymbolTable> table;
    DecafParser::ExpressionContext *expressionContext = nullptr;;
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState, vector<string> * method_arg_types, shared_ptr<SymbolTable> table);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgContext* arg(vector<string> * method_arg_types,shared_ptr<SymbolTable> table);

  class  Arith_opContext : public antlr4::ParserRuleContext {
  public:
    Arith_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Arith_high_precedenceContext *arith_high_precedence();
    Arith_low_precedenceContext *arith_low_precedence();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arith_opContext* arith_op();

  class  Arith_high_precedenceContext : public antlr4::ParserRuleContext {
  public:
    Arith_high_precedenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arith_high_precedenceContext* arith_high_precedence();

  class  Arith_low_precedenceContext : public antlr4::ParserRuleContext {
  public:
    Arith_low_precedenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arith_low_precedenceContext* arith_low_precedence();

  class  Rel_opContext : public antlr4::ParserRuleContext {
  public:
    Rel_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rel_opContext* rel_op();

  class  Eq_opContext : public antlr4::ParserRuleContext {
  public:
    Eq_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Eq_opContext* eq_op();

  class  Cond_andContext : public antlr4::ParserRuleContext {
  public:
    Cond_andContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cond_andContext* cond_and();

  class  Cond_orContext : public antlr4::ParserRuleContext {
  public:
    Cond_orContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cond_orContext* cond_or();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Int_literalContext *int_literal();
    Char_literalContext *char_literal();
    Bool_literalContext *bool_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  Int_literalContext : public antlr4::ParserRuleContext {
  public:
    Int_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Int_literalContext* int_literal();

  class  Char_literalContext : public antlr4::ParserRuleContext {
  public:
    Char_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Char_literalContext* char_literal();

  class  Bool_literalContext : public antlr4::ParserRuleContext {
  public:
    Bool_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bool_literalContext* bool_literal();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  shared_ptr<SymbolTable> table_head = make_shared<SymbolTable>("__global__");
  ErrorHandler *e_handler;
  int scope_counter = 0;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace decafcore
