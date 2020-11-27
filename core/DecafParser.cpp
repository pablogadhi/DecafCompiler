
// Generated from /home/gadhi/Documents/Compis/Decaf/Decaf.g4 by ANTLR 4.8


#include "DecafListener.h"
#include "DecafVisitor.h"

#include "DecafParser.h"


#include "../structs/symb_table.h"
#include "../structs/triple.h"
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


pair<SymbolTable, vector<vector<string>>> DecafParser::symbol_table() {
  return table_head->flatten();
}

shared_ptr<SymbolTable> &DecafParser::symbols() {
	return table_head;
}

void DecafParser::set_error_handler(ErrorHandler *handler) {
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

  table_head->init_basic_types();
  table_top = table_head;
    
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(DecafParser::T__0);
    setState(51);
    match(DecafParser::T__1);
    setState(52);
    match(DecafParser::T__2);
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(53);
      declaration();
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(59);
    match(DecafParser::T__3);
   _ctx->stop = _input->LT(-1);

    if(!get_where<Method>(table_head->methods(), [](Method& m){return m.name() == "main" && m.param_signature().size() == 0;}, &_localctx->main)){
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

DecafParser::DeclarationContext* DecafParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, DecafParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(61);
      structDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(62);
      varDeclaration(nullptr);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(63);
      methodDeclaration();
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

DecafParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState, int * struct_size)
  : ParserRuleContext(parent, invokingState) {
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

DecafParser::VarDeclarationContext* DecafParser::varDeclaration(int * struct_size) {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState(), struct_size);
  enterRule(_localctx, 4, DecafParser::RuleVarDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
      dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext = varType();
      setState(67);
      dynamic_cast<VarDeclarationContext *>(_localctx)->idToken = match(DecafParser::ID);
      setState(68);
      match(DecafParser::T__4);
      dynamic_cast<VarDeclarationContext *>(_localctx)->name =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getText() : ""); dynamic_cast<VarDeclarationContext *>(_localctx)->d_type =  dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext->d_type; dynamic_cast<VarDeclarationContext *>(_localctx)->size =  dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext->size; dynamic_cast<VarDeclarationContext *>(_localctx)->line =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getLine() : 0); dynamic_cast<VarDeclarationContext *>(_localctx)->pos =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getCharPositionInLine() : 0);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(71);
      dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext = varType();
      setState(72);
      dynamic_cast<VarDeclarationContext *>(_localctx)->idToken = match(DecafParser::ID);
      setState(73);
      match(DecafParser::T__5);
      setState(74);
      dynamic_cast<VarDeclarationContext *>(_localctx)->numToken = match(DecafParser::NUM);
      setState(75);
      match(DecafParser::T__6);
      setState(76);
      match(DecafParser::T__4);

      dynamic_cast<VarDeclarationContext *>(_localctx)->name =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getText() : ""); dynamic_cast<VarDeclarationContext *>(_localctx)->d_type =  dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext->d_type; dynamic_cast<VarDeclarationContext *>(_localctx)->size =  dynamic_cast<VarDeclarationContext *>(_localctx)->varTypeContext->size * stoi((dynamic_cast<VarDeclarationContext *>(_localctx)->numToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->numToken->getText() : "")) ; dynamic_cast<VarDeclarationContext *>(_localctx)->line =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getLine() : 0); dynamic_cast<VarDeclarationContext *>(_localctx)->pos =  (dynamic_cast<VarDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->idToken->getCharPositionInLine() : 0);
      if(stoi((dynamic_cast<VarDeclarationContext *>(_localctx)->numToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->numToken->getText() : "")) <= 0){
        e_handler->get_lambda(WRONG_NUM_ARRAY, (dynamic_cast<VarDeclarationContext *>(_localctx)->numToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->numToken->getLine() : 0), (dynamic_cast<VarDeclarationContext *>(_localctx)->numToken != nullptr ? dynamic_cast<VarDeclarationContext *>(_localctx)->numToken->getCharPositionInLine() : 0))();
      }
          
      break;
    }

    }
   _ctx->stop = _input->LT(-1);

    if(_localctx->struct_size != nullptr){
      *struct_size += _localctx->size;
      table_top->add_type(_localctx->name, _localctx->d_type, _localctx->size, e_handler->get_lambda(IDENT_DEFINED, _localctx->line, _localctx->pos, vector<string>{_localctx->name, table_top->name()}));
    } else {
      table_top->add_symbol(_localctx->name, _localctx->d_type, _localctx->size, e_handler->get_lambda(IDENT_DEFINED, _localctx->line, _localctx->pos, vector<string>{_localctx->name, table_top->name()}));
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

DecafParser::StructDeclarationContext* DecafParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, DecafParser::RuleStructDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(DecafParser::T__7);
    setState(82);
    dynamic_cast<StructDeclarationContext *>(_localctx)->idToken = match(DecafParser::ID);

    dynamic_cast<StructDeclarationContext *>(_localctx)->new_table =  make_shared<SymbolTable>(Method((dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getText() : ""), "struct"), table_top);
    table_top = _localctx->new_table;
      
    setState(84);
    match(DecafParser::T__2);
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(85);
      varDeclaration(&_localctx->l_size);
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
    match(DecafParser::T__3);

    table_top = table_top->parent();
    table_top->add_type((dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getText() : ""), "struct", _localctx->l_size, e_handler->get_lambda(IDENT_DEFINED, (dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{(dynamic_cast<StructDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<StructDeclarationContext *>(_localctx)->idToken->getText() : ""), table_top->name()}));
    table_top->add_child(_localctx->new_table);
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

DecafParser::VarTypeContext* DecafParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, DecafParser::RuleVarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(94);
      match(DecafParser::T__8);
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  "int"; dynamic_cast<VarTypeContext *>(_localctx)->size =  4;
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(96);
      match(DecafParser::T__9);
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  "char"; dynamic_cast<VarTypeContext *>(_localctx)->size =  1;
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(98);
      match(DecafParser::T__10);
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  "boolean"; dynamic_cast<VarTypeContext *>(_localctx)->size =  1;
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(100);
      match(DecafParser::T__7);
      setState(101);
      dynamic_cast<VarTypeContext *>(_localctx)->idToken = match(DecafParser::ID);

      auto struct_name = (dynamic_cast<VarTypeContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarTypeContext *>(_localctx)->idToken->getText() : "");
      Type type_ctr;
      if(recursive_lookup<Type>(table_top, [&](shared_ptr<SymbolTable> table){return table->types();}, [struct_name](Type& t){ return t.name() == struct_name && t.type() == "struct";}, &type_ctr)){
        dynamic_cast<VarTypeContext *>(_localctx)->d_type =  type_ctr.name(); dynamic_cast<VarTypeContext *>(_localctx)->size =  type_ctr.size();
      } else {
        e_handler->get_lambda(IDENT_NOT_DEFINED, (dynamic_cast<VarTypeContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarTypeContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<VarTypeContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarTypeContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{struct_name});
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(103);
      dynamic_cast<VarTypeContext *>(_localctx)->structDeclarationContext = structDeclaration();
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  dynamic_cast<VarTypeContext *>(_localctx)->structDeclarationContext->d_type; dynamic_cast<VarTypeContext *>(_localctx)->size =  dynamic_cast<VarTypeContext *>(_localctx)->structDeclarationContext->size;
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(106);
      match(DecafParser::T__11);
      dynamic_cast<VarTypeContext *>(_localctx)->d_type =  "void"; dynamic_cast<VarTypeContext *>(_localctx)->size =  0;
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

DecafParser::MethodDeclarationContext* DecafParser::methodDeclaration() {
  MethodDeclarationContext *_localctx = _tracker.createInstance<MethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, DecafParser::RuleMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    dynamic_cast<MethodDeclarationContext *>(_localctx)->methodTypeContext = methodType();
    setState(111);
    dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken = match(DecafParser::ID);
    setState(112);
    match(DecafParser::T__12);
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10))) != 0)) {
      setState(113);
      parameter(&_localctx->params);
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DecafParser::T__13) {
        setState(114);
        match(DecafParser::T__13);
        setState(115);
        parameter(&_localctx->params);
        setState(120);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(123);
    match(DecafParser::T__14);

    vector<string> param_types;
    transform(_localctx->params.begin(), _localctx->params.end(), back_inserter(param_types), [](Symbol &s){return s.type();});
    dynamic_cast<MethodDeclarationContext *>(_localctx)->new_table =  make_shared<SymbolTable>(Method((dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : ""), dynamic_cast<MethodDeclarationContext *>(_localctx)->methodTypeContext->d_type, param_types), table_top);
    dynamic_cast<MethodDeclarationContext *>(_localctx)->alias =  (dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : "") + "_" + to_string(scope_counter);
    scope_counter++;
    table_top->add_method((dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : ""), dynamic_cast<MethodDeclarationContext *>(_localctx)->methodTypeContext->d_type, param_types, _localctx->alias, e_handler->get_lambda(IDENT_DEFINED, (dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{(dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : ""), table_top->name()}));
    table_top->add_child(_localctx->new_table);
    for(auto &symb: _localctx->params){
      _localctx->new_table->add_symbol(symb.name(), symb.type(), symb.size());
    }
    table_top = _localctx->new_table;
      
    setState(125);
    block((dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodDeclarationContext *>(_localctx)->idToken->getText() : ""));

    table_top = table_top->parent();
        
   
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
    setState(136);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(128);
        match(DecafParser::T__8);
        dynamic_cast<MethodTypeContext *>(_localctx)->d_type =  "int";
        break;
      }

      case DecafParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(130);
        match(DecafParser::T__9);
        dynamic_cast<MethodTypeContext *>(_localctx)->d_type =  "char";
        break;
      }

      case DecafParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(132);
        match(DecafParser::T__10);
        dynamic_cast<MethodTypeContext *>(_localctx)->d_type =  "boolean";
        break;
      }

      case DecafParser::T__11: {
        enterOuterAlt(_localctx, 4);
        setState(134);
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

DecafParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState, vector<Symbol> * meth_params)
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

