
// Generated from /home/gadhi/Documents/Compis/Decaf/Decaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "DecafListener.h"


namespace decafcore {

/**
 * This class provides an empty implementation of DecafListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DecafBaseListener : public DecafListener {
public:

  virtual void enterProgram(DecafParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(DecafParser::ProgramContext * /*ctx*/) override { }

  virtual void enterDeclaration(DecafParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(DecafParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterVarDeclaration(DecafParser::VarDeclarationContext * /*ctx*/) override { }
  virtual void exitVarDeclaration(DecafParser::VarDeclarationContext * /*ctx*/) override { }

  virtual void enterStructDeclaration(DecafParser::StructDeclarationContext * /*ctx*/) override { }
  virtual void exitStructDeclaration(DecafParser::StructDeclarationContext * /*ctx*/) override { }

  virtual void enterVarType(DecafParser::VarTypeContext * /*ctx*/) override { }
  virtual void exitVarType(DecafParser::VarTypeContext * /*ctx*/) override { }

  virtual void enterMethodDeclaration(DecafParser::MethodDeclarationContext * /*ctx*/) override { }
  virtual void exitMethodDeclaration(DecafParser::MethodDeclarationContext * /*ctx*/) override { }

  virtual void enterMethodType(DecafParser::MethodTypeContext * /*ctx*/) override { }
  virtual void exitMethodType(DecafParser::MethodTypeContext * /*ctx*/) override { }

  virtual void enterParameter(DecafParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(DecafParser::ParameterContext * /*ctx*/) override { }

  virtual void enterParameterType(DecafParser::ParameterTypeContext * /*ctx*/) override { }
  virtual void exitParameterType(DecafParser::ParameterTypeContext * /*ctx*/) override { }

  virtual void enterBlock(DecafParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(DecafParser::BlockContext * /*ctx*/) override { }

  virtual void enterIfStatement(DecafParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(DecafParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(DecafParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(DecafParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(DecafParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(DecafParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterMethodCallStatement(DecafParser::MethodCallStatementContext * /*ctx*/) override { }
  virtual void exitMethodCallStatement(DecafParser::MethodCallStatementContext * /*ctx*/) override { }

  virtual void enterBlockStatement(DecafParser::BlockStatementContext * /*ctx*/) override { }
  virtual void exitBlockStatement(DecafParser::BlockStatementContext * /*ctx*/) override { }

  virtual void enterAssignStatement(DecafParser::AssignStatementContext * /*ctx*/) override { }
  virtual void exitAssignStatement(DecafParser::AssignStatementContext * /*ctx*/) override { }

  virtual void enterExprStatement(DecafParser::ExprStatementContext * /*ctx*/) override { }
  virtual void exitExprStatement(DecafParser::ExprStatementContext * /*ctx*/) override { }

  virtual void enterLocation(DecafParser::LocationContext * /*ctx*/) override { }
  virtual void exitLocation(DecafParser::LocationContext * /*ctx*/) override { }

  virtual void enterParensExpr(DecafParser::ParensExprContext * /*ctx*/) override { }
  virtual void exitParensExpr(DecafParser::ParensExprContext * /*ctx*/) override { }

  virtual void enterBooleanExpr(DecafParser::BooleanExprContext * /*ctx*/) override { }
  virtual void exitBooleanExpr(DecafParser::BooleanExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(DecafParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(DecafParser::OrExprContext * /*ctx*/) override { }

  virtual void enterAndExpr(DecafParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(DecafParser::AndExprContext * /*ctx*/) override { }

  virtual void enterEqExpr(DecafParser::EqExprContext * /*ctx*/) override { }
  virtual void exitEqExpr(DecafParser::EqExprContext * /*ctx*/) override { }

  virtual void enterRelExpr(DecafParser::RelExprContext * /*ctx*/) override { }
  virtual void exitRelExpr(DecafParser::RelExprContext * /*ctx*/) override { }

  virtual void enterAritLowExpr(DecafParser::AritLowExprContext * /*ctx*/) override { }
  virtual void exitAritLowExpr(DecafParser::AritLowExprContext * /*ctx*/) override { }

  virtual void enterAritHighExpr(DecafParser::AritHighExprContext * /*ctx*/) override { }
  virtual void exitAritHighExpr(DecafParser::AritHighExprContext * /*ctx*/) override { }

  virtual void enterMinusExpr(DecafParser::MinusExprContext * /*ctx*/) override { }
  virtual void exitMinusExpr(DecafParser::MinusExprContext * /*ctx*/) override { }

  virtual void enterNotExpr(DecafParser::NotExprContext * /*ctx*/) override { }
  virtual void exitNotExpr(DecafParser::NotExprContext * /*ctx*/) override { }

  virtual void enterLiteralExpr(DecafParser::LiteralExprContext * /*ctx*/) override { }
  virtual void exitLiteralExpr(DecafParser::LiteralExprContext * /*ctx*/) override { }

  virtual void enterMethodCallExpr(DecafParser::MethodCallExprContext * /*ctx*/) override { }
  virtual void exitMethodCallExpr(DecafParser::MethodCallExprContext * /*ctx*/) override { }

  virtual void enterLocationExpr(DecafParser::LocationExprContext * /*ctx*/) override { }
  virtual void exitLocationExpr(DecafParser::LocationExprContext * /*ctx*/) override { }

  virtual void enterMethodCall(DecafParser::MethodCallContext * /*ctx*/) override { }
  virtual void exitMethodCall(DecafParser::MethodCallContext * /*ctx*/) override { }

  virtual void enterArg(DecafParser::ArgContext * /*ctx*/) override { }
  virtual void exitArg(DecafParser::ArgContext * /*ctx*/) override { }

  virtual void enterArith_high_op(DecafParser::Arith_high_opContext * /*ctx*/) override { }
  virtual void exitArith_high_op(DecafParser::Arith_high_opContext * /*ctx*/) override { }

  virtual void enterArith_low_op(DecafParser::Arith_low_opContext * /*ctx*/) override { }
  virtual void exitArith_low_op(DecafParser::Arith_low_opContext * /*ctx*/) override { }

  virtual void enterRel_op(DecafParser::Rel_opContext * /*ctx*/) override { }
  virtual void exitRel_op(DecafParser::Rel_opContext * /*ctx*/) override { }

  virtual void enterEq_op(DecafParser::Eq_opContext * /*ctx*/) override { }
  virtual void exitEq_op(DecafParser::Eq_opContext * /*ctx*/) override { }

  virtual void enterAnd_op(DecafParser::And_opContext * /*ctx*/) override { }
  virtual void exitAnd_op(DecafParser::And_opContext * /*ctx*/) override { }

  virtual void enterOr_op(DecafParser::Or_opContext * /*ctx*/) override { }
  virtual void exitOr_op(DecafParser::Or_opContext * /*ctx*/) override { }

  virtual void enterIntLiteral(DecafParser::IntLiteralContext * /*ctx*/) override { }
  virtual void exitIntLiteral(DecafParser::IntLiteralContext * /*ctx*/) override { }

  virtual void enterCharLiteral(DecafParser::CharLiteralContext * /*ctx*/) override { }
  virtual void exitCharLiteral(DecafParser::CharLiteralContext * /*ctx*/) override { }

  virtual void enterBoolLiteral(DecafParser::BoolLiteralContext * /*ctx*/) override { }
  virtual void exitBoolLiteral(DecafParser::BoolLiteralContext * /*ctx*/) override { }

  virtual void enterInt_literal(DecafParser::Int_literalContext * /*ctx*/) override { }
  virtual void exitInt_literal(DecafParser::Int_literalContext * /*ctx*/) override { }

  virtual void enterChar_literal(DecafParser::Char_literalContext * /*ctx*/) override { }
  virtual void exitChar_literal(DecafParser::Char_literalContext * /*ctx*/) override { }

  virtual void enterBool_literal(DecafParser::Bool_literalContext * /*ctx*/) override { }
  virtual void exitBool_literal(DecafParser::Bool_literalContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace decafcore
