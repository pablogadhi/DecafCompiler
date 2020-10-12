
// Generated from /home/gadhi/Documents/Compis/Decaf/Decaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "DecafParser.h"


namespace decafcore {

/**
 * This interface defines an abstract listener for a parse tree produced by DecafParser.
 */
class  DecafListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(DecafParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(DecafParser::ProgramContext *ctx) = 0;

  virtual void enterDeclaration(DecafParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(DecafParser::DeclarationContext *ctx) = 0;

  virtual void enterVarDeclaration(DecafParser::VarDeclarationContext *ctx) = 0;
  virtual void exitVarDeclaration(DecafParser::VarDeclarationContext *ctx) = 0;

  virtual void enterStructDeclaration(DecafParser::StructDeclarationContext *ctx) = 0;
  virtual void exitStructDeclaration(DecafParser::StructDeclarationContext *ctx) = 0;

  virtual void enterVarType(DecafParser::VarTypeContext *ctx) = 0;
  virtual void exitVarType(DecafParser::VarTypeContext *ctx) = 0;

  virtual void enterMethodDeclaration(DecafParser::MethodDeclarationContext *ctx) = 0;
  virtual void exitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx) = 0;

  virtual void enterMethodType(DecafParser::MethodTypeContext *ctx) = 0;
  virtual void exitMethodType(DecafParser::MethodTypeContext *ctx) = 0;

  virtual void enterParameter(DecafParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(DecafParser::ParameterContext *ctx) = 0;

  virtual void enterParameterType(DecafParser::ParameterTypeContext *ctx) = 0;
  virtual void exitParameterType(DecafParser::ParameterTypeContext *ctx) = 0;

  virtual void enterBlock(DecafParser::BlockContext *ctx) = 0;
  virtual void exitBlock(DecafParser::BlockContext *ctx) = 0;

  virtual void enterIfStatement(DecafParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(DecafParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileStatement(DecafParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(DecafParser::WhileStatementContext *ctx) = 0;

  virtual void enterReturnStatement(DecafParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(DecafParser::ReturnStatementContext *ctx) = 0;

  virtual void enterMethodCallStatement(DecafParser::MethodCallStatementContext *ctx) = 0;
  virtual void exitMethodCallStatement(DecafParser::MethodCallStatementContext *ctx) = 0;

  virtual void enterBlockStatement(DecafParser::BlockStatementContext *ctx) = 0;
  virtual void exitBlockStatement(DecafParser::BlockStatementContext *ctx) = 0;

  virtual void enterAssignStatement(DecafParser::AssignStatementContext *ctx) = 0;
  virtual void exitAssignStatement(DecafParser::AssignStatementContext *ctx) = 0;

  virtual void enterExprStatement(DecafParser::ExprStatementContext *ctx) = 0;
  virtual void exitExprStatement(DecafParser::ExprStatementContext *ctx) = 0;

  virtual void enterLocation(DecafParser::LocationContext *ctx) = 0;
  virtual void exitLocation(DecafParser::LocationContext *ctx) = 0;

  virtual void enterMethodCallExpr(DecafParser::MethodCallExprContext *ctx) = 0;
  virtual void exitMethodCallExpr(DecafParser::MethodCallExprContext *ctx) = 0;

  virtual void enterEqExpr(DecafParser::EqExprContext *ctx) = 0;
  virtual void exitEqExpr(DecafParser::EqExprContext *ctx) = 0;

  virtual void enterNotExpr(DecafParser::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(DecafParser::NotExprContext *ctx) = 0;

  virtual void enterLocationExpr(DecafParser::LocationExprContext *ctx) = 0;
  virtual void exitLocationExpr(DecafParser::LocationExprContext *ctx) = 0;

  virtual void enterLiteralExpr(DecafParser::LiteralExprContext *ctx) = 0;
  virtual void exitLiteralExpr(DecafParser::LiteralExprContext *ctx) = 0;

  virtual void enterOrExpr(DecafParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(DecafParser::OrExprContext *ctx) = 0;

  virtual void enterAritHighExpr(DecafParser::AritHighExprContext *ctx) = 0;
  virtual void exitAritHighExpr(DecafParser::AritHighExprContext *ctx) = 0;

  virtual void enterAritLowExpr(DecafParser::AritLowExprContext *ctx) = 0;
  virtual void exitAritLowExpr(DecafParser::AritLowExprContext *ctx) = 0;

  virtual void enterParensExpr(DecafParser::ParensExprContext *ctx) = 0;
  virtual void exitParensExpr(DecafParser::ParensExprContext *ctx) = 0;

  virtual void enterRelExpr(DecafParser::RelExprContext *ctx) = 0;
  virtual void exitRelExpr(DecafParser::RelExprContext *ctx) = 0;

  virtual void enterMinusExpr(DecafParser::MinusExprContext *ctx) = 0;
  virtual void exitMinusExpr(DecafParser::MinusExprContext *ctx) = 0;

  virtual void enterAndExpr(DecafParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(DecafParser::AndExprContext *ctx) = 0;

  virtual void enterMethodCall(DecafParser::MethodCallContext *ctx) = 0;
  virtual void exitMethodCall(DecafParser::MethodCallContext *ctx) = 0;

  virtual void enterArg(DecafParser::ArgContext *ctx) = 0;
  virtual void exitArg(DecafParser::ArgContext *ctx) = 0;

  virtual void enterArith_high_op(DecafParser::Arith_high_opContext *ctx) = 0;
  virtual void exitArith_high_op(DecafParser::Arith_high_opContext *ctx) = 0;

  virtual void enterArith_low_op(DecafParser::Arith_low_opContext *ctx) = 0;
  virtual void exitArith_low_op(DecafParser::Arith_low_opContext *ctx) = 0;

  virtual void enterRel_op(DecafParser::Rel_opContext *ctx) = 0;
  virtual void exitRel_op(DecafParser::Rel_opContext *ctx) = 0;

  virtual void enterEq_op(DecafParser::Eq_opContext *ctx) = 0;
  virtual void exitEq_op(DecafParser::Eq_opContext *ctx) = 0;

  virtual void enterAnd_op(DecafParser::And_opContext *ctx) = 0;
  virtual void exitAnd_op(DecafParser::And_opContext *ctx) = 0;

  virtual void enterOr_op(DecafParser::Or_opContext *ctx) = 0;
  virtual void exitOr_op(DecafParser::Or_opContext *ctx) = 0;

  virtual void enterIntLiteral(DecafParser::IntLiteralContext *ctx) = 0;
  virtual void exitIntLiteral(DecafParser::IntLiteralContext *ctx) = 0;

  virtual void enterCharLiteral(DecafParser::CharLiteralContext *ctx) = 0;
  virtual void exitCharLiteral(DecafParser::CharLiteralContext *ctx) = 0;

  virtual void enterBoolLiteral(DecafParser::BoolLiteralContext *ctx) = 0;
  virtual void exitBoolLiteral(DecafParser::BoolLiteralContext *ctx) = 0;

  virtual void enterInt_literal(DecafParser::Int_literalContext *ctx) = 0;
  virtual void exitInt_literal(DecafParser::Int_literalContext *ctx) = 0;

  virtual void enterChar_literal(DecafParser::Char_literalContext *ctx) = 0;
  virtual void exitChar_literal(DecafParser::Char_literalContext *ctx) = 0;

  virtual void enterBool_literal(DecafParser::Bool_literalContext *ctx) = 0;
  virtual void exitBool_literal(DecafParser::Bool_literalContext *ctx) = 0;


};

}  // namespace decafcore