DecafParser::ParameterContext* DecafParser::parameter(vector<Symbol> * meth_params) {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState(), meth_params);
  enterRule(_localctx, 14, DecafParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(138);
      dynamic_cast<ParameterContext *>(_localctx)->parameterTypeContext = parameterType();
      setState(139);
      dynamic_cast<ParameterContext *>(_localctx)->idToken = match(DecafParser::ID);
      meth_params->push_back(Symbol((dynamic_cast<ParameterContext *>(_localctx)->idToken != nullptr ? dynamic_cast<ParameterContext *>(_localctx)->idToken->getText() : ""), dynamic_cast<ParameterContext *>(_localctx)->parameterTypeContext->d_type, dynamic_cast<ParameterContext *>(_localctx)->parameterTypeContext->size, 0));
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(142);
      parameterType();
      setState(143);
      match(DecafParser::ID);
      setState(144);
      match(DecafParser::T__5);
      setState(145);
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
    setState(155);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(149);
        match(DecafParser::T__8);
        dynamic_cast<ParameterTypeContext *>(_localctx)->d_type =  "int"; dynamic_cast<ParameterTypeContext *>(_localctx)->size =  4;
        break;
      }

      case DecafParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(151);
        match(DecafParser::T__9);
        dynamic_cast<ParameterTypeContext *>(_localctx)->d_type =  "char"; dynamic_cast<ParameterTypeContext *>(_localctx)->size =  1;
        break;
      }

      case DecafParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(153);
        match(DecafParser::T__10);
        dynamic_cast<ParameterTypeContext *>(_localctx)->d_type =  "boolean"; dynamic_cast<ParameterTypeContext *>(_localctx)->size =  1;
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

DecafParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState, string method_name)
  : ParserRuleContext(parent, invokingState) {
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

DecafParser::BlockContext* DecafParser::block(string method_name) {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState(), method_name);
  enterRule(_localctx, 18, DecafParser::RuleBlock);

  if(method_name == ""){
    dynamic_cast<BlockContext *>(_localctx)->new_table =  make_shared<SymbolTable>(Method(table_top->name() + "_" + to_string(scope_counter), table_top->id().type()), table_top);
    scope_counter++;
    table_top->add_method(_localctx->new_table->name(), table_top->id().type(), vector<string>{});
    table_top->add_child(_localctx->new_table);
    table_top = _localctx->new_table;
  }
    
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(DecafParser::T__2);
    setState(161);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(158);
      varDeclaration(nullptr);
      setState(163);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169);
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
      setState(164);
      dynamic_cast<BlockContext *>(_localctx)->statementContext = statement();
      dynamic_cast<BlockContext *>(_localctx)->next_list =  dynamic_cast<BlockContext *>(_localctx)->statementContext->next_list;
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(172);
    match(DecafParser::T__3);
   _ctx->stop = _input->LT(-1);

    if(method_name == ""){
      table_top = table_top->parent();
    }
      
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


size_t DecafParser::StatementContext::getRuleIndex() const {
  return DecafParser::RuleStatement;
}

void DecafParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->next_list = ctx->next_list;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::WhileStatementContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::BlockContext* DecafParser::WhileStatementContext::block() {
  return getRuleContext<DecafParser::BlockContext>(0);
}

DecafParser::WhileStatementContext::WhileStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}
void DecafParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}

antlrcpp::Any DecafParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockStatementContext ------------------------------------------------------------------

DecafParser::BlockContext* DecafParser::BlockStatementContext::block() {
  return getRuleContext<DecafParser::BlockContext>(0);
}

DecafParser::BlockStatementContext::BlockStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::BlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStatement(this);
}
void DecafParser::BlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStatement(this);
}

antlrcpp::Any DecafParser::BlockStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitBlockStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodCallStatementContext ------------------------------------------------------------------

DecafParser::MethodCallContext* DecafParser::MethodCallStatementContext::methodCall() {
  return getRuleContext<DecafParser::MethodCallContext>(0);
}

DecafParser::MethodCallStatementContext::MethodCallStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::MethodCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCallStatement(this);
}
void DecafParser::MethodCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCallStatement(this);
}

antlrcpp::Any DecafParser::MethodCallStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodCallStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStatementContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::ExprStatementContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::ExprStatementContext::ExprStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::ExprStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStatement(this);
}
void DecafParser::ExprStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStatement(this);
}

antlrcpp::Any DecafParser::ExprStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExprStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStatementContext ------------------------------------------------------------------

DecafParser::LocationContext* DecafParser::AssignStatementContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}

DecafParser::ExpressionContext* DecafParser::AssignStatementContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::AssignStatementContext::AssignStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::AssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStatement(this);
}
void DecafParser::AssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStatement(this);
}

antlrcpp::Any DecafParser::AssignStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitAssignStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStatementContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::IfStatementContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

std::vector<DecafParser::BlockContext *> DecafParser::IfStatementContext::block() {
  return getRuleContexts<DecafParser::BlockContext>();
}

DecafParser::BlockContext* DecafParser::IfStatementContext::block(size_t i) {
  return getRuleContext<DecafParser::BlockContext>(i);
}

DecafParser::IfStatementContext::IfStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}
void DecafParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

antlrcpp::Any DecafParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStatementContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::ReturnStatementContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::ReturnStatementContext::ReturnStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}
void DecafParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

