#ifndef INTER_CODE_H
#define INTER_CODE_H

#include "core/DecafBaseVisitor.h"

using namespace decafcore;
using namespace antlrcpp;

class InterCodeVisitor : public DecafBaseVisitor {
private:
  TACode ta_code;
  bool control_flow = false;

public:
  TACode &intermediate_code();

  Any visitProgram(DecafParser::ProgramContext *ctx);

  Any visitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx);

  Any visitBlock(DecafParser::BlockContext *ctx);

  Any visitIfStatement(DecafParser::IfStatementContext *ctx);
  Any visitWhileStatement(DecafParser::WhileStatementContext *ctx);
  Any visitReturnStatement(DecafParser::ReturnStatementContext *ctx);
  Any visitAssignStatement(DecafParser::AssignStatementContext *ctx);

  Any visitLocation(DecafParser::LocationContext *ctx);

  Any visitParensExpr(DecafParser::ParensExprContext *ctx);
  // Any visitAritExpr(DecafParser::AritExprContext *ctx);
  Any visitBooleanExpr(DecafParser::BooleanExprContext *ctx);

  Any visitLiteralExpr(DecafParser::LiteralExprContext *ctx);
  Any visitMethodCallExpr(DecafParser::MethodCallExprContext *ctx);
  Any visitLocationExpr(DecafParser::LocationExprContext *ctx);
  Any visitNotExpr(DecafParser::NotExprContext *ctx);
  Any visitMinusExpr(DecafParser::MinusExprContext *ctx);
  Any visitAritHighExpr(DecafParser::AritHighExprContext *ctx);
  Any visitAritLowExpr(DecafParser::AritLowExprContext *ctx);
  Any visitRelExpr(DecafParser::RelExprContext *ctx);
  Any visitEqExpr(DecafParser::EqExprContext *ctx);
  Any visitAndExpr(DecafParser::AndExprContext *ctx);
  Any visitOrExpr(DecafParser::OrExprContext *ctx);

  Any visitMethodCall(DecafParser::MethodCallContext *ctx);
  Any visitArg(DecafParser::ArgContext *ctx);

  Any visitIntLiteral(DecafParser::IntLiteralContext *ctx);
  Any visitCharLiteral(DecafParser::CharLiteralContext *ctx);
  Any visitBoolLiteral(DecafParser::BoolLiteralContext *ctx);
};

#endif