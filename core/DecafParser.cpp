
// Generated from Decaf.g4 by ANTLR 4.7.1


#include "DecafListener.h"
#include "DecafVisitor.h"

#include "DecafParser.h"


#include "../structs/symb_table.h"
#include "../structs/error_item.h"


using namespace antlrcpp;
using namespace decafcore;
using namespace antlr4;

DecafParser::DecafParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

DecafParser::~DecafParser() {
  delete _interpreter;
}

std::string DecafParser::getGrammarFileName() const {
  return "Decaf.g4";
}

const std::vector<std::string>& DecafParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& DecafParser::getVocabulary() const {
  return _vocabulary;
}


SymbolTable DecafParser::symbol_table() {
  return table_head->flatten();
}

void DecafParser::set_error_handler(ErrorHandler *handler){
  e_handler = handler;
}


//----------------- ProgramContext ------------------------------------------------------------------

DecafParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DecafParser::DeclarationContext *> DecafParser::ProgramContext::declaration() {
  return getRuleContexts<DecafParser::DeclarationContext>();
}

DecafParser::DeclarationContext* DecafParser::ProgramContext::declaration(size_t i) {
  return getRuleContext<DecafParser::DeclarationContext>(i);
}


size_t DecafParser::ProgramContext::getRuleIndex() const {
  return DecafParser::RuleProgram;
}

void DecafParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void DecafParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any DecafParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::ProgramContext* DecafParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, DecafParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
     table_head->init_basic_types(); 
    setState(53);
    match(DecafParser::T__0);
    setState(54);
    match(DecafParser::T__1);
    setState(55);
    match(DecafParser::T__2);
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(56);
      declaration(table_head);
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
    match(DecafParser::T__3);
   _ctx->stop = _input->LT(-1);

    if(!get_where<Method>(table_head->methods(), [](Method& m){return m.name() == "main" && m.param_signature().size() == 0;})){
      e_handler->get_lambda(NO_MAIN, 0, 0)();
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

DecafParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
}

DecafParser::StructDeclarationContext* DecafParser::DeclarationContext::structDeclaration() {
  return getRuleContext<DecafParser::StructDeclarationContext>(0);
}

DecafParser::VarDeclarationContext* DecafParser::DeclarationContext::varDeclaration() {
  return getRuleContext<DecafParser::VarDeclarationContext>(0);
}

DecafParser::MethodDeclarationContext* DecafParser::DeclarationContext::methodDeclaration() {
  return getRuleContext<DecafParser::MethodDeclarationContext>(0);
}


size_t DecafParser::DeclarationContext::getRuleIndex() const {
  return DecafParser::RuleDeclaration;
}

void DecafParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void DecafParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any DecafParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::DeclarationContext* DecafParser::declaration(shared_ptr<SymbolTable> table) {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState(), table);
  enterRule(_localctx, 2, DecafParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(67);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      structDeclaration(_localctx->table);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(65);
      varDeclaration(_localctx->table, nullptr);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(66);
      methodDeclaration(_localctx->table);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

DecafParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table, int * struct_size)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
  this->struct_size = struct_size;
}

DecafParser::VarTypeContext* DecafParser::VarDeclarationContext::varType() {
  return getRuleContext<DecafParser::VarTypeContext>(0);
}

tree::TerminalNode* DecafParser::VarDeclarationContext::ID() {
  return getToken(DecafParser::ID, 0);
}

tree::TerminalNode* DecafParser::VarDeclarationContext::NUM() {
  return getToken(DecafParser::NUM, 0);
}


size_t DecafParser::VarDeclarationContext::getRuleIndex() const {
  return DecafParser::RuleVarDeclaration;
}

void DecafParser::VarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclaration(this);
}

void DecafParser::VarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclaration(this);
}


antlrcpp::Any DecafParser::VarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitVarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::VarDeclarationContext* DecafParser::varDeclaration(shared_ptr<SymbolTable> table,int * struct_size) {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState(), table, struct_size);
  enterRule(_localctx, 4, DecafParser::RuleVarDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(82);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(69);
      dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext = varType(_localctx->table);
      setState(70);
      dynamic_cast<VarDeclarationContext *>(_localctx)->idToken = match(DecafParser::ID);
      setState(71);
      match(DecafParser::T__4);
      dynamic_cast<VarDeclarationContext *>(_localctx)->name =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getText() : ""); dynamic_cast<VarDeclarationContext *>(_localctx)->d_type =  dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext->d_type; dynamic_cast<VarDeclarationContext *>(_localctx)->size =  dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext->size; dynamic_cast<VarDeclarationContext *>(_localctx)->line =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getLine() : 0); dynamic_cast<VarDeclarationContext *>(_localctx)->pos =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getCharPositionInLine() : 0);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(74);
      dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext = varType(_localctx->table);
      setState(75);
      dynamic_cast<VarDeclarationContext *>(_localctx)->idToken = match(DecafParser::ID);
      setState(76);
      match(DecafParser::T__5);
      setState(77);
      dynamic_cast<VarDeclarationContext *>(_localctx)->numToken = match(DecafParser::NUM);
      setState(78);
      match(DecafParser::T__6);
      setState(79);
      match(DecafParser::T__4);

      dynamic_cast<VarDeclarationContext *>(_localctx)->name =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getText() : ""); dynamic_cast<VarDeclarationContext *>(_localctx)->d_type =  dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext->d_type; dynamic_cast<VarDeclarationContext *>(_localctx)->size =  dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext->size * stoi((dynamic_cast<VarDeclarationContext *>(_localctx)->numToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->numToken->getText() : "")); dynamic_cast<VarDeclarationContext *>(_localctx)->line =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getLine() : 0); dynamic_cast<VarDeclarationContext *>(_localctx)->pos =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getCharPositionInLine() : 0);
      if(stoi((dynamic_cast<VarDeclarationContext *>(_localctx)->numToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->numToken->getText() : "")) <= 0){
        e_handler->get_lambda(WRONG_NUM_ARRAY, (dynamic_cast<VarDeclarationContext *>(_localctx)->numToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->numToken->getLine() : 0), (dynamic_cast<VarDeclarationContext *>(_localctx)->numToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->numToken->getCharPositionInLine() : 0))();
      }
          
      break;
    }

    }
   _ctx->stop = _input->LT(-1);

    if(_localctx->struct_size != nullptr){
      *struct_size += _localctx->size;
      table->add_type(_localctx->name, _localctx->d_type, _localctx->table->id(), _localctx->size, e_handler->get_lambda(IDENT_DEFINED, _localctx->line, _localctx->pos, vector<string>{_localctx->name, _localctx->table->id()}));
    } else {
      table->add_symbol(_localctx->name, _localctx->d_type, _localctx->table->id(), _localctx->size, e_handler->get_lambda(IDENT_DEFINED, _localctx->line, _localctx->pos, vector<string>{_localctx->name, _localctx->table->id()}));
    }
      
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

DecafParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
}

tree::TerminalNode* DecafParser::StructDeclarationContext::ID() {
  return getToken(DecafParser::ID, 0);
}

std::vector<DecafParser::VarDeclarationContext *> DecafParser::StructDeclarationContext::varDeclaration() {
  return getRuleContexts<DecafParser::VarDeclarationContext>();
}

DecafParser::VarDeclarationContext* DecafParser::StructDeclarationContext::varDeclaration(size_t i) {
  return getRuleContext<DecafParser::VarDeclarationContext>(i);
}


size_t DecafParser::StructDeclarationContext::getRuleIndex() const {
  return DecafParser::RuleStructDeclaration;
}

void DecafParser::StructDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaration(this);
}

void DecafParser::StructDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaration(this);
}


antlrcpp::Any DecafParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::StructDeclarationContext* DecafParser::structDeclaration(shared_ptr<SymbolTable> table) {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState(), table);
  enterRule(_localctx, 6, DecafParser::RuleStructDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(DecafParser::T__7);
    setState(85);
    dynamic_cast<StructDeclarationContext *>(_localctx)->idToken = match(DecafParser::ID);

    dynamic_cast<StructDeclarationContext *>(_localctx)->new_table =  make_shared<SymbolTable>((dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getText() : ""), _localctx->table);
      
    setState(87);
    match(DecafParser::T__2);
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(88);
      varDeclaration(_localctx->new_table, &_localctx->l_size);
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(94);
    match(DecafParser::T__3);

    table->add_type((dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getText() : ""), "struct", _localctx->table->id(), _localctx->l_size, e_handler->get_lambda(IDENT_DEFINED, (dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{(dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getText() : ""), _localctx->table->id()}));
    table->add_child(_localctx->new_table);
    dynamic_cast<StructDeclarationContext *>(_localctx)->d_type =  (dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getText() : "");
        
   _ctx->stop = _input->LT(-1);

        dynamic_cast<StructDeclarationContext *>(_localctx)->size =  _localctx->l_size;
      
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext ------------------------------------------------------------------

DecafParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
}

tree::TerminalNode* DecafParser::VarTypeContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::StructDeclarationContext* DecafParser::VarTypeContext::structDeclaration() {
  return getRuleContext<DecafParser::StructDeclarationContext>(0);
}


size_t DecafParser::VarTypeContext::getRuleIndex() const {
  return DecafParser::RuleVarType;
}

void DecafParser::VarTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarType(this);
}

void DecafParser::VarTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarType(this);
}


antlrcpp::Any DecafParser::VarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::VarTypeContext* DecafParser::varType(shared_ptr<SymbolTable> table) {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState(), table);
  enterRule(_localctx, 8, DecafParser::RuleVarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      match(DecafParser::T__8);
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  "int"; dynamic_cast<VarTypeContext *>(_localctx)->size =  4;
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(99);
      match(DecafParser::T__9);
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  "char"; dynamic_cast<VarTypeContext *>(_localctx)->size =  1;
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(101);
      match(DecafParser::T__10);
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  "boolean"; dynamic_cast<VarTypeContext *>(_localctx)->size =  1;
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(103);
      match(DecafParser::T__7);
      setState(104);
      dynamic_cast<VarTypeContext *>(_localctx)->idToken = match(DecafParser::ID);

      auto struct_name = (dynamic_cast<VarTypeContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarTypeContext *>(_localctx)->idToken->getText() : "");
      Type type_ctr;
      if(get_where<Type>(table->types(), [struct_name](Type& t){ return t.name() == struct_name && t.type() == "struct";}, &type_ctr)){
        dynamic_cast<VarTypeContext *>(_localctx)->d_type =  type_ctr.name(); dynamic_cast<VarTypeContext *>(_localctx)->size =  type_ctr.size();
      } else {
        // add_sem_error((dynamic_cast<VarTypeContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarTypeContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<VarTypeContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarTypeContext *>(_localctx)->idToken->getCharPositionInLine() : 0), "Struct " + (dynamic_cast<VarTypeContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarTypeContext *>(_localctx)->idToken->getText() : "") + " is undefined!");
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(106);
      dynamic_cast<VarTypeContext *>(_localctx)->structDeclarationContext = structDeclaration(_localctx->table);
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  dynamic_cast<VarTypeContext *>(_localctx)->structDeclarationContext->d_type; dynamic_cast<VarTypeContext *>(_localctx)->size =  dynamic_cast<VarTypeContext *>(_localctx)->structDeclarationContext->size;
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(109);
      match(DecafParser::T__11);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclarationContext ------------------------------------------------------------------

DecafParser::MethodDeclarationContext::MethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::MethodDeclarationContext::MethodDeclarationContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
}

DecafParser::MethodTypeContext* DecafParser::MethodDeclarationContext::methodType() {
  return getRuleContext<DecafParser::MethodTypeContext>(0);
}

tree::TerminalNode* DecafParser::MethodDeclarationContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::BlockContext* DecafParser::MethodDeclarationContext::block() {
  return getRuleContext<DecafParser::BlockContext>(0);
}

std::vector<DecafParser::ParameterContext *> DecafParser::MethodDeclarationContext::parameter() {
  return getRuleContexts<DecafParser::ParameterContext>();
}

DecafParser::ParameterContext* DecafParser::MethodDeclarationContext::parameter(size_t i) {
  return getRuleContext<DecafParser::ParameterContext>(i);
}


size_t DecafParser::MethodDeclarationContext::getRuleIndex() const {
  return DecafParser::RuleMethodDeclaration;
}

void DecafParser::MethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDeclaration(this);
}

void DecafParser::MethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDeclaration(this);
}


antlrcpp::Any DecafParser::MethodDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodDeclaration(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::MethodDeclarationContext* DecafParser::methodDeclaration(shared_ptr<SymbolTable> table) {
  MethodDeclarationContext *_localctx = _tracker.createInstance<MethodDeclarationContext>(_ctx, getState(), table);
  enterRule(_localctx, 10, DecafParser::RuleMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    dynamic_cast<MethodDeclarationContext *>(_localctx)->methodTypeContext = methodType();
    setState(113);
    dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken = match(DecafParser::ID);
    dynamic_cast<MethodDeclarationContext *>(_localctx)->new_table =  make_shared<SymbolTable>((dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : ""), _localctx->table);
    setState(115);
    match(DecafParser::T__12);
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10))) != 0)) {
      setState(116);
      parameter(&_localctx->params);
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DecafParser::T__13) {
        setState(117);
        match(DecafParser::T__13);
        setState(118);
        parameter(&_localctx->params);
        setState(123);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(126);
    match(DecafParser::T__14);
    setState(127);
    block(_localctx->new_table, (dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : ""));

    table->add_method((dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : ""), dynamic_cast<MethodDeclarationContext *>(_localctx)->methodTypeContext->d_type, _localctx->table->id(), _localctx->params, e_handler->get_lambda(IDENT_DEFINED, (dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{(dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : ""), _localctx->table->id()}));
    table->add_child(_localctx->new_table);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodTypeContext ------------------------------------------------------------------

DecafParser::MethodTypeContext::MethodTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::MethodTypeContext::getRuleIndex() const {
  return DecafParser::RuleMethodType;
}

void DecafParser::MethodTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodType(this);
}

void DecafParser::MethodTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodType(this);
}