antlrcpp::Any DecafParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}
DecafParser::StatementContext* DecafParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, DecafParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(211);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::IfStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(174);
      match(DecafParser::T__15);
      setState(175);
      match(DecafParser::T__12);
      setState(176);
      dynamic_cast<IfStatementContext *>(_localctx)->expressionContext = expression(0);

      if(dynamic_cast<IfStatementContext *>(_localctx)->expressionContext->d_type != "boolean"){
        e_handler->get_lambda(EXPR_TYPE_ERROR, (dynamic_cast<IfStatementContext *>(_localctx)->expressionContext != nullptr ? (dynamic_cast<IfStatementContext *>(_localctx)->expressionContext->start) : nullptr)->getLine(), (dynamic_cast<IfStatementContext *>(_localctx)->expressionContext != nullptr ? (dynamic_cast<IfStatementContext *>(_localctx)->expressionContext->start) : nullptr)->getCharPositionInLine()+ 1, vector<string>{dynamic_cast<IfStatementContext *>(_localctx)->expressionContext->d_type, "boolean"})();
      }

      setState(178);
      match(DecafParser::T__14);
      setState(179);
      dynamic_cast<IfStatementContext *>(_localctx)->true_block = block("");
      setState(182);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::T__16) {
        setState(180);
        match(DecafParser::T__16);
        setState(181);
        dynamic_cast<IfStatementContext *>(_localctx)->false_block = block("");
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::WhileStatementContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(184);
      match(DecafParser::T__17);
      setState(185);
      match(DecafParser::T__12);
      setState(186);
      dynamic_cast<WhileStatementContext *>(_localctx)->expressionContext = expression(0);

      if(dynamic_cast<WhileStatementContext *>(_localctx)->expressionContext->d_type != "boolean"){
        e_handler->get_lambda(EXPR_TYPE_ERROR, (dynamic_cast<WhileStatementContext *>(_localctx)->expressionContext != nullptr ? (dynamic_cast<WhileStatementContext *>(_localctx)->expressionContext->start) : nullptr)->getLine(), (dynamic_cast<WhileStatementContext *>(_localctx)->expressionContext != nullptr ? (dynamic_cast<WhileStatementContext *>(_localctx)->expressionContext->start) : nullptr)->getCharPositionInLine(), vector<string>{dynamic_cast<WhileStatementContext *>(_localctx)->expressionContext->d_type, "boolean"})();
      }
        
      setState(188);
      match(DecafParser::T__14);
      setState(189);
      block("");
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::ReturnStatementContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(191);
      dynamic_cast<ReturnStatementContext *>(_localctx)->r = match(DecafParser::T__18);
      setState(195);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__12)
        | (1ULL << DecafParser::T__21)
        | (1ULL << DecafParser::T__22)
        | (1ULL << DecafParser::T__35)
        | (1ULL << DecafParser::T__36)
        | (1ULL << DecafParser::ID)
        | (1ULL << DecafParser::NUM)
        | (1ULL << DecafParser::CHAR))) != 0)) {
        setState(192);
        dynamic_cast<ReturnStatementContext *>(_localctx)->expressionContext = expression(0);

        if(dynamic_cast<ReturnStatementContext *>(_localctx)->expressionContext->d_type != table_top->id().type()){
          e_handler->get_lambda(WRONG_RETURN_TYPE, (dynamic_cast<ReturnStatementContext *>(_localctx)->r != nullptr ? dynamic_cast<ReturnStatementContext *>(_localctx)->r->getLine() : 0), (dynamic_cast<ReturnStatementContext *>(_localctx)->r != nullptr ? dynamic_cast<ReturnStatementContext *>(_localctx)->r->getCharPositionInLine() : 0), vector<string>{table_top->name(), table_top->id().type(), dynamic_cast<ReturnStatementContext *>(_localctx)->expressionContext->d_type})();
        }
          
      }
      setState(197);
      match(DecafParser::T__4);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::MethodCallStatementContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(198);
      methodCall();
      setState(199);
      match(DecafParser::T__4);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::BlockStatementContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(201);
      block("");
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::AssignStatementContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(202);
      dynamic_cast<AssignStatementContext *>(_localctx)->locationContext = location();
      setState(203);
      match(DecafParser::T__19);
      setState(204);
      dynamic_cast<AssignStatementContext *>(_localctx)->expressionContext = expression(0);

      if(dynamic_cast<AssignStatementContext *>(_localctx)->locationContext->d_type != dynamic_cast<AssignStatementContext *>(_localctx)->expressionContext->d_type){
        e_handler->get_lambda(EXPR_TYPE_ERROR, (dynamic_cast<AssignStatementContext *>(_localctx)->expressionContext != nullptr ? (dynamic_cast<AssignStatementContext *>(_localctx)->expressionContext->start) : nullptr)->getLine(), (dynamic_cast<AssignStatementContext *>(_localctx)->expressionContext != nullptr ? (dynamic_cast<AssignStatementContext *>(_localctx)->expressionContext->start) : nullptr)->getCharPositionInLine(), vector<string>{dynamic_cast<AssignStatementContext *>(_localctx)->expressionContext->d_type, dynamic_cast<AssignStatementContext *>(_localctx)->locationContext->d_type})();
      } 

      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::ExprStatementContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(208);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__12)
        | (1ULL << DecafParser::T__21)
        | (1ULL << DecafParser::T__22)
        | (1ULL << DecafParser::T__35)
        | (1ULL << DecafParser::T__36)
        | (1ULL << DecafParser::ID)
        | (1ULL << DecafParser::NUM)
        | (1ULL << DecafParser::CHAR))) != 0)) {
        setState(207);
        expression(0);
      }
      setState(210);
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

DecafParser::LocationContext* DecafParser::location() {
  LocationContext *_localctx = _tracker.createInstance<LocationContext>(_ctx, getState());
  enterRule(_localctx, 22, DecafParser::RuleLocation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(213);
      dynamic_cast<LocationContext *>(_localctx)->idToken = match(DecafParser::ID);
      break;
    }

    case 2: {
      setState(214);
      dynamic_cast<LocationContext *>(_localctx)->idToken = match(DecafParser::ID);
      setState(215);
      match(DecafParser::T__5);
      setState(216);
      dynamic_cast<LocationContext *>(_localctx)->expressionContext = expression(0);
      setState(217);
      match(DecafParser::T__6);
      dynamic_cast<LocationContext *>(_localctx)->array_check =  true;
      break;
    }

    }

    shared_ptr<SymbolTable> parent_table;
    if(recursive_lookup<Symbol>(table_top, [&](shared_ptr<SymbolTable> t){return t->symbols();}, [&](Symbol &s){return s.name() == (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getText() : "");}, parent_table, &_localctx->out)){
      dynamic_cast<LocationContext *>(_localctx)->d_type =  _localctx->out.type();
      if(_localctx->array_check){
        recursive_lookup<Type>(table_top, [&](shared_ptr<SymbolTable> t){return t->types();}, [&](Type &t){return t.name() == _localctx->out.type();}, &_localctx->type_info);
        if(_localctx->type_info.size() == _localctx->out.size()){
          e_handler->get_lambda(IDENT_NOT_ARRAY, (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{(dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getText() : "")})();
        } else if(dynamic_cast<LocationContext *>(_localctx)->expressionContext->d_type != "int"){
          e_handler->get_lambda(INDEX_NOT_INT, (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{(dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getText() : "")})();
        } 
      }
    } else {
      e_handler->get_lambda(IDENT_NOT_DEFINED, (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getCharPositionInLine() : 0), vector<string>{(dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getText() : "")})();
    }
      
    setState(228);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(223);
      match(DecafParser::T__20);

      dynamic_cast<LocationContext *>(_localctx)->old_top =  table_top;
      if(parent_table != nullptr){
      auto children = parent_table->children();
      if(children.find(Method((dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getText() : ""), "")) != children.end()){
        table_top = children[Method((dynamic_cast<LocationContext *>(_localctx)->idToken != nullptr ? dynamic_cast<LocationContext *>(_localctx)->idToken->getText() : ""), "")];
      }
        }

      setState(225);
      dynamic_cast<LocationContext *>(_localctx)->child = dynamic_cast<LocationContext *>(_localctx)->locationContext = location();

      dynamic_cast<LocationContext *>(_localctx)->d_type =  dynamic_cast<LocationContext *>(_localctx)->locationContext->d_type;
      table_top = _localctx->old_top;

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

//----------------- ExpressionContext ------------------------------------------------------------------

DecafParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::ExpressionContext::getRuleIndex() const {
  return DecafParser::RuleExpression;
}

void DecafParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->d_type = ctx->d_type;
  this->addr = ctx->addr;
  this->false_list = ctx->false_list;
  this->true_list = ctx->true_list;
}

//----------------- MethodCallExprContext ------------------------------------------------------------------

DecafParser::MethodCallContext* DecafParser::MethodCallExprContext::methodCall() {
  return getRuleContext<DecafParser::MethodCallContext>(0);
}

DecafParser::MethodCallExprContext::MethodCallExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::MethodCallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCallExpr(this);
}
void DecafParser::MethodCallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCallExpr(this);
}

antlrcpp::Any DecafParser::MethodCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqExprContext ------------------------------------------------------------------

std::vector<DecafParser::ExpressionContext *> DecafParser::EqExprContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::EqExprContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::Eq_opContext* DecafParser::EqExprContext::eq_op() {
  return getRuleContext<DecafParser::Eq_opContext>(0);
}

DecafParser::EqExprContext::EqExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::EqExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpr(this);
}
void DecafParser::EqExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpr(this);
}

antlrcpp::Any DecafParser::EqExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitEqExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::NotExprContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::NotExprContext::NotExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::NotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpr(this);
}
void DecafParser::NotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpr(this);
}

