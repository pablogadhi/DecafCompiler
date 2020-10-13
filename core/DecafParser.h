
// Generated from /home/gadhi/Documents/Compis/Decaf/Decaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"


#include "../structs/symb_table.h"
#include "../structs/triple.h"
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
    RuleExpression = 12, RuleAritLowExpr = 13, RuleAritHighExpr = 14, RuleMinusExpr = 15, 
    RuleOrExpr = 16, RuleAndExpr = 17, RuleEqExpr = 18, RuleRelExpr = 19, 
    RuleNotExpr = 20, RuleAtomExpr = 21, RuleMethodCall = 22, RuleArg = 23, 
    RuleArith_high_op = 24, RuleArith_low_op = 25, RuleRel_op = 26, RuleEq_op = 27, 
    RuleAnd_op = 28, RuleOr_op = 29, RuleLiteral = 30, RuleInt_literal = 31, 
    RuleChar_literal = 32, RuleBool_literal = 33
  };

  DecafParser(antlr4::TokenStream *input);
  ~DecafParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  pair<SymbolTable, vector<vector<string>>> symbol_table();
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
  class AritLowExprContext;
  class AritHighExprContext;
  class MinusExprContext;
  class OrExprContext;
  class AndExprContext;
  class EqExprContext;
  class RelExprContext;
  class NotExprContext;
  class AtomExprContext;
  class MethodCallContext;
  class ArgContext;
  class Arith_high_opContext;
  class Arith_low_opContext;
  class Rel_opContext;
  class Eq_opContext;
  class And_opContext;
  class Or_opContext;
  class LiteralContext;
  class Int_literalContext;
  class Char_literalContext;
  class Bool_literalContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    Method main;
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
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StructDeclarationContext *structDeclaration();
    VarDeclarationContext *varDeclaration();
    MethodDeclarationContext *methodDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  VarDeclarationContext : public antlr4::ParserRuleContext {
  public:
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
    VarDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, int * struct_size);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NUM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclarationContext* varDeclaration(int * struct_size);

  class  StructDeclarationContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    int size;
    shared_ptr<SymbolTable> new_table;
    int l_size = 0;
    antlr4::Token *idToken = nullptr;;
    StructDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<VarDeclarationContext *> varDeclaration();
    VarDeclarationContext* varDeclaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructDeclarationContext* structDeclaration();

  class  VarTypeContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    int size;
    antlr4::Token *idToken = nullptr;;
    DecafParser::StructDeclarationContext *structDeclarationContext = nullptr;;
    VarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    StructDeclarationContext *structDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarTypeContext* varType();

  class  MethodDeclarationContext : public antlr4::ParserRuleContext {
  public:
    vector<Symbol> params;
    shared_ptr<SymbolTable> new_table;
    string alias;
    DecafParser::MethodTypeContext *methodTypeContext = nullptr;;
    antlr4::Token *idToken = nullptr;;
    MethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
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

  MethodDeclarationContext* methodDeclaration();

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
    vector<Symbol> * meth_params;
    DecafParser::ParameterTypeContext *parameterTypeContext = nullptr;;
    antlr4::Token *idToken = nullptr;;
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState, vector<Symbol> * meth_params);
    virtual size_t getRuleIndex() const override;
    ParameterTypeContext *parameterType();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter(vector<Symbol> * meth_params);

  class  ParameterTypeContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    int size;
    ParameterTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterTypeContext* parameterType();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    string method_name;
    vector<int> next_list;
    shared_ptr<SymbolTable> new_table;
    DecafParser::StatementContext *statementContext = nullptr;;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState, string method_name);
    virtual size_t getRuleIndex() const override;
    std::vector<VarDeclarationContext *> varDeclaration();
    VarDeclarationContext* varDeclaration(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block(string method_name);

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    vector<int> next_list;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WhileStatementContext : public StatementContext {
  public:
    WhileStatementContext(StatementContext *ctx);

    DecafParser::ExpressionContext *expressionContext = nullptr;
    ExpressionContext *expression();
    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BlockStatementContext : public StatementContext {
  public:
    BlockStatementContext(StatementContext *ctx);

    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MethodCallStatementContext : public StatementContext {
  public:
    MethodCallStatementContext(StatementContext *ctx);

    MethodCallContext *methodCall();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprStatementContext : public StatementContext {
  public:
    ExprStatementContext(StatementContext *ctx);

    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignStatementContext : public StatementContext {
  public:
    AssignStatementContext(StatementContext *ctx);

    DecafParser::LocationContext *locationContext = nullptr;
    DecafParser::ExpressionContext *expressionContext = nullptr;
    LocationContext *location();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfStatementContext : public StatementContext {
  public:
    IfStatementContext(StatementContext *ctx);

    DecafParser::ExpressionContext *expressionContext = nullptr;
    DecafParser::BlockContext *true_block = nullptr;
    DecafParser::BlockContext *false_block = nullptr;
    ExpressionContext *expression();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStatementContext : public StatementContext {
  public:
    ReturnStatementContext(StatementContext *ctx);

    antlr4::Token *r = nullptr;
    DecafParser::ExpressionContext *expressionContext = nullptr;
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  LocationContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    bool array_check = false;
    shared_ptr<SymbolTable> old_top;
    Symbol out;
    Type type_info;
    antlr4::Token *idToken = nullptr;;
    DecafParser::ExpressionContext *expressionContext = nullptr;;
    DecafParser::LocationContext *child = nullptr;;
    DecafParser::LocationContext *locationContext = nullptr;;
    LocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ExpressionContext *expression();
    LocationContext *location();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocationContext* location();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BooleanExprContext : public ExpressionContext {
  public:
    BooleanExprContext(ExpressionContext *ctx);

    DecafParser::OrExprContext *orExprContext = nullptr;
    OrExprContext *orExpr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AritExprContext : public ExpressionContext {
  public:
    AritExprContext(ExpressionContext *ctx);

    DecafParser::AritLowExprContext *aritLowExprContext = nullptr;
    AritLowExprContext *aritLowExpr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParensExprContext : public ExpressionContext {
  public:
    ParensExprContext(ExpressionContext *ctx);

    DecafParser::ExpressionContext *expressionContext = nullptr;
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();

  class  AritLowExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    DecafParser::AritHighExprContext *lexpr = nullptr;;
    DecafParser::AritLowExprContext *rexpr = nullptr;;
    AritLowExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AritHighExprContext *aritHighExpr();
    Arith_low_opContext *arith_low_op();
    AritLowExprContext *aritLowExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AritLowExprContext* aritLowExpr();

  class  AritHighExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    DecafParser::MinusExprContext *lexpr = nullptr;;
    DecafParser::AritHighExprContext *rexpr = nullptr;;
    AritHighExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MinusExprContext *minusExpr();
    Arith_high_opContext *arith_high_op();
    AritHighExprContext *aritHighExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AritHighExprContext* aritHighExpr();

  class  MinusExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    bool check_type = false;
    DecafParser::AtomExprContext *atomExprContext = nullptr;;
    MinusExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomExprContext *atomExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MinusExprContext* minusExpr();

  class  OrExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    DecafParser::AndExprContext *lexpr = nullptr;;
    DecafParser::OrExprContext *rexpr = nullptr;;
    OrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AndExprContext *andExpr();
    Or_opContext *or_op();
    OrExprContext *orExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrExprContext* orExpr();

  class  AndExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    DecafParser::EqExprContext *lexpr = nullptr;;
    DecafParser::AndExprContext *rexpr = nullptr;;
    AndExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqExprContext *eqExpr();
    And_opContext *and_op();
    AndExprContext *andExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndExprContext* andExpr();

  class  EqExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    DecafParser::RelExprContext *lexpr = nullptr;;
    DecafParser::Eq_opContext *op = nullptr;;
    DecafParser::EqExprContext *rexpr = nullptr;;
    EqExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelExprContext *relExpr();
    Eq_opContext *eq_op();
    EqExprContext *eqExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqExprContext* eqExpr();

  class  RelExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    DecafParser::NotExprContext *lexpr = nullptr;;
    DecafParser::RelExprContext *rexpr = nullptr;;
    RelExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NotExprContext *notExpr();
    Rel_opContext *rel_op();
    RelExprContext *relExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelExprContext* relExpr();

  class  NotExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    bool check_type = false;
    DecafParser::AtomExprContext *atomExprContext = nullptr;;
    NotExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomExprContext *atomExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotExprContext* notExpr();

  class  AtomExprContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    vector<int> false_list;
    vector<int> true_list;
    AtomExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomExprContext() = default;
    void copyFrom(AtomExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MethodCallExprContext : public AtomExprContext {
  public:
    MethodCallExprContext(AtomExprContext *ctx);

    DecafParser::MethodCallContext *methodCallContext = nullptr;
    MethodCallContext *methodCall();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LocationExprContext : public AtomExprContext {
  public:
    LocationExprContext(AtomExprContext *ctx);

    DecafParser::LocationContext *locationContext = nullptr;
    LocationContext *location();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralExprContext : public AtomExprContext {
  public:
    LiteralExprContext(AtomExprContext *ctx);

    DecafParser::LiteralContext *literalContext = nullptr;
    LiteralContext *literal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomExprContext* atomExpr();

  class  MethodCallContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    int line;
    int pos;
    shared_ptr<Address> addr;
    vector<string> arg_types;
    Method out;
    antlr4::Token *idToken = nullptr;;
    MethodCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<ArgContext *> arg();
    ArgContext* arg(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodCallContext* methodCall();

  class  ArgContext : public antlr4::ParserRuleContext {
  public:
    vector<string> * method_arg_types;
    DecafParser::ExpressionContext *expressionContext = nullptr;;
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState, vector<string> * method_arg_types);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgContext* arg(vector<string> * method_arg_types);

  class  Arith_high_opContext : public antlr4::ParserRuleContext {
  public:
    Operator op;
    Arith_high_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arith_high_opContext* arith_high_op();

  class  Arith_low_opContext : public antlr4::ParserRuleContext {
  public:
    Operator op;
    Arith_low_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arith_low_opContext* arith_low_op();

  class  Rel_opContext : public antlr4::ParserRuleContext {
  public:
    Operator op;
    Rel_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rel_opContext* rel_op();

  class  Eq_opContext : public antlr4::ParserRuleContext {
  public:
    Operator op;
    Eq_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Eq_opContext* eq_op();

  class  And_opContext : public antlr4::ParserRuleContext {
  public:
    And_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  And_opContext* and_op();

  class  Or_opContext : public antlr4::ParserRuleContext {
  public:
    Or_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Or_opContext* or_op();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    string d_type;
    shared_ptr<Address> addr;
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LiteralContext() = default;
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IntLiteralContext : public LiteralContext {
  public:
    IntLiteralContext(LiteralContext *ctx);

    Int_literalContext *int_literal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharLiteralContext : public LiteralContext {
  public:
    CharLiteralContext(LiteralContext *ctx);

    Char_literalContext *char_literal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolLiteralContext : public LiteralContext {
  public:
    BoolLiteralContext(LiteralContext *ctx);

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


  shared_ptr<SymbolTable> table_head = make_shared<SymbolTable>(Method("__global__", ""));
  shared_ptr<SymbolTable> table_top;
  ErrorHandler *e_handler;
  int scope_counter = 0;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace decafcore