antlrcpp::Any DecafParser::MethodTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodType(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::MethodTypeContext* DecafParser::methodType() {
  MethodTypeContext *_localctx = _tracker.createInstance<MethodTypeContext>(_ctx, getState());
  enterRule(_localctx, 12, DecafParser::RuleMethodType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(130);
        match(DecafParser::T__8);
        dynamic_cast<MethodTypeContext *>(_localctx)->d_type =  "int";
        break;
      }

      case DecafParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(132);
        match(DecafParser::T__9);
        dynamic_cast<MethodTypeContext *>(_localctx)->d_type =  "char";
        break;
      }

      case DecafParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(134);
        match(DecafParser::T__10);
        dynamic_cast<MethodTypeContext *>(_localctx)->d_type =  "boolean";
        break;
      }

      case DecafParser::T__11: {
        enterOuterAlt(_localctx, 4);
        setState(136);
        match(DecafParser::T__11);
        dynamic_cast<MethodTypeContext *>(_localctx)->d_type =  "void";
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

DecafParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState, vector<string> * meth_params)
  : ParserRuleContext(parent, invokingState) {
  this->meth_params = meth_params;
}

DecafParser::ParameterTypeContext* DecafParser::ParameterContext::parameterType() {
  return getRuleContext<DecafParser::ParameterTypeContext>(0);
}

tree::TerminalNode* DecafParser::ParameterContext::ID() {
  return getToken(DecafParser::ID, 0);
}


size_t DecafParser::ParameterContext::getRuleIndex() const {
  return DecafParser::RuleParameter;
}

void DecafParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void DecafParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


antlrcpp::Any DecafParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::ParameterContext* DecafParser::parameter(vector<string> * meth_params) {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState(), meth_params);
  enterRule(_localctx, 14, DecafParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      dynamic_cast<ParameterContext *>(_localctx)->parameterTypeContext = parameterType();
      setState(141);
      match(DecafParser::ID);
      meth_params->push_back(dynamic_cast<ParameterContext *>(_localctx)->parameterTypeContext->d_type);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(144);
      parameterType();
      setState(145);
      match(DecafParser::ID);
      setState(146);
      match(DecafParser::T__5);
      setState(147);
      match(DecafParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterTypeContext ------------------------------------------------------------------

DecafParser::ParameterTypeContext::ParameterTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::ParameterTypeContext::getRuleIndex() const {
  return DecafParser::RuleParameterType;
}

void DecafParser::ParameterTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterType(this);
}

void DecafParser::ParameterTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterType(this);
}


antlrcpp::Any DecafParser::ParameterTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitParameterType(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::ParameterTypeContext* DecafParser::parameterType() {
  ParameterTypeContext *_localctx = _tracker.createInstance<ParameterTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, DecafParser::RuleParameterType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(151);
        match(DecafParser::T__8);
        dynamic_cast<ParameterTypeContext *>(_localctx)->d_type =  "int";
        break;
      }

      case DecafParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(153);
        match(DecafParser::T__9);
        dynamic_cast<ParameterTypeContext *>(_localctx)->d_type =  "char";
        break;
      }

      case DecafParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(155);
        match(DecafParser::T__10);
        dynamic_cast<ParameterTypeContext *>(_localctx)->d_type =  "boolean";
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

DecafParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table, string method_name)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
  this->method_name = method_name;
}

std::vector<DecafParser::VarDeclarationContext *> DecafParser::BlockContext::varDeclaration() {
  return getRuleContexts<DecafParser::VarDeclarationContext>();
}

DecafParser::VarDeclarationContext* DecafParser::BlockContext::varDeclaration(size_t i) {
  return getRuleContext<DecafParser::VarDeclarationContext>(i);
}

std::vector<DecafParser::StatementContext *> DecafParser::BlockContext::statement() {
  return getRuleContexts<DecafParser::StatementContext>();
}

DecafParser::StatementContext* DecafParser::BlockContext::statement(size_t i) {
  return getRuleContext<DecafParser::StatementContext>(i);
}


size_t DecafParser::BlockContext::getRuleIndex() const {
  return DecafParser::RuleBlock;
}

void DecafParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void DecafParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any DecafParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::BlockContext* DecafParser::block(shared_ptr<SymbolTable> table,string method_name) {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState(), table, method_name);
  enterRule(_localctx, 18, DecafParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

    if(method_name == ""){
      dynamic_cast<BlockContext *>(_localctx)->new_table =  make_shared<SymbolTable>(_localctx->table->id() + "_" + to_string(scope_counter), _localctx->table);
      scope_counter++;
      table->add_method(_localctx->new_table->id(), "void", _localctx->table->id(), vector<string>{});
      table->add_child(_localctx->new_table);
    } else {
      dynamic_cast<BlockContext *>(_localctx)->new_table =  _localctx->table;
    }
      
    setState(160);
    match(DecafParser::T__2);
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(161);
      varDeclaration(_localctx->new_table, nullptr);
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__2)
      | (1ULL << DecafParser::T__4)
      | (1ULL << DecafParser::T__12)
      | (1ULL << DecafParser::T__15)
      | (1ULL << DecafParser::T__17)
      | (1ULL << DecafParser::T__18)
      | (1ULL << DecafParser::T__21)
      | (1ULL << DecafParser::T__22)
      | (1ULL << DecafParser::T__35)
      | (1ULL << DecafParser::T__36)
      | (1ULL << DecafParser::ID)
      | (1ULL << DecafParser::NUM)
      | (1ULL << DecafParser::CHAR))) != 0)) {
      setState(167);
      statement(_localctx->new_table);
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(173);
    match(DecafParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

DecafParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
}

DecafParser::ExpressionContext* DecafParser::StatementContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

std::vector<DecafParser::BlockContext *> DecafParser::StatementContext::block() {
  return getRuleContexts<DecafParser::BlockContext>();
}

DecafParser::BlockContext* DecafParser::StatementContext::block(size_t i) {
  return getRuleContext<DecafParser::BlockContext>(i);
}

DecafParser::MethodCallContext* DecafParser::StatementContext::methodCall() {
  return getRuleContext<DecafParser::MethodCallContext>(0);
}

DecafParser::LocationContext* DecafParser::StatementContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}


size_t DecafParser::StatementContext::getRuleIndex() const {
  return DecafParser::RuleStatement;
}

void DecafParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void DecafParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any DecafParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::StatementContext* DecafParser::statement(shared_ptr<SymbolTable> table) {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState(), table);
  enterRule(_localctx, 20, DecafParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(175);
      match(DecafParser::T__15);
      setState(176);
      match(DecafParser::T__12);
      setState(177);
      expression(0);
      setState(178);
      match(DecafParser::T__14);
      setState(179);
      block(_localctx->table, "");
      setState(182);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::T__16) {
        setState(180);
        match(DecafParser::T__16);
        setState(181);
        block(_localctx->table, "");
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(184);
      match(DecafParser::T__17);
      setState(185);
      match(DecafParser::T__12);
      setState(186);
      expression(0);
      setState(187);
      match(DecafParser::T__14);
      setState(188);
      block(_localctx->table, "");
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(190);
      match(DecafParser::T__18);
      setState(192);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__12)
        | (1ULL << DecafParser::T__21)
        | (1ULL << DecafParser::T__22)
        | (1ULL << DecafParser::T__35)
        | (1ULL << DecafParser::T__36)
        | (1ULL << DecafParser::NUM)
        | (1ULL << DecafParser::CHAR))) != 0)) {
        setState(191);
        expression(0);
      }
      setState(194);
      match(DecafParser::T__4);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(195);
      methodCall(_localctx->table);
      setState(196);
      match(DecafParser::T__4);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(198);
      block(_localctx->table, "");
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(199);
      location(_localctx->table);
      setState(200);
      match(DecafParser::T__19);
      setState(201);
      expression(0);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(204);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__12)
        | (1ULL << DecafParser::T__21)
        | (1ULL << DecafParser::T__22)
        | (1ULL << DecafParser::T__35)
        | (1ULL << DecafParser::T__36)
        | (1ULL << DecafParser::NUM)
        | (1ULL << DecafParser::CHAR))) != 0)) {
        setState(203);
        expression(0);
      }
      setState(206);
      match(DecafParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocationContext ------------------------------------------------------------------

DecafParser::LocationContext::LocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::LocationContext::LocationContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
}

tree::TerminalNode* DecafParser::LocationContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::ExpressionContext* DecafParser::LocationContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::LocationContext* DecafParser::LocationContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}


size_t DecafParser::LocationContext::getRuleIndex() const {
  return DecafParser::RuleLocation;
}

void DecafParser::LocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocation(this);
}

void DecafParser::LocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocation(this);
}


antlrcpp::Any DecafParser::LocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLocation(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::LocationContext* DecafParser::location(shared_ptr<SymbolTable> table) {
  LocationContext *_localctx = _tracker.createInstance<LocationContext>(_ctx, getState(), table);
  enterRule(_localctx, 22, DecafParser::RuleLocation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(209);
      dynamic_cast<LocationContext *>(_localctx)->idToken = match(DecafParser::ID);
      break;
    }

    case 2: {
      setState(210);
      dynamic_cast<LocationContext *>(_localctx)->idToken = match(DecafParser::ID);
      setState(211);
      match(DecafParser::T__5);
      setState(212);
      expression(0);
      setState(213);
      match(DecafParser::T__6);
      break;
    }

    }

    Symbol out;
    if(recursive_lookup<Symbol>(_localctx->table, [&](shared_ptr<SymbolTable> t){return t->symbols();}, [&](Symbol &s){return s.name() == (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getText() : "");}, &out)){
      dynamic_cast<LocationContext *>(_localctx)->d_type =  out.type();
    } else {
      e_handler->get_lambda(IDENT_NOT_DEFINED, (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{(dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getText() : "")})();
    }
      
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DecafParser::T__20) {
      setState(218);
      match(DecafParser::T__20);
      setState(219);
      location(_localctx->table);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

DecafParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DecafParser::ExpressionContext *> DecafParser::ExpressionContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::LiteralContext* DecafParser::ExpressionContext::literal() {
  return getRuleContext<DecafParser::LiteralContext>(0);
}

DecafParser::Arith_high_precedenceContext* DecafParser::ExpressionContext::arith_high_precedence() {
  return getRuleContext<DecafParser::Arith_high_precedenceContext>(0);
}

DecafParser::Arith_low_precedenceContext* DecafParser::ExpressionContext::arith_low_precedence() {
  return getRuleContext<DecafParser::Arith_low_precedenceContext>(0);
}

DecafParser::Rel_opContext* DecafParser::ExpressionContext::rel_op() {
  return getRuleContext<DecafParser::Rel_opContext>(0);
}

DecafParser::Eq_opContext* DecafParser::ExpressionContext::eq_op() {
  return getRuleContext<DecafParser::Eq_opContext>(0);
}

DecafParser::Cond_andContext* DecafParser::ExpressionContext::cond_and() {
  return getRuleContext<DecafParser::Cond_andContext>(0);
}

DecafParser::Cond_orContext* DecafParser::ExpressionContext::cond_or() {
  return getRuleContext<DecafParser::Cond_orContext>(0);
}


size_t DecafParser::ExpressionContext::getRuleIndex() const {
  return DecafParser::RuleExpression;
}

void DecafParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void DecafParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any DecafParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


DecafParser::ExpressionContext* DecafParser::expression() {
   return expression(0);
}

DecafParser::ExpressionContext* DecafParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  DecafParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  DecafParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, DecafParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(234);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__12: {
        setState(223);
        match(DecafParser::T__12);
        setState(224);
        expression(0);
        setState(225);
        match(DecafParser::T__14);
        break;
      }

      case DecafParser::T__21: {
        setState(227);
        match(DecafParser::T__21);
        setState(228);
        expression(9);
        break;
      }

      case DecafParser::T__22: {
        setState(229);
        match(DecafParser::T__22);
        setState(230);
        expression(8);
        break;
      }

      case DecafParser::T__35:
      case DecafParser::T__36:
      case DecafParser::NUM:
      case DecafParser::CHAR: {
        setState(231);
        dynamic_cast<ExpressionContext *>(_localctx)->literalContext = literal();
        dynamic_cast<ExpressionContext *>(_localctx)->d_type =  dynamic_cast<ExpressionContext *>(_localctx)->literalContext->d_type;
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(262);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(260);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(236);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(237);
          arith_high_precedence();
          setState(238);
          expression(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(240);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(241);
          arith_low_precedence();
          setState(242);
          expression(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(244);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(245);
          rel_op();
          setState(246);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(248);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(249);
          eq_op();
          setState(250);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(252);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(253);
          cond_and();
          setState(254);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(256);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(257);
          cond_or();
          setState(258);
          expression(3);
          break;
        }

        } 
      }
      setState(264);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MethodCallContext ------------------------------------------------------------------

DecafParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState, shared_ptr<SymbolTable> table)
  : ParserRuleContext(parent, invokingState) {
  this->table = table;
}

tree::TerminalNode* DecafParser::MethodCallContext::ID() {
  return getToken(DecafParser::ID, 0);
}

std::vector<DecafParser::ArgContext *> DecafParser::MethodCallContext::arg() {
  return getRuleContexts<DecafParser::ArgContext>();
}

DecafParser::ArgContext* DecafParser::MethodCallContext::arg(size_t i) {
  return getRuleContext<DecafParser::ArgContext>(i);
}


size_t DecafParser::MethodCallContext::getRuleIndex() const {
  return DecafParser::RuleMethodCall;
}

void DecafParser::MethodCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCall(this);
}