antlrcpp::Any DecafParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LocationExprContext ------------------------------------------------------------------

DecafParser::LocationContext* DecafParser::LocationExprContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}

DecafParser::LocationExprContext::LocationExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::LocationExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocationExpr(this);
}
void DecafParser::LocationExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocationExpr(this);
}

antlrcpp::Any DecafParser::LocationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLocationExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExprContext ------------------------------------------------------------------

DecafParser::LiteralContext* DecafParser::LiteralExprContext::literal() {
  return getRuleContext<DecafParser::LiteralContext>(0);
}

DecafParser::LiteralExprContext::LiteralExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::LiteralExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralExpr(this);
}
void DecafParser::LiteralExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralExpr(this);
}

antlrcpp::Any DecafParser::LiteralExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLiteralExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

DecafParser::Or_opContext* DecafParser::OrExprContext::or_op() {
  return getRuleContext<DecafParser::Or_opContext>(0);
}

std::vector<DecafParser::ExpressionContext *> DecafParser::OrExprContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::OrExprContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::OrExprContext::OrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void DecafParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

antlrcpp::Any DecafParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AritHighExprContext ------------------------------------------------------------------

DecafParser::Arith_high_opContext* DecafParser::AritHighExprContext::arith_high_op() {
  return getRuleContext<DecafParser::Arith_high_opContext>(0);
}

std::vector<DecafParser::ExpressionContext *> DecafParser::AritHighExprContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::AritHighExprContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::AritHighExprContext::AritHighExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::AritHighExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAritHighExpr(this);
}
void DecafParser::AritHighExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAritHighExpr(this);
}

antlrcpp::Any DecafParser::AritHighExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitAritHighExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AritLowExprContext ------------------------------------------------------------------

DecafParser::Arith_low_opContext* DecafParser::AritLowExprContext::arith_low_op() {
  return getRuleContext<DecafParser::Arith_low_opContext>(0);
}

std::vector<DecafParser::ExpressionContext *> DecafParser::AritLowExprContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::AritLowExprContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::AritLowExprContext::AritLowExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::AritLowExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAritLowExpr(this);
}
void DecafParser::AritLowExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAritLowExpr(this);
}

antlrcpp::Any DecafParser::AritLowExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitAritLowExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParensExprContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::ParensExprContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::ParensExprContext::ParensExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::ParensExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParensExpr(this);
}
void DecafParser::ParensExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParensExpr(this);
}

antlrcpp::Any DecafParser::ParensExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitParensExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelExprContext ------------------------------------------------------------------

DecafParser::Rel_opContext* DecafParser::RelExprContext::rel_op() {
  return getRuleContext<DecafParser::Rel_opContext>(0);
}

std::vector<DecafParser::ExpressionContext *> DecafParser::RelExprContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::RelExprContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::RelExprContext::RelExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::RelExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpr(this);
}
void DecafParser::RelExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpr(this);
}

antlrcpp::Any DecafParser::RelExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitRelExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinusExprContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::MinusExprContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::MinusExprContext::MinusExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::MinusExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMinusExpr(this);
}
void DecafParser::MinusExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMinusExpr(this);
}

antlrcpp::Any DecafParser::MinusExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMinusExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndExprContext ------------------------------------------------------------------

DecafParser::And_opContext* DecafParser::AndExprContext::and_op() {
  return getRuleContext<DecafParser::And_opContext>(0);
}

std::vector<DecafParser::ExpressionContext *> DecafParser::AndExprContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::AndExprContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::AndExprContext::AndExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void DecafParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

