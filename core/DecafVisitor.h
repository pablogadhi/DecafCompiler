
// Generated from /home/gadhi/Documents/Compis/Decaf/Decaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "DecafParser.h"


namespace decafcore {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by DecafParser.
 */
class  DecafVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DecafParser.
   */
    virtual antlrcpp::Any visitProgram(DecafParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(DecafParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVarDeclaration(DecafParser::VarDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaration(DecafParser::StructDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVarType(DecafParser::VarTypeContext *context) = 0;

    virtual antlrcpp::Any visitMethodDeclaration(DecafParser::MethodDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitMethodType(DecafParser::MethodTypeContext *context) = 0;

    virtual antlrcpp::Any visitParameter(DecafParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitParameterType(DecafParser::ParameterTypeContext *context) = 0;

    virtual antlrcpp::Any visitBlock(DecafParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(DecafParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(DecafParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(DecafParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitMethodCallStatement(DecafParser::MethodCallStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockStatement(DecafParser::BlockStatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignStatement(DecafParser::AssignStatementContext *context) = 0;

    virtual antlrcpp::Any visitExprStatement(DecafParser::ExprStatementContext *context) = 0;

    virtual antlrcpp::Any visitLocation(DecafParser::LocationContext *context) = 0;

    virtual antlrcpp::Any visitParensExpr(DecafParser::ParensExprContext *context) = 0;

    virtual antlrcpp::Any visitAritExpr(DecafParser::AritExprContext *context) = 0;

    virtual antlrcpp::Any visitBooleanExpr(DecafParser::BooleanExprContext *context) = 0;

    virtual antlrcpp::Any visitAritLowExpr(DecafParser::AritLowExprContext *context) = 0;

    virtual antlrcpp::Any visitAritHighExpr(DecafParser::AritHighExprContext *context) = 0;

    virtual antlrcpp::Any visitMinusExpr(DecafParser::MinusExprContext *context) = 0;

    virtual antlrcpp::Any visitOrExpr(DecafParser::OrExprContext *context) = 0;

    virtual antlrcpp::Any visitAndExpr(DecafParser::AndExprContext *context) = 0;

    virtual antlrcpp::Any visitEqExpr(DecafParser::EqExprContext *context) = 0;

    virtual antlrcpp::Any visitRelExpr(DecafParser::RelExprContext *context) = 0;

    virtual antlrcpp::Any visitNotExpr(DecafParser::NotExprContext *context) = 0;

    virtual antlrcpp::Any visitLiteralExpr(DecafParser::LiteralExprContext *context) = 0;

    virtual antlrcpp::Any visitMethodCallExpr(DecafParser::MethodCallExprContext *context) = 0;

    virtual antlrcpp::Any visitLocationExpr(DecafParser::LocationExprContext *context) = 0;

    virtual antlrcpp::Any visitMethodCall(DecafParser::MethodCallContext *context) = 0;

    virtual antlrcpp::Any visitArg(DecafParser::ArgContext *context) = 0;

    virtual antlrcpp::Any visitArith_high_op(DecafParser::Arith_high_opContext *context) = 0;

    virtual antlrcpp::Any visitArith_low_op(DecafParser::Arith_low_opContext *context) = 0;

    virtual antlrcpp::Any visitRel_op(DecafParser::Rel_opContext *context) = 0;

    virtual antlrcpp::Any visitEq_op(DecafParser::Eq_opContext *context) = 0;

    virtual antlrcpp::Any visitAnd_op(DecafParser::And_opContext *context) = 0;

    virtual antlrcpp::Any visitOr_op(DecafParser::Or_opContext *context) = 0;

    virtual antlrcpp::Any visitIntLiteral(DecafParser::IntLiteralContext *context) = 0;

    virtual antlrcpp::Any visitCharLiteral(DecafParser::CharLiteralContext *context) = 0;

    virtual antlrcpp::Any visitBoolLiteral(DecafParser::BoolLiteralContext *context) = 0;

    virtual antlrcpp::Any visitInt_literal(DecafParser::Int_literalContext *context) = 0;

    virtual antlrcpp::Any visitChar_literal(DecafParser::Char_literalContext *context) = 0;

    virtual antlrcpp::Any visitBool_literal(DecafParser::Bool_literalContext *context) = 0;


};

}  // namespace decafcore