void DecafParser::MethodCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCall(this);
}


antlrcpp::Any DecafParser::MethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodCall(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::MethodCallContext* DecafParser::methodCall(shared_ptr<SymbolTable> table) {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState(), table);
  enterRule(_localctx, 26, DecafParser::RuleMethodCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(DecafParser::ID);
    setState(266);
    match(DecafParser::T__12);
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__12)
      | (1ULL << DecafParser::T__21)
      | (1ULL << DecafParser::T__22)
      | (1ULL << DecafParser::T__35)
      | (1ULL << DecafParser::T__36)
      | (1ULL << DecafParser::NUM)
      | (1ULL << DecafParser::CHAR))) != 0)) {
      setState(267);
      arg(&_localctx->arg_types, _localctx->table);
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DecafParser::T__13) {
        setState(268);
        match(DecafParser::T__13);
        setState(269);
        arg(&_localctx->arg_types, _localctx->table);
        setState(274);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(277);
    match(DecafParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

DecafParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState, vector<string> * method_arg_types, shared_ptr<SymbolTable> table)
  : ParserRuleContext(parent, invokingState) {
  this->method_arg_types = method_arg_types;
  this->table = table;
}

DecafParser::ExpressionContext* DecafParser::ArgContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}


size_t DecafParser::ArgContext::getRuleIndex() const {
  return DecafParser::RuleArg;
}

void DecafParser::ArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg(this);
}

void DecafParser::ArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg(this);
}


antlrcpp::Any DecafParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::ArgContext* DecafParser::arg(vector<string> * method_arg_types,shared_ptr<SymbolTable> table) {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState(), method_arg_types, table);
  enterRule(_localctx, 28, DecafParser::RuleArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    dynamic_cast<ArgContext *>(_localctx)->expressionContext = expression(0);
    method_arg_types->push_back(dynamic_cast<ArgContext *>(_localctx)->expressionContext->d_type);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arith_opContext ------------------------------------------------------------------

DecafParser::Arith_opContext::Arith_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::Arith_high_precedenceContext* DecafParser::Arith_opContext::arith_high_precedence() {
  return getRuleContext<DecafParser::Arith_high_precedenceContext>(0);
}

DecafParser::Arith_low_precedenceContext* DecafParser::Arith_opContext::arith_low_precedence() {
  return getRuleContext<DecafParser::Arith_low_precedenceContext>(0);
}


size_t DecafParser::Arith_opContext::getRuleIndex() const {
  return DecafParser::RuleArith_op;
}

void DecafParser::Arith_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_op(this);
}

void DecafParser::Arith_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_op(this);
}


antlrcpp::Any DecafParser::Arith_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitArith_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Arith_opContext* DecafParser::arith_op() {
  Arith_opContext *_localctx = _tracker.createInstance<Arith_opContext>(_ctx, getState());
  enterRule(_localctx, 30, DecafParser::RuleArith_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__23:
      case DecafParser::T__24:
      case DecafParser::T__25: {
        enterOuterAlt(_localctx, 1);
        setState(282);
        arith_high_precedence();
        break;
      }

      case DecafParser::T__22:
      case DecafParser::T__26: {
        enterOuterAlt(_localctx, 2);
        setState(283);
        arith_low_precedence();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arith_high_precedenceContext ------------------------------------------------------------------

DecafParser::Arith_high_precedenceContext::Arith_high_precedenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Arith_high_precedenceContext::getRuleIndex() const {
  return DecafParser::RuleArith_high_precedence;
}

void DecafParser::Arith_high_precedenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_high_precedence(this);
}

void DecafParser::Arith_high_precedenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_high_precedence(this);
}


antlrcpp::Any DecafParser::Arith_high_precedenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitArith_high_precedence(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Arith_high_precedenceContext* DecafParser::arith_high_precedence() {
  Arith_high_precedenceContext *_localctx = _tracker.createInstance<Arith_high_precedenceContext>(_ctx, getState());
  enterRule(_localctx, 32, DecafParser::RuleArith_high_precedence);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__23)
      | (1ULL << DecafParser::T__24)
      | (1ULL << DecafParser::T__25))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arith_low_precedenceContext ------------------------------------------------------------------

DecafParser::Arith_low_precedenceContext::Arith_low_precedenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Arith_low_precedenceContext::getRuleIndex() const {
  return DecafParser::RuleArith_low_precedence;
}

void DecafParser::Arith_low_precedenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_low_precedence(this);
}

void DecafParser::Arith_low_precedenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_low_precedence(this);
}


antlrcpp::Any DecafParser::Arith_low_precedenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitArith_low_precedence(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Arith_low_precedenceContext* DecafParser::arith_low_precedence() {
  Arith_low_precedenceContext *_localctx = _tracker.createInstance<Arith_low_precedenceContext>(_ctx, getState());
  enterRule(_localctx, 34, DecafParser::RuleArith_low_precedence);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    _la = _input->LA(1);
    if (!(_la == DecafParser::T__22

    || _la == DecafParser::T__26)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_opContext ------------------------------------------------------------------

DecafParser::Rel_opContext::Rel_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Rel_opContext::getRuleIndex() const {
  return DecafParser::RuleRel_op;
}

void DecafParser::Rel_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_op(this);
}

void DecafParser::Rel_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_op(this);
}


antlrcpp::Any DecafParser::Rel_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitRel_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Rel_opContext* DecafParser::rel_op() {
  Rel_opContext *_localctx = _tracker.createInstance<Rel_opContext>(_ctx, getState());
  enterRule(_localctx, 36, DecafParser::RuleRel_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__27)
      | (1ULL << DecafParser::T__28)
      | (1ULL << DecafParser::T__29)
      | (1ULL << DecafParser::T__30))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Eq_opContext ------------------------------------------------------------------

DecafParser::Eq_opContext::Eq_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Eq_opContext::getRuleIndex() const {
  return DecafParser::RuleEq_op;
}

void DecafParser::Eq_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEq_op(this);
}

void DecafParser::Eq_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEq_op(this);
}