antlrcpp::Any DecafParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
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
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, DecafParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(231);
      match(DecafParser::T__12);
      setState(232);
      dynamic_cast<ParensExprContext *>(_localctx)->expressionContext = expression(0);
      setState(233);
      match(DecafParser::T__14);
      dynamic_cast<ParensExprContext *>(_localctx)->d_type =  dynamic_cast<ParensExprContext *>(_localctx)->expressionContext->d_type;
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<LiteralExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(236);
      dynamic_cast<LiteralExprContext *>(_localctx)->literalContext = literal();

      dynamic_cast<LiteralExprContext *>(_localctx)->d_type =  dynamic_cast<LiteralExprContext *>(_localctx)->literalContext->d_type;

      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MethodCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(239);
      dynamic_cast<MethodCallExprContext *>(_localctx)->methodCallContext = methodCall();

      if(dynamic_cast<MethodCallExprContext *>(_localctx)->methodCallContext->d_type == "void"){
        e_handler->get_lambda(NO_RETURN_IN_EXPR, dynamic_cast<MethodCallExprContext *>(_localctx)->methodCallContext->line, dynamic_cast<MethodCallExprContext *>(_localctx)->methodCallContext->pos, vector<string>{(dynamic_cast<MethodCallExprContext *>(_localctx)->methodCallContext != nullptr ? _input->getText(dynamic_cast<MethodCallExprContext *>(_localctx)->methodCallContext->start, dynamic_cast<MethodCallExprContext *>(_localctx)->methodCallContext->stop) : nullptr)})();
      }else{
        dynamic_cast<MethodCallExprContext *>(_localctx)->d_type =  dynamic_cast<MethodCallExprContext *>(_localctx)->methodCallContext->d_type;
      }

      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<LocationExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(242);
      dynamic_cast<LocationExprContext *>(_localctx)->locationContext = location();

      dynamic_cast<LocationExprContext *>(_localctx)->d_type =  dynamic_cast<LocationExprContext *>(_localctx)->locationContext->d_type;

      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(245);
      match(DecafParser::T__21);
      setState(246);
      dynamic_cast<NotExprContext *>(_localctx)->expressionContext = expression(8);

      if(dynamic_cast<NotExprContext *>(_localctx)->expressionContext->d_type != "boolean"){
        e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, (dynamic_cast<NotExprContext *>(_localctx)->expressionContext != nullptr ? (dynamic_cast<NotExprContext *>(_localctx)->expressionContext->start) : nullptr)->getLine(), (dynamic_cast<NotExprContext *>(_localctx)->expressionContext != nullptr ? (dynamic_cast<NotExprContext *>(_localctx)->expressionContext->start) : nullptr)->getCharPositionInLine(), vector<string>{"boolean"})();
      }else{
      	dynamic_cast<NotExprContext *>(_localctx)->d_type =  dynamic_cast<NotExprContext *>(_localctx)->expressionContext->d_type;
      } 

      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MinusExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(249);
      match(DecafParser::T__22);
      setState(250);
      dynamic_cast<MinusExprContext *>(_localctx)->expressionContext = expression(7);

      // TODO Check the expression type
      dynamic_cast<MinusExprContext *>(_localctx)->d_type =  dynamic_cast<MinusExprContext *>(_localctx)->expressionContext->d_type;

      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(287);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(285);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AritHighExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lexpr = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(255);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(256);
          arith_high_op();
          setState(257);
          dynamic_cast<AritHighExprContext *>(_localctx)->rexpr = dynamic_cast<AritHighExprContext *>(_localctx)->expressionContext = expression(7);

                    if(dynamic_cast<AritHighExprContext *>(_localctx)->lexpr->d_type != "int" || dynamic_cast<AritHighExprContext *>(_localctx)->rexpr->d_type != "int"){
                      e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, (dynamic_cast<AritHighExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<AritHighExprContext *>(_localctx)->lexpr->start) : nullptr)->getLine(), (dynamic_cast<AritHighExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<AritHighExprContext *>(_localctx)->lexpr->start) : nullptr)->getCharPositionInLine(), vector<string>{"int"})();
                    }else{
                    	dynamic_cast<AritHighExprContext *>(_localctx)->d_type =  dynamic_cast<AritHighExprContext *>(_localctx)->lexpr->d_type;
                    }
                    
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AritLowExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lexpr = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(260);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(261);
          arith_low_op();
          setState(262);
          dynamic_cast<AritLowExprContext *>(_localctx)->rexpr = dynamic_cast<AritLowExprContext *>(_localctx)->expressionContext = expression(6);

                    if(dynamic_cast<AritLowExprContext *>(_localctx)->lexpr->d_type != "int" || dynamic_cast<AritLowExprContext *>(_localctx)->rexpr->d_type != "int"){
                      e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, (dynamic_cast<AritLowExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<AritLowExprContext *>(_localctx)->lexpr->start) : nullptr)->getLine(), (dynamic_cast<AritLowExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<AritLowExprContext *>(_localctx)->lexpr->start) : nullptr)->getCharPositionInLine(), vector<string>{"int"})();
                    }else{
                    	dynamic_cast<AritLowExprContext *>(_localctx)->d_type =  dynamic_cast<AritLowExprContext *>(_localctx)->lexpr->d_type;
                    } 
                    
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lexpr = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(265);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(266);
          rel_op();
          setState(267);
          dynamic_cast<RelExprContext *>(_localctx)->rexpr = dynamic_cast<RelExprContext *>(_localctx)->expressionContext = expression(5);

                    if(dynamic_cast<RelExprContext *>(_localctx)->lexpr->d_type != "int" || dynamic_cast<RelExprContext *>(_localctx)->rexpr->d_type != "int"){
                      e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, (dynamic_cast<RelExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<RelExprContext *>(_localctx)->lexpr->start) : nullptr)->getLine(), (dynamic_cast<RelExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<RelExprContext *>(_localctx)->lexpr->start) : nullptr)->getCharPositionInLine(), vector<string>{"int"})();
                    }else{
                      dynamic_cast<RelExprContext *>(_localctx)->d_type =  "boolean";
                    }
                    
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lexpr = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(270);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(271);
          dynamic_cast<EqExprContext *>(_localctx)->op = eq_op();
          setState(272);
          dynamic_cast<EqExprContext *>(_localctx)->rexpr = dynamic_cast<EqExprContext *>(_localctx)->expressionContext = expression(4);

                    auto valid_types = vector<string>{"int", "char", "boolean"};
                    if(dynamic_cast<EqExprContext *>(_localctx)->lexpr->d_type != dynamic_cast<EqExprContext *>(_localctx)->rexpr->d_type){
                      e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, (dynamic_cast<EqExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<EqExprContext *>(_localctx)->lexpr->start) : nullptr)->getLine(), (dynamic_cast<EqExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<EqExprContext *>(_localctx)->lexpr->start) : nullptr)->getCharPositionInLine(), vector<string>{dynamic_cast<EqExprContext *>(_localctx)->lexpr->d_type})();
                    }else if(find(valid_types.begin(), valid_types.end(), dynamic_cast<EqExprContext *>(_localctx)->lexpr->d_type) == valid_types.end()){
                      e_handler->get_lambda(CAN_NOT_USE_OPERATOR, (dynamic_cast<EqExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<EqExprContext *>(_localctx)->lexpr->start) : nullptr)->getLine(), (dynamic_cast<EqExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<EqExprContext *>(_localctx)->lexpr->start) : nullptr)->getCharPositionInLine(), vector<string>{dynamic_cast<EqExprContext *>(_localctx)->lexpr->d_type})();
                    }else if(find(valid_types.begin(), valid_types.end(), dynamic_cast<EqExprContext *>(_localctx)->rexpr->d_type) == valid_types.end()){
                      e_handler->get_lambda(CAN_NOT_USE_OPERATOR, (dynamic_cast<EqExprContext *>(_localctx)->rexpr != nullptr ? (dynamic_cast<EqExprContext *>(_localctx)->rexpr->start) : nullptr)->getLine(), (dynamic_cast<EqExprContext *>(_localctx)->rexpr != nullptr ? (dynamic_cast<EqExprContext *>(_localctx)->rexpr->start) : nullptr)->getCharPositionInLine(), vector<string>{dynamic_cast<EqExprContext *>(_localctx)->rexpr->d_type})();
                    }else{
                      dynamic_cast<EqExprContext *>(_localctx)->d_type =  "boolean";
                    }
                    
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lexpr = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(275);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(276);
          and_op();
          setState(277);
          dynamic_cast<AndExprContext *>(_localctx)->rexpr = dynamic_cast<AndExprContext *>(_localctx)->expressionContext = expression(3);

                    if(dynamic_cast<AndExprContext *>(_localctx)->lexpr->d_type != "boolean" || dynamic_cast<AndExprContext *>(_localctx)->rexpr->d_type != "boolean"){
                      e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, (dynamic_cast<AndExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<AndExprContext *>(_localctx)->lexpr->start) : nullptr)->getLine(), (dynamic_cast<AndExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<AndExprContext *>(_localctx)->lexpr->start) : nullptr)->getCharPositionInLine(), vector<string>{"boolean"})();
                    }else{
                      dynamic_cast<AndExprContext *>(_localctx)->d_type =  "boolean";
                    } 
                    
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lexpr = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(280);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(281);
          or_op();
          setState(282);
          dynamic_cast<OrExprContext *>(_localctx)->rexpr = dynamic_cast<OrExprContext *>(_localctx)->expressionContext = expression(2);

                    if(dynamic_cast<OrExprContext *>(_localctx)->lexpr->d_type != "boolean" || dynamic_cast<OrExprContext *>(_localctx)->rexpr->d_type != "boolean"){
                      e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, (dynamic_cast<OrExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<OrExprContext *>(_localctx)->lexpr->start) : nullptr)->getLine(), (dynamic_cast<OrExprContext *>(_localctx)->lexpr != nullptr ? (dynamic_cast<OrExprContext *>(_localctx)->lexpr->start) : nullptr)->getCharPositionInLine(), vector<string>{"boolean"})();
                    }else{
                      dynamic_cast<OrExprContext *>(_localctx)->d_type =  "boolean";
                    }
                    
          break;
        }

        } 
      }
      setState(289);
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

DecafParser::MethodCallContext* DecafParser::methodCall() {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState());
  enterRule(_localctx, 26, DecafParser::RuleMethodCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    dynamic_cast<MethodCallContext *>(_localctx)->idToken = match(DecafParser::ID);
    setState(291);
    match(DecafParser::T__12);
    setState(300);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__12)
      | (1ULL << DecafParser::T__21)
      | (1ULL << DecafParser::T__22)
      | (1ULL << DecafParser::T__35)
      | (1ULL << DecafParser::T__36)
      | (1ULL << DecafParser::ID)
      | (1ULL << DecafParser::NUM)
      | (1ULL << DecafParser::CHAR))) != 0)) {
      setState(292);
      arg(&_localctx->arg_types);
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DecafParser::T__13) {
        setState(293);
        match(DecafParser::T__13);
        setState(294);
        arg(&_localctx->arg_types);
        setState(299);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(302);
    match(DecafParser::T__14);

    if(!get_where<Method>(table_head->methods(), [&](Method &m){return m.name() == (dynamic_cast<MethodCallContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodCallContext *>(_localctx)->idToken->getText() : "") && m.param_signature() == _localctx->arg_types;}, &_localctx->out)){
      auto msg_parts = vector<string>{(dynamic_cast<MethodCallContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodCallContext *>(_localctx)->idToken->getText() : "")};
      msg_parts.insert(msg_parts.end(), _localctx->arg_types.begin(), _localctx->arg_types.end());
      e_handler->get_lambda(NO_METHOD_WITH_SIGN, (dynamic_cast<MethodCallContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodCallContext *>(_localctx)->idToken->getLine() : 0), (dynamic_cast<MethodCallContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodCallContext *>(_localctx)->idToken->getCharPositionInLine() : 0), msg_parts)();
    }
    dynamic_cast<MethodCallContext *>(_localctx)->d_type =  _localctx->out.type(); dynamic_cast<MethodCallContext *>(_localctx)->line =  (dynamic_cast<MethodCallContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodCallContext *>(_localctx)->idToken->getLine() : 0); dynamic_cast<MethodCallContext *>(_localctx)->pos =  (dynamic_cast<MethodCallContext *>(_localctx)->idToken != nullptr ? dynamic_cast<MethodCallContext *>(_localctx)->idToken->getCharPositionInLine() : 0);
      
   
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

DecafParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState, vector<string> * method_arg_types)
  : ParserRuleContext(parent, invokingState) {
  this->method_arg_types = method_arg_types;
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

DecafParser::ArgContext* DecafParser::arg(vector<string> * method_arg_types) {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState(), method_arg_types);
  enterRule(_localctx, 28, DecafParser::RuleArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
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

//----------------- Arith_high_opContext ------------------------------------------------------------------

DecafParser::Arith_high_opContext::Arith_high_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Arith_high_opContext::getRuleIndex() const {
  return DecafParser::RuleArith_high_op;
}

void DecafParser::Arith_high_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_high_op(this);
}

void DecafParser::Arith_high_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_high_op(this);
}


antlrcpp::Any DecafParser::Arith_high_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitArith_high_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Arith_high_opContext* DecafParser::arith_high_op() {
  Arith_high_opContext *_localctx = _tracker.createInstance<Arith_high_opContext>(_ctx, getState());
  enterRule(_localctx, 30, DecafParser::RuleArith_high_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(314);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__23: {
        enterOuterAlt(_localctx, 1);
        setState(308);
        match(DecafParser::T__23);
        dynamic_cast<Arith_high_opContext *>(_localctx)->op =  Operator::MUL;
        break;
      }

      case DecafParser::T__24: {
        enterOuterAlt(_localctx, 2);
        setState(310);
        match(DecafParser::T__24);
        dynamic_cast<Arith_high_opContext *>(_localctx)->op =  Operator::DIV;
        break;
      }

      case DecafParser::T__25: {
        enterOuterAlt(_localctx, 3);
        setState(312);
        match(DecafParser::T__25);
        dynamic_cast<Arith_high_opContext *>(_localctx)->op =  Operator::MOD;
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

//----------------- Arith_low_opContext ------------------------------------------------------------------

DecafParser::Arith_low_opContext::Arith_low_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Arith_low_opContext::getRuleIndex() const {
  return DecafParser::RuleArith_low_op;
}

void DecafParser::Arith_low_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_low_op(this);
}

void DecafParser::Arith_low_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_low_op(this);
}


antlrcpp::Any DecafParser::Arith_low_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitArith_low_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Arith_low_opContext* DecafParser::arith_low_op() {
  Arith_low_opContext *_localctx = _tracker.createInstance<Arith_low_opContext>(_ctx, getState());
  enterRule(_localctx, 32, DecafParser::RuleArith_low_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__26: {
        enterOuterAlt(_localctx, 1);
        setState(316);
        match(DecafParser::T__26);
        dynamic_cast<Arith_low_opContext *>(_localctx)->op =  Operator::SUM;
        break;
      }

      case DecafParser::T__22: {
        enterOuterAlt(_localctx, 2);
        setState(318);
        match(DecafParser::T__22);
        dynamic_cast<Arith_low_opContext *>(_localctx)->op =  Operator::MINUS;
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
  enterRule(_localctx, 34, DecafParser::RuleRel_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(330);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__27: {
        enterOuterAlt(_localctx, 1);
        setState(322);
        match(DecafParser::T__27);
        dynamic_cast<Rel_opContext *>(_localctx)->op =  Operator::LESS;
        break;
      }

      case DecafParser::T__28: {
        enterOuterAlt(_localctx, 2);
        setState(324);
        match(DecafParser::T__28);
        dynamic_cast<Rel_opContext *>(_localctx)->op =  Operator::LESS_EQ;
        break;
      }

      case DecafParser::T__29: {
        enterOuterAlt(_localctx, 3);
        setState(326);
        match(DecafParser::T__29);
        dynamic_cast<Rel_opContext *>(_localctx)->op =  Operator::GREATER; 
        break;
      }

      case DecafParser::T__30: {
        enterOuterAlt(_localctx, 4);
        setState(328);
        match(DecafParser::T__30);
        dynamic_cast<Rel_opContext *>(_localctx)->op =  Operator::GREATER_EQ;
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
  enterRule(_localctx, 36, DecafParser::RuleEq_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(336);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::T__31: {
        enterOuterAlt(_localctx, 1);
        setState(332);
        match(DecafParser::T__31);
        dynamic_cast<Eq_opContext *>(_localctx)->op =  Operator::EQ;
        break;
      }

      case DecafParser::T__32: {
        enterOuterAlt(_localctx, 2);
        setState(334);
        match(DecafParser::T__32);
        dynamic_cast<Eq_opContext *>(_localctx)->op =  Operator::NOT_EQ;
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

//----------------- And_opContext ------------------------------------------------------------------

DecafParser::And_opContext::And_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::And_opContext::getRuleIndex() const {
  return DecafParser::RuleAnd_op;
}

void DecafParser::And_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd_op(this);
}

void DecafParser::And_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd_op(this);
}


antlrcpp::Any DecafParser::And_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitAnd_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::And_opContext* DecafParser::and_op() {
  And_opContext *_localctx = _tracker.createInstance<And_opContext>(_ctx, getState());
  enterRule(_localctx, 38, DecafParser::RuleAnd_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    match(DecafParser::T__33);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Or_opContext ------------------------------------------------------------------

DecafParser::Or_opContext::Or_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Or_opContext::getRuleIndex() const {
  return DecafParser::RuleOr_op;
}

void DecafParser::Or_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOr_op(this);
}

void DecafParser::Or_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOr_op(this);
}


antlrcpp::Any DecafParser::Or_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitOr_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Or_opContext* DecafParser::or_op() {
  Or_opContext *_localctx = _tracker.createInstance<Or_opContext>(_ctx, getState());
  enterRule(_localctx, 40, DecafParser::RuleOr_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
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


size_t DecafParser::LiteralContext::getRuleIndex() const {
  return DecafParser::RuleLiteral;
}

void DecafParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->d_type = ctx->d_type;
  this->addr = ctx->addr;
}

//----------------- IntLiteralContext ------------------------------------------------------------------

DecafParser::Int_literalContext* DecafParser::IntLiteralContext::int_literal() {
  return getRuleContext<DecafParser::Int_literalContext>(0);
}

DecafParser::IntLiteralContext::IntLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void DecafParser::IntLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntLiteral(this);
}
void DecafParser::IntLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntLiteral(this);
}

antlrcpp::Any DecafParser::IntLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitIntLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharLiteralContext ------------------------------------------------------------------

DecafParser::Char_literalContext* DecafParser::CharLiteralContext::char_literal() {
  return getRuleContext<DecafParser::Char_literalContext>(0);
}

DecafParser::CharLiteralContext::CharLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void DecafParser::CharLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharLiteral(this);
}
void DecafParser::CharLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharLiteral(this);
}

antlrcpp::Any DecafParser::CharLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitCharLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolLiteralContext ------------------------------------------------------------------

DecafParser::Bool_literalContext* DecafParser::BoolLiteralContext::bool_literal() {
  return getRuleContext<DecafParser::Bool_literalContext>(0);
}

DecafParser::BoolLiteralContext::BoolLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void DecafParser::BoolLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolLiteral(this);
}
void DecafParser::BoolLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolLiteral(this);
}

antlrcpp::Any DecafParser::BoolLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitBoolLiteral(this);
  else
    return visitor->visitChildren(this);
}
DecafParser::LiteralContext* DecafParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 42, DecafParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(351);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::NUM: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<DecafParser::IntLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(342);
        int_literal();
        dynamic_cast<IntLiteralContext *>(_localctx)->d_type =  "int";
        break;
      }

      case DecafParser::CHAR: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<DecafParser::CharLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(345);
        char_literal();
        dynamic_cast<CharLiteralContext *>(_localctx)->d_type =  "char";
        break;
      }

      case DecafParser::T__35:
      case DecafParser::T__36: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<DecafParser::BoolLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(348);
        bool_literal();
        dynamic_cast<BoolLiteralContext *>(_localctx)->d_type =  "boolean";
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
  enterRule(_localctx, 44, DecafParser::RuleInt_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
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
  enterRule(_localctx, 46, DecafParser::RuleChar_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
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
  enterRule(_localctx, 48, DecafParser::RuleBool_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
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
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

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
  "statement", "location", "expression", "methodCall", "arg", "arith_high_op", 
  "arith_low_op", "rel_op", "eq_op", "and_op", "or_op", "literal", "int_literal", 
  "char_literal", "bool_literal"
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
    0x3, 0x2b, 0x16a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x39, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x3c, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x43, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x52, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x7, 0x5, 0x59, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5c, 0xb, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x6f, 0xa, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x77, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x7a, 0xb, 0x7, 0x5, 0x7, 0x7c, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x8b, 0xa, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x96, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x9e, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x7, 0xb, 0xa2, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xa5, 0xb, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xaa, 0xa, 0xb, 0xc, 0xb, 
    0xe, 0xb, 0xad, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb9, 
    0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xc6, 0xa, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xd3, 0xa, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0xd6, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xdf, 0xa, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xe7, 0xa, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x100, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x7, 0xe, 0x120, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x123, 0xb, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x12a, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0x12d, 0xb, 0xf, 0x5, 0xf, 0x12f, 0xa, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x13d, 
    0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x143, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x14d, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x153, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0x162, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x2, 0x3, 0x1a, 0x1b, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x2, 0x3, 0x3, 0x2, 
    0x26, 0x27, 0x2, 0x185, 0x2, 0x34, 0x3, 0x2, 0x2, 0x2, 0x4, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x51, 0x3, 0x2, 0x2, 0x2, 0x8, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x6e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x70, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x8a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x95, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x16, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0xde, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xff, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x124, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x133, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x22, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x26, 0x152, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x154, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x156, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x161, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x163, 0x3, 0x2, 0x2, 0x2, 0x30, 0x165, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x167, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 0x3, 
    0x2, 0x2, 0x35, 0x36, 0x7, 0x4, 0x2, 0x2, 0x36, 0x3a, 0x7, 0x5, 0x2, 
    0x2, 0x37, 0x39, 0x5, 0x4, 0x3, 0x2, 0x38, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x6, 0x2, 0x2, 0x3e, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x43, 0x5, 0x8, 0x5, 0x2, 0x40, 0x43, 0x5, 0x6, 
    0x4, 0x2, 0x41, 0x43, 0x5, 0xc, 0x7, 0x2, 0x42, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x5, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x5, 0xa, 0x6, 0x2, 0x45, 
    0x46, 0x7, 0x28, 0x2, 0x2, 0x46, 0x47, 0x7, 0x7, 0x2, 0x2, 0x47, 0x48, 
    0x8, 0x4, 0x1, 0x2, 0x48, 0x52, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x5, 
    0xa, 0x6, 0x2, 0x4a, 0x4b, 0x7, 0x28, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x8, 
    0x2, 0x2, 0x4c, 0x4d, 0x7, 0x29, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x9, 0x2, 
    0x2, 0x4e, 0x4f, 0x7, 0x7, 0x2, 0x2, 0x4f, 0x50, 0x8, 0x4, 0x1, 0x2, 
    0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 0x44, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x52, 0x7, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 
    0x7, 0xa, 0x2, 0x2, 0x54, 0x55, 0x7, 0x28, 0x2, 0x2, 0x55, 0x56, 0x8, 
    0x5, 0x1, 0x2, 0x56, 0x5a, 0x7, 0x5, 0x2, 0x2, 0x57, 0x59, 0x5, 0x6, 
    0x4, 0x2, 0x58, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 
    0x5e, 0x7, 0x6, 0x2, 0x2, 0x5e, 0x5f, 0x8, 0x5, 0x1, 0x2, 0x5f, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0xb, 0x2, 0x2, 0x61, 0x6f, 0x8, 
    0x6, 0x1, 0x2, 0x62, 0x63, 0x7, 0xc, 0x2, 0x2, 0x63, 0x6f, 0x8, 0x6, 
    0x1, 0x2, 0x64, 0x65, 0x7, 0xd, 0x2, 0x2, 0x65, 0x6f, 0x8, 0x6, 0x1, 
    0x2, 0x66, 0x67, 0x7, 0xa, 0x2, 0x2, 0x67, 0x68, 0x7, 0x28, 0x2, 0x2, 
    0x68, 0x6f, 0x8, 0x6, 0x1, 0x2, 0x69, 0x6a, 0x5, 0x8, 0x5, 0x2, 0x6a, 
    0x6b, 0x8, 0x6, 0x1, 0x2, 0x6b, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 
    0x7, 0xe, 0x2, 0x2, 0x6d, 0x6f, 0x8, 0x6, 0x1, 0x2, 0x6e, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x62, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x71, 0x5, 0xe, 0x8, 0x2, 0x71, 0x72, 0x7, 0x28, 0x2, 0x2, 0x72, 
    0x7b, 0x7, 0xf, 0x2, 0x2, 0x73, 0x78, 0x5, 0x10, 0x9, 0x2, 0x74, 0x75, 
    0x7, 0x10, 0x2, 0x2, 0x75, 0x77, 0x5, 0x10, 0x9, 0x2, 0x76, 0x74, 0x3, 
    0x2, 0x2, 0x2, 0x77, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7c, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 
    0x7e, 0x7, 0x11, 0x2, 0x2, 0x7e, 0x7f, 0x8, 0x7, 0x1, 0x2, 0x7f, 0x80, 
    0x5, 0x14, 0xb, 0x2, 0x80, 0x81, 0x8, 0x7, 0x1, 0x2, 0x81, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0xb, 0x2, 0x2, 0x83, 0x8b, 0x8, 0x8, 
    0x1, 0x2, 0x84, 0x85, 0x7, 0xc, 0x2, 0x2, 0x85, 0x8b, 0x8, 0x8, 0x1, 
    0x2, 0x86, 0x87, 0x7, 0xd, 0x2, 0x2, 0x87, 0x8b, 0x8, 0x8, 0x1, 0x2, 
    0x88, 0x89, 0x7, 0xe, 0x2, 0x2, 0x89, 0x8b, 0x8, 0x8, 0x1, 0x2, 0x8a, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x12, 0xa, 0x2, 0x8d, 0x8e, 0x7, 0x28, 
    0x2, 0x2, 0x8e, 0x8f, 0x8, 0x9, 0x1, 0x2, 0x8f, 0x96, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x91, 0x5, 0x12, 0xa, 0x2, 0x91, 0x92, 0x7, 0x28, 0x2, 0x2, 
    0x92, 0x93, 0x7, 0x8, 0x2, 0x2, 0x93, 0x94, 0x7, 0x9, 0x2, 0x2, 0x94, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x95, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x95, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x96, 0x11, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x7, 
    0xb, 0x2, 0x2, 0x98, 0x9e, 0x8, 0xa, 0x1, 0x2, 0x99, 0x9a, 0x7, 0xc, 
    0x2, 0x2, 0x9a, 0x9e, 0x8, 0xa, 0x1, 0x2, 0x9b, 0x9c, 0x7, 0xd, 0x2, 
    0x2, 0x9c, 0x9e, 0x8, 0xa, 0x1, 0x2, 0x9d, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa3, 0x7, 0x5, 0x2, 0x2, 0xa0, 0xa2, 
    0x5, 0x6, 0x4, 0x2, 0xa1, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa6, 0xa7, 0x5, 0x16, 0xc, 0x2, 0xa7, 0xa8, 0x8, 0xb, 0x1, 0x2, 
    0xa8, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0xae, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x6, 0x2, 0x2, 0xaf, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0xb1, 0x7, 0x12, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0xf, 0x2, 
    0x2, 0xb2, 0xb3, 0x5, 0x1a, 0xe, 0x2, 0xb3, 0xb4, 0x8, 0xc, 0x1, 0x2, 
    0xb4, 0xb5, 0x7, 0x11, 0x2, 0x2, 0xb5, 0xb8, 0x5, 0x14, 0xb, 0x2, 0xb6, 
    0xb7, 0x7, 0x13, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x14, 0xb, 0x2, 0xb8, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xd6, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x14, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0xf, 
    0x2, 0x2, 0xbc, 0xbd, 0x5, 0x1a, 0xe, 0x2, 0xbd, 0xbe, 0x8, 0xc, 0x1, 
    0x2, 0xbe, 0xbf, 0x7, 0x11, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x14, 0xb, 0x2, 
    0xc0, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc5, 0x7, 0x15, 0x2, 0x2, 0xc2, 
    0xc3, 0x5, 0x1a, 0xe, 0x2, 0xc3, 0xc4, 0x8, 0xc, 0x1, 0x2, 0xc4, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc5, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xd6, 0x7, 0x7, 
    0x2, 0x2, 0xc8, 0xc9, 0x5, 0x1c, 0xf, 0x2, 0xc9, 0xca, 0x7, 0x7, 0x2, 
    0x2, 0xca, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xd6, 0x5, 0x14, 0xb, 0x2, 
    0xcc, 0xcd, 0x5, 0x18, 0xd, 0x2, 0xcd, 0xce, 0x7, 0x16, 0x2, 0x2, 0xce, 
    0xcf, 0x5, 0x1a, 0xe, 0x2, 0xcf, 0xd0, 0x8, 0xc, 0x1, 0x2, 0xd0, 0xd6, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x1a, 0xe, 0x2, 0xd2, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xd6, 0x7, 0x7, 0x2, 0x2, 0xd5, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xba, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xd5, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xdf, 0x7, 0x28, 0x2, 0x2, 0xd8, 0xd9, 0x7, 
    0x28, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x8, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x1a, 
    0xe, 0x2, 0xdb, 0xdc, 0x7, 0x9, 0x2, 0x2, 0xdc, 0xdd, 0x8, 0xd, 0x1, 
    0x2, 0xdd, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xd7, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xe6, 0x8, 0xd, 0x1, 0x2, 0xe1, 0xe2, 0x7, 0x17, 0x2, 0x2, 0xe2, 0xe3, 
    0x8, 0xd, 0x1, 0x2, 0xe3, 0xe4, 0x5, 0x18, 0xd, 0x2, 0xe4, 0xe5, 0x8, 
    0xd, 0x1, 0x2, 0xe5, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe9, 0x8, 0xe, 0x1, 0x2, 0xe9, 0xea, 0x7, 0xf, 0x2, 0x2, 
    0xea, 0xeb, 0x5, 0x1a, 0xe, 0x2, 0xeb, 0xec, 0x7, 0x11, 0x2, 0x2, 0xec, 
    0xed, 0x8, 0xe, 0x1, 0x2, 0xed, 0x100, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 
    0x5, 0x2c, 0x17, 0x2, 0xef, 0xf0, 0x8, 0xe, 0x1, 0x2, 0xf0, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xf2, 0x5, 0x1c, 0xf, 0x2, 0xf2, 0xf3, 0x8, 0xe, 
    0x1, 0x2, 0xf3, 0x100, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x18, 0xd, 
    0x2, 0xf5, 0xf6, 0x8, 0xe, 0x1, 0x2, 0xf6, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf8, 0x7, 0x18, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x1a, 0xe, 0xa, 0xf9, 
    0xfa, 0x8, 0xe, 0x1, 0x2, 0xfa, 0x100, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 
    0x7, 0x19, 0x2, 0x2, 0xfc, 0xfd, 0x5, 0x1a, 0xe, 0x9, 0xfd, 0xfe, 0x8, 
    0xe, 0x1, 0x2, 0xfe, 0x100, 0x3, 0x2, 0x2, 0x2, 0xff, 0xe8, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0xee, 0x3, 0x2, 0x2, 0x2, 0xff, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0xff, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xff, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x100, 0x121, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x102, 0xc, 0x8, 0x2, 0x2, 0x102, 0x103, 0x5, 0x20, 0x11, 0x2, 0x103, 
    0x104, 0x5, 0x1a, 0xe, 0x9, 0x104, 0x105, 0x8, 0xe, 0x1, 0x2, 0x105, 
    0x120, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0xc, 0x7, 0x2, 0x2, 0x107, 
    0x108, 0x5, 0x22, 0x12, 0x2, 0x108, 0x109, 0x5, 0x1a, 0xe, 0x8, 0x109, 
    0x10a, 0x8, 0xe, 0x1, 0x2, 0x10a, 0x120, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0x10c, 0xc, 0x6, 0x2, 0x2, 0x10c, 0x10d, 0x5, 0x24, 0x13, 0x2, 0x10d, 
    0x10e, 0x5, 0x1a, 0xe, 0x7, 0x10e, 0x10f, 0x8, 0xe, 0x1, 0x2, 0x10f, 
    0x120, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0xc, 0x5, 0x2, 0x2, 0x111, 
    0x112, 0x5, 0x26, 0x14, 0x2, 0x112, 0x113, 0x5, 0x1a, 0xe, 0x6, 0x113, 
    0x114, 0x8, 0xe, 0x1, 0x2, 0x114, 0x120, 0x3, 0x2, 0x2, 0x2, 0x115, 
    0x116, 0xc, 0x4, 0x2, 0x2, 0x116, 0x117, 0x5, 0x28, 0x15, 0x2, 0x117, 
    0x118, 0x5, 0x1a, 0xe, 0x5, 0x118, 0x119, 0x8, 0xe, 0x1, 0x2, 0x119, 
    0x120, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0xc, 0x3, 0x2, 0x2, 0x11b, 
    0x11c, 0x5, 0x2a, 0x16, 0x2, 0x11c, 0x11d, 0x5, 0x1a, 0xe, 0x4, 0x11d, 
    0x11e, 0x8, 0xe, 0x1, 0x2, 0x11e, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x101, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x106, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x120, 
    0x123, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x7, 0x28, 0x2, 0x2, 0x125, 0x12e, 
    0x7, 0xf, 0x2, 0x2, 0x126, 0x12b, 0x5, 0x1e, 0x10, 0x2, 0x127, 0x128, 
    0x7, 0x10, 0x2, 0x2, 0x128, 0x12a, 0x5, 0x1e, 0x10, 0x2, 0x129, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x126, 
    0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x7, 0x11, 0x2, 0x2, 0x131, 0x132, 
    0x8, 0xf, 0x1, 0x2, 0x132, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x5, 
    0x1a, 0xe, 0x2, 0x134, 0x135, 0x8, 0x10, 0x1, 0x2, 0x135, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0x1a, 0x2, 0x2, 0x137, 0x13d, 0x8, 
    0x11, 0x1, 0x2, 0x138, 0x139, 0x7, 0x1b, 0x2, 0x2, 0x139, 0x13d, 0x8, 
    0x11, 0x1, 0x2, 0x13a, 0x13b, 0x7, 0x1c, 0x2, 0x2, 0x13b, 0x13d, 0x8, 
    0x11, 0x1, 0x2, 0x13c, 0x136, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x138, 0x3, 
    0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x13e, 0x13f, 0x7, 0x1d, 0x2, 0x2, 0x13f, 0x143, 0x8, 0x12, 
    0x1, 0x2, 0x140, 0x141, 0x7, 0x19, 0x2, 0x2, 0x141, 0x143, 0x8, 0x12, 
    0x1, 0x2, 0x142, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 
    0x2, 0x2, 0x143, 0x23, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x7, 0x1e, 
    0x2, 0x2, 0x145, 0x14d, 0x8, 0x13, 0x1, 0x2, 0x146, 0x147, 0x7, 0x1f, 
    0x2, 0x2, 0x147, 0x14d, 0x8, 0x13, 0x1, 0x2, 0x148, 0x149, 0x7, 0x20, 
    0x2, 0x2, 0x149, 0x14d, 0x8, 0x13, 0x1, 0x2, 0x14a, 0x14b, 0x7, 0x21, 
    0x2, 0x2, 0x14b, 0x14d, 0x8, 0x13, 0x1, 0x2, 0x14c, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x146, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x148, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x14f, 0x7, 0x22, 0x2, 0x2, 0x14f, 0x153, 0x8, 0x14, 0x1, 
    0x2, 0x150, 0x151, 0x7, 0x23, 0x2, 0x2, 0x151, 0x153, 0x8, 0x14, 0x1, 
    0x2, 0x152, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 
    0x2, 0x153, 0x27, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x7, 0x24, 0x2, 
    0x2, 0x155, 0x29, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x7, 0x25, 0x2, 
    0x2, 0x157, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x5, 0x2e, 0x18, 
    0x2, 0x159, 0x15a, 0x8, 0x17, 0x1, 0x2, 0x15a, 0x162, 0x3, 0x2, 0x2, 
    0x2, 0x15b, 0x15c, 0x5, 0x30, 0x19, 0x2, 0x15c, 0x15d, 0x8, 0x17, 0x1, 
    0x2, 0x15d, 0x162, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x5, 0x32, 0x1a, 
    0x2, 0x15f, 0x160, 0x8, 0x17, 0x1, 0x2, 0x160, 0x162, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x158, 0x3, 0x2, 0x2, 0x2, 0x161, 0x15b, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x162, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x164, 0x7, 0x29, 0x2, 0x2, 0x164, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x165, 0x166, 0x7, 0x2a, 0x2, 0x2, 0x166, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x167, 0x168, 0x9, 0x2, 0x2, 0x2, 0x168, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x3a, 0x42, 0x51, 0x5a, 0x6e, 0x78, 0x7b, 0x8a, 0x95, 0x9d, 0xa3, 0xab, 
    0xb8, 0xc5, 0xd2, 0xd5, 0xde, 0xe6, 0xff, 0x11f, 0x121, 0x12b, 0x12e, 
    0x13c, 0x142, 0x14c, 0x152, 0x161, 
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
