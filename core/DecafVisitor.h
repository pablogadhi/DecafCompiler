
// Generated from Decaf.g4 by ANTLR 4.7.1

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

    virtual antlrcpp::Any visitStatement(DecafParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitLocation(DecafParser::LocationContext *context) = 0;

    virtual antlrcpp::Any visitExpression(DecafParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMethodCall(DecafParser::MethodCallContext *context) = 0;

    virtual antlrcpp::Any visitArg(DecafParser::ArgContext *context) = 0;

    virtual antlrcpp::Any visitArith_op(DecafParser::Arith_opContext *context) = 0;

    virtual antlrcpp::Any visitArith_high_precedence(DecafParser::Arith_high_precedenceContext *context) = 0;

    virtual antlrcpp::Any visitArith_low_precedence(DecafParser::Arith_low_precedenceContext *context) = 0;

    virtual antlrcpp::Any visitRel_op(DecafParser::Rel_opContext *context) = 0;

    virtual antlrcpp::Any visitEq_op(DecafParser::Eq_opContext *context) = 0;

    virtual antlrcpp::Any visitCond_and(DecafParser::Cond_andContext *context) = 0;

    virtual antlrcpp::Any visitCond_or(DecafParser::Cond_orContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(DecafParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitInt_literal(DecafParser::Int_literalContext *context) = 0;

    virtual antlrcpp::Any visitChar_literal(DecafParser::Char_literalContext *context) = 0;

    virtual antlrcpp::Any visitBool_literal(DecafParser::Bool_literalContext *context) = 0;


};

}  // namespace decafcore