antlrcpp::Any DecafParser::Eq_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitEq_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Eq_opContext* DecafParser::eq_op() {
  Eq_opContext *_localctx = _tracker.createInstance<Eq_opContext>(_ctx, getState());
  enterRule(_localctx, 38, DecafParser::RuleEq_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    _la = _input->LA(1);
    if (!(_la == DecafParser::T__31

    || _la == DecafParser::T__32)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_andContext ------------------------------------------------------------------

DecafParser::Cond_andContext::Cond_andContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Cond_andContext::getRuleIndex() const {
  return DecafParser::RuleCond_and;
}

void DecafParser::Cond_andContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond_and(this);
}

void DecafParser::Cond_andContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond_and(this);
}


antlrcpp::Any DecafParser::Cond_andContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitCond_and(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Cond_andContext* DecafParser::cond_and() {
  Cond_andContext *_localctx = _tracker.createInstance<Cond_andContext>(_ctx, getState());
  enterRule(_localctx, 40, DecafParser::RuleCond_and);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    match(DecafParser::T__33);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_orContext ------------------------------------------------------------------

DecafParser::Cond_orContext::Cond_orContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Cond_orContext::getRuleIndex() const {
  return DecafParser::RuleCond_or;
}

void DecafParser::Cond_orContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond_or(this);
}

void DecafParser::Cond_orContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond_or(this);
}


antlrcpp::Any DecafParser::Cond_orContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitCond_or(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Cond_orContext* DecafParser::cond_or() {
  Cond_orContext *_localctx = _tracker.createInstance<Cond_orContext>(_ctx, getState());
  enterRule(_localctx, 42, DecafParser::RuleCond_or);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    match(DecafParser::T__34);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

DecafParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::Int_literalContext* DecafParser::LiteralContext::int_literal() {
  return getRuleContext<DecafParser::Int_literalContext>(0);
}

DecafParser::Char_literalContext* DecafParser::LiteralContext::char_literal() {
  return getRuleContext<DecafParser::Char_literalContext>(0);
}

DecafParser::Bool_literalContext* DecafParser::LiteralContext::bool_literal() {
  return getRuleContext<DecafParser::Bool_literalContext>(0);
}


size_t DecafParser::LiteralContext::getRuleIndex() const {
  return DecafParser::RuleLiteral;
}

void DecafParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void DecafParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any DecafParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::LiteralContext* DecafParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 44, DecafParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(307);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(298);
        int_literal();
        dynamic_cast<LiteralContext *>(_localctx)->d_type =  "int";
        break;
      }

      case DecafParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(301);
        char_literal();
        dynamic_cast<LiteralContext *>(_localctx)->d_type =  "char";
        break;
      }

      case DecafParser::T__35:
      case DecafParser::T__36: {
        enterOuterAlt(_localctx, 3);
        setState(304);
        bool_literal();
        dynamic_cast<LiteralContext *>(_localctx)->d_type =  "boolean";
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Int_literalContext ------------------------------------------------------------------

DecafParser::Int_literalContext::Int_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::Int_literalContext::NUM() {
  return getToken(DecafParser::NUM, 0);
}


size_t DecafParser::Int_literalContext::getRuleIndex() const {
  return DecafParser::RuleInt_literal;
}

void DecafParser::Int_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt_literal(this);
}

void DecafParser::Int_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt_literal(this);
}


antlrcpp::Any DecafParser::Int_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitInt_literal(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Int_literalContext* DecafParser::int_literal() {
  Int_literalContext *_localctx = _tracker.createInstance<Int_literalContext>(_ctx, getState());
  enterRule(_localctx, 46, DecafParser::RuleInt_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(DecafParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Char_literalContext ------------------------------------------------------------------

DecafParser::Char_literalContext::Char_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::Char_literalContext::CHAR() {
  return getToken(DecafParser::CHAR, 0);
}


size_t DecafParser::Char_literalContext::getRuleIndex() const {
  return DecafParser::RuleChar_literal;
}

void DecafParser::Char_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChar_literal(this);
}

void DecafParser::Char_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChar_literal(this);
}


antlrcpp::Any DecafParser::Char_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitChar_literal(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Char_literalContext* DecafParser::char_literal() {
  Char_literalContext *_localctx = _tracker.createInstance<Char_literalContext>(_ctx, getState());
  enterRule(_localctx, 48, DecafParser::RuleChar_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    match(DecafParser::CHAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_literalContext ------------------------------------------------------------------

DecafParser::Bool_literalContext::Bool_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Bool_literalContext::getRuleIndex() const {
  return DecafParser::RuleBool_literal;
}

void DecafParser::Bool_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_literal(this);
}

void DecafParser::Bool_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_literal(this);
}


antlrcpp::Any DecafParser::Bool_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitBool_literal(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Bool_literalContext* DecafParser::bool_literal() {
  Bool_literalContext *_localctx = _tracker.createInstance<Bool_literalContext>(_ctx, getState());
  enterRule(_localctx, 50, DecafParser::RuleBool_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    _la = _input->LA(1);
    if (!(_la == DecafParser::T__35

    || _la == DecafParser::T__36)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool DecafParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool DecafParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> DecafParser::_decisionToDFA;
atn::PredictionContextCache DecafParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN DecafParser::_atn;
std::vector<uint16_t> DecafParser::_serializedATN;

std::vector<std::string> DecafParser::_ruleNames = {
  "program", "declaration", "varDeclaration", "structDeclaration", "varType", 
  "methodDeclaration", "methodType", "parameter", "parameterType", "block", 
  "statement", "location", "expression", "methodCall", "arg", "arith_op", 
  "arith_high_precedence", "arith_low_precedence", "rel_op", "eq_op", "cond_and", 
  "cond_or", "literal", "int_literal", "char_literal", "bool_literal"
};

std::vector<std::string> DecafParser::_literalNames = {
  "", "'class'", "'Program'", "'{'", "'}'", "';'", "'['", "']'", "'struct'", 
  "'int'", "'char'", "'boolean'", "'void'", "'('", "','", "')'", "'if'", 
  "'else'", "'while'", "'return'", "'='", "'.'", "'!'", "'-'", "'*'", "'/'", 
  "'%'", "'+'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", 
  "'true'", "'false'"
};

std::vector<std::string> DecafParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "ID", "NUM", "CHAR", "WS"
};

dfa::Vocabulary DecafParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> DecafParser::_tokenNames;

DecafParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0x13e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3c, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x3f, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x46, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x55, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x5c, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x5f, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x71, 0xa, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x7, 0x7, 0x7a, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x7d, 0xb, 0x7, 0x5, 
    0x7, 0x7f, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x8d, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x98, 0xa, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0xa0, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xa5, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xa8, 0xb, 0xb, 0x3, 0xb, 0x7, 0xb, 0xab, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xae, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb9, 
    0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xc3, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0xcf, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0xd2, 0xa, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xda, 
    0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xdf, 0xa, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xed, 0xa, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x107, 0xa, 0xe, 0xc, 0xe, 0xe, 
    0xe, 0x10a, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x7, 0xf, 0x111, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x114, 0xb, 0xf, 0x5, 
    0xf, 0x116, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x11f, 0xa, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x5, 0x18, 0x136, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x2, 0x3, 0x1a, 0x1c, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x2, 0x7, 0x3, 0x2, 0x1a, 0x1c, 0x4, 0x2, 0x19, 0x19, 0x1d, 0x1d, 0x3, 
    0x2, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 0x3, 0x2, 0x26, 0x27, 0x2, 0x150, 
    0x2, 0x36, 0x3, 0x2, 0x2, 0x2, 0x4, 0x45, 0x3, 0x2, 0x2, 0x2, 0x6, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x56, 0x3, 0x2, 0x2, 0x2, 0xa, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x72, 0x3, 0x2, 0x2, 0x2, 0xe, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x97, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0x16, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xec, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x119, 0x3, 0x2, 0x2, 0x2, 0x20, 0x11e, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x120, 0x3, 0x2, 0x2, 0x2, 0x24, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x124, 0x3, 0x2, 0x2, 0x2, 0x28, 0x126, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x135, 0x3, 0x2, 0x2, 0x2, 0x30, 0x137, 0x3, 0x2, 0x2, 0x2, 0x32, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x8, 
    0x2, 0x1, 0x2, 0x37, 0x38, 0x7, 0x3, 0x2, 0x2, 0x38, 0x39, 0x7, 0x4, 
    0x2, 0x2, 0x39, 0x3d, 0x7, 0x5, 0x2, 0x2, 0x3a, 0x3c, 0x5, 0x4, 0x3, 
    0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 
    0x7, 0x6, 0x2, 0x2, 0x41, 0x3, 0x3, 0x2, 0x2, 0x2, 0x42, 0x46, 0x5, 
    0x8, 0x5, 0x2, 0x43, 0x46, 0x5, 0x6, 0x4, 0x2, 0x44, 0x46, 0x5, 0xc, 
    0x7, 0x2, 0x45, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x48, 0x5, 0xa, 0x6, 0x2, 0x48, 0x49, 0x7, 0x28, 0x2, 0x2, 0x49, 
    0x4a, 0x7, 0x7, 0x2, 0x2, 0x4a, 0x4b, 0x8, 0x4, 0x1, 0x2, 0x4b, 0x55, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0xa, 0x6, 0x2, 0x4d, 0x4e, 0x7, 
    0x28, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x8, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x29, 
    0x2, 0x2, 0x50, 0x51, 0x7, 0x9, 0x2, 0x2, 0x51, 0x52, 0x7, 0x7, 0x2, 
    0x2, 0x52, 0x53, 0x8, 0x4, 0x1, 0x2, 0x53, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x47, 0x3, 0x2, 0x2, 0x2, 0x54, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0xa, 0x2, 0x2, 0x57, 0x58, 
    0x7, 0x28, 0x2, 0x2, 0x58, 0x59, 0x8, 0x5, 0x1, 0x2, 0x59, 0x5d, 0x7, 
    0x5, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0x6, 0x4, 0x2, 0x5b, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x6, 0x2, 0x2, 0x61, 
    0x62, 0x8, 0x5, 0x1, 0x2, 0x62, 0x9, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 
    0x7, 0xb, 0x2, 0x2, 0x64, 0x71, 0x8, 0x6, 0x1, 0x2, 0x65, 0x66, 0x7, 
    0xc, 0x2, 0x2, 0x66, 0x71, 0x8, 0x6, 0x1, 0x2, 0x67, 0x68, 0x7, 0xd, 
    0x2, 0x2, 0x68, 0x71, 0x8, 0x6, 0x1, 0x2, 0x69, 0x6a, 0x7, 0xa, 0x2, 
    0x2, 0x6a, 0x6b, 0x7, 0x28, 0x2, 0x2, 0x6b, 0x71, 0x8, 0x6, 0x1, 0x2, 
    0x6c, 0x6d, 0x5, 0x8, 0x5, 0x2, 0x6d, 0x6e, 0x8, 0x6, 0x1, 0x2, 0x6e, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 0x7, 0xe, 0x2, 0x2, 0x70, 0x63, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x65, 0x3, 0x2, 0x2, 0x2, 0x70, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x69, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x73, 0x5, 0xe, 0x8, 0x2, 0x73, 0x74, 0x7, 0x28, 0x2, 0x2, 
    0x74, 0x75, 0x8, 0x7, 0x1, 0x2, 0x75, 0x7e, 0x7, 0xf, 0x2, 0x2, 0x76, 
    0x7b, 0x5, 0x10, 0x9, 0x2, 0x77, 0x78, 0x7, 0x10, 0x2, 0x2, 0x78, 0x7a, 
    0x5, 0x10, 0x9, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x7c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x7e, 0x76, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 0x11, 0x2, 0x2, 0x81, 
    0x82, 0x5, 0x14, 0xb, 0x2, 0x82, 0x83, 0x8, 0x7, 0x1, 0x2, 0x83, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0xb, 0x2, 0x2, 0x85, 0x8d, 0x8, 
    0x8, 0x1, 0x2, 0x86, 0x87, 0x7, 0xc, 0x2, 0x2, 0x87, 0x8d, 0x8, 0x8, 
    0x1, 0x2, 0x88, 0x89, 0x7, 0xd, 0x2, 0x2, 0x89, 0x8d, 0x8, 0x8, 0x1, 
    0x2, 0x8a, 0x8b, 0x7, 0xe, 0x2, 0x2, 0x8b, 0x8d, 0x8, 0x8, 0x1, 0x2, 
    0x8c, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8d, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x12, 0xa, 0x2, 0x8f, 0x90, 0x7, 
    0x28, 0x2, 0x2, 0x90, 0x91, 0x8, 0x9, 0x1, 0x2, 0x91, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x93, 0x5, 0x12, 0xa, 0x2, 0x93, 0x94, 0x7, 0x28, 0x2, 
    0x2, 0x94, 0x95, 0x7, 0x8, 0x2, 0x2, 0x95, 0x96, 0x7, 0x9, 0x2, 0x2, 
    0x96, 0x98, 0x3, 0x2, 0x2, 0x2, 0x97, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x98, 0x11, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 
    0x7, 0xb, 0x2, 0x2, 0x9a, 0xa0, 0x8, 0xa, 0x1, 0x2, 0x9b, 0x9c, 0x7, 
    0xc, 0x2, 0x2, 0x9c, 0xa0, 0x8, 0xa, 0x1, 0x2, 0x9d, 0x9e, 0x7, 0xd, 
    0x2, 0x2, 0x9e, 0xa0, 0x8, 0xa, 0x1, 0x2, 0x9f, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x8, 0xb, 0x1, 0x2, 0xa2, 
    0xa6, 0x7, 0x5, 0x2, 0x2, 0xa3, 0xa5, 0x5, 0x6, 0x4, 0x2, 0xa4, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xab, 0x5, 0x16, 0xc, 
    0x2, 0xaa, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xaf, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 
    0x7, 0x6, 0x2, 0x2, 0xb0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 
    0x12, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0xf, 0x2, 0x2, 0xb3, 0xb4, 0x5, 0x1a, 
    0xe, 0x2, 0xb4, 0xb5, 0x7, 0x11, 0x2, 0x2, 0xb5, 0xb8, 0x5, 0x14, 0xb, 
    0x2, 0xb6, 0xb7, 0x7, 0x13, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x14, 0xb, 0x2, 
    0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x14, 0x2, 0x2, 0xbb, 0xbc, 
    0x7, 0xf, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x1a, 0xe, 0x2, 0xbd, 0xbe, 0x7, 
    0x11, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x14, 0xb, 0x2, 0xbf, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xc2, 0x7, 0x15, 0x2, 0x2, 0xc1, 0xc3, 0x5, 0x1a, 0xe, 
    0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xd2, 0x7, 0x7, 0x2, 0x2, 0xc5, 
    0xc6, 0x5, 0x1c, 0xf, 0x2, 0xc6, 0xc7, 0x7, 0x7, 0x2, 0x2, 0xc7, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0xd2, 0x5, 0x14, 0xb, 0x2, 0xc9, 0xca, 0x5, 
    0x18, 0xd, 0x2, 0xca, 0xcb, 0x7, 0x16, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x1a, 
    0xe, 0x2, 0xcc, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcf, 0x5, 0x1a, 0xe, 
    0x2, 0xce, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd2, 0x7, 0x7, 0x2, 0x2, 0xd1, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xba, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc8, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xda, 0x7, 0x28, 0x2, 
    0x2, 0xd4, 0xd5, 0x7, 0x28, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x8, 0x2, 0x2, 
    0xd6, 0xd7, 0x5, 0x1a, 0xe, 0x2, 0xd7, 0xd8, 0x7, 0x9, 0x2, 0x2, 0xd8, 
    0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x8, 
    0xd, 0x1, 0x2, 0xdc, 0xdd, 0x7, 0x17, 0x2, 0x2, 0xdd, 0xdf, 0x5, 0x18, 
    0xd, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0x19, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x8, 0xe, 0x1, 0x2, 
    0xe1, 0xe2, 0x7, 0xf, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x1a, 0xe, 0x2, 0xe3, 
    0xe4, 0x7, 0x11, 0x2, 0x2, 0xe4, 0xed, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 
    0x7, 0x18, 0x2, 0x2, 0xe6, 0xed, 0x5, 0x1a, 0xe, 0xb, 0xe7, 0xe8, 0x7, 
    0x19, 0x2, 0x2, 0xe8, 0xed, 0x5, 0x1a, 0xe, 0xa, 0xe9, 0xea, 0x5, 0x2e, 
    0x18, 0x2, 0xea, 0xeb, 0x8, 0xe, 0x1, 0x2, 0xeb, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe5, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xed, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0xc, 0x9, 0x2, 0x2, 0xef, 0xf0, 
    0x5, 0x22, 0x12, 0x2, 0xf0, 0xf1, 0x5, 0x1a, 0xe, 0xa, 0xf1, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0xc, 0x8, 0x2, 0x2, 0xf3, 0xf4, 0x5, 
    0x24, 0x13, 0x2, 0xf4, 0xf5, 0x5, 0x1a, 0xe, 0x9, 0xf5, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf7, 0xc, 0x7, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x26, 
    0x14, 0x2, 0xf8, 0xf9, 0x5, 0x1a, 0xe, 0x8, 0xf9, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xfb, 0xc, 0x6, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x28, 0x15, 0x2, 
    0xfc, 0xfd, 0x5, 0x1a, 0xe, 0x7, 0xfd, 0x107, 0x3, 0x2, 0x2, 0x2, 0xfe, 
    0xff, 0xc, 0x5, 0x2, 0x2, 0xff, 0x100, 0x5, 0x2a, 0x16, 0x2, 0x100, 
    0x101, 0x5, 0x1a, 0xe, 0x6, 0x101, 0x107, 0x3, 0x2, 0x2, 0x2, 0x102, 
    0x103, 0xc, 0x4, 0x2, 0x2, 0x103, 0x104, 0x5, 0x2c, 0x17, 0x2, 0x104, 
    0x105, 0x5, 0x1a, 0xe, 0x5, 0x105, 0x107, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0x106, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x106, 0xf6, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x106, 0xfe, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x102, 0x3, 0x2, 0x2, 0x2, 0x107, 0x10a, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x109, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x10c, 0x7, 0x28, 0x2, 0x2, 0x10c, 0x115, 0x7, 0xf, 
    0x2, 0x2, 0x10d, 0x112, 0x5, 0x1e, 0x10, 0x2, 0x10e, 0x10f, 0x7, 0x10, 
    0x2, 0x2, 0x10f, 0x111, 0x5, 0x1e, 0x10, 0x2, 0x110, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x114, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x116, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x117, 0x118, 0x7, 0x11, 0x2, 0x2, 0x118, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x11a, 0x5, 0x1a, 0xe, 0x2, 0x11a, 0x11b, 0x8, 0x10, 
    0x1, 0x2, 0x11b, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11f, 0x5, 0x22, 
    0x12, 0x2, 0x11d, 0x11f, 0x5, 0x24, 0x13, 0x2, 0x11e, 0x11c, 0x3, 0x2, 
    0x2, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x120, 0x121, 0x9, 0x2, 0x2, 0x2, 0x121, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x122, 0x123, 0x9, 0x3, 0x2, 0x2, 0x123, 0x25, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0x125, 0x9, 0x4, 0x2, 0x2, 0x125, 0x27, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 
    0x9, 0x5, 0x2, 0x2, 0x127, 0x29, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x7, 
    0x24, 0x2, 0x2, 0x129, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x7, 
    0x25, 0x2, 0x2, 0x12b, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x5, 
    0x30, 0x19, 0x2, 0x12d, 0x12e, 0x8, 0x18, 0x1, 0x2, 0x12e, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x32, 0x1a, 0x2, 0x130, 0x131, 0x8, 
    0x18, 0x1, 0x2, 0x131, 0x136, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x5, 
    0x34, 0x1b, 0x2, 0x133, 0x134, 0x8, 0x18, 0x1, 0x2, 0x134, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x135, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x135, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x135, 0x132, 0x3, 0x2, 0x2, 0x2, 0x136, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x138, 0x7, 0x29, 0x2, 0x2, 0x138, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x139, 0x13a, 0x7, 0x2a, 0x2, 0x2, 0x13a, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x13c, 0x9, 0x6, 0x2, 0x2, 0x13c, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x1b, 0x3d, 0x45, 0x54, 0x5d, 0x70, 0x7b, 0x7e, 0x8c, 0x97, 0x9f, 
    0xa6, 0xac, 0xb8, 0xc2, 0xce, 0xd1, 0xd9, 0xde, 0xec, 0x106, 0x108, 
    0x112, 0x115, 0x11e, 0x135, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

DecafParser::Initializer DecafParser::_init;
