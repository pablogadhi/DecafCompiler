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

  Any visitIfStatement(DecafParser::IfStatementContext *ctx);
  // Any visitWhileStatement(DecafParser::WhileStatementContext *ctx);
  Any visitAssignStatement(DecafParser::AssignStatementContext *ctx);

  Any visitLocation(DecafParser::LocationContext *ctx);

  Any visitLiteralExpr(DecafParser::LiteralExprContext *ctx);
  // Any visitMethodCallExpr(DecafParser::MethodCallExprContext *ctx);
  Any visitLocationExpr(DecafParser::LocationExprContext *ctx);
  Any visitParensExpr(DecafParser::ParensExprContext *ctx);
  Any visitNotExpr(DecafParser::NotExprContext *ctx);
  Any visitMinusExpr(DecafParser::MinusExprContext *ctx);
  Any visitAritHighExpr(DecafParser::AritHighExprContext *ctx);
  Any visitAritLowExpr(DecafParser::AritLowExprContext *ctx);
  Any visitRelExpr(DecafParser::RelExprContext *ctx);
  Any visitEqExpr(DecafParser::EqExprContext *ctx);
  Any visitAndExpr(DecafParser::AndExprContext *ctx);
  Any visitOrExpr(DecafParser::OrExprContext *ctx);

  Any visitIntLiteral(DecafParser::IntLiteralContext *ctx);
  Any visitCharLiteral(DecafParser::CharLiteralContext *ctx);
  Any visitBoolLiteral(DecafParser::BoolLiteralContext *ctx);
};

#endif