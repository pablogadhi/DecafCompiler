
// Generated from Decaf.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "DecafVisitor.h"


namespace decafcore {

/**
 * This class provides an empty implementation of DecafVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DecafBaseVisitor : public DecafVisitor {
public:

  virtual antlrcpp::Any visitProgram(DecafParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(DecafParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDeclaration(DecafParser::VarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructDeclaration(DecafParser::StructDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarType(DecafParser::VarTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodType(DecafParser::MethodTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(DecafParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterType(DecafParser::ParameterTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(DecafParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(DecafParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocation(DecafParser::LocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(DecafParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodCall(DecafParser::MethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArg(DecafParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArith_op(DecafParser::Arith_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArith_high_precedence(DecafParser::Arith_high_precedenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArith_low_precedence(DecafParser::Arith_low_precedenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRel_op(DecafParser::Rel_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEq_op(DecafParser::Eq_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond_and(DecafParser::Cond_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond_or(DecafParser::Cond_orContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(DecafParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt_literal(DecafParser::Int_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChar_literal(DecafParser::Char_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_literal(DecafParser::Bool_literalContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace decafcore
