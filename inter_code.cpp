#include "inter_code.h"

TACode &InterCodeVisitor::intermediate_code() { return ta_code; }

Any InterCodeVisitor::visitIfStatement(DecafParser::IfStatementContext *ctx) {
  int next_instr;
  int second_next_instr;

  control_flow = true;
  visit(ctx->expression());
  control_flow = false;

  next_instr = ta_code.next_instr();
  auto new_label = make_shared<Literal>("string", ta_code.new_label());
  ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(new_label));

  visit(ctx->true_block);

  ta_code.back_patch(ctx->expression()->true_list, next_instr);
  ctx->next_list =
      ta_code.merge(ctx->expression()->false_list, ctx->true_block->next_list);

  if (ctx->false_block != nullptr) {
    auto temp_next_list = ta_code.merge(
        ctx->true_block->next_list, ta_code.make_list(ta_code.next_instr()));
    second_next_instr = ta_code.next_instr();
    auto new_label = make_shared<Literal>("string", ta_code.new_label());
    ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(new_label));

    visit(ctx->false_block);

    ta_code.back_patch(ctx->expression()->false_list, second_next_instr);
    ctx->next_list = ta_code.merge(temp_next_list, ctx->false_block->next_list);
  }

  return nullptr;
}

Any InterCodeVisitor::visitAssignStatement(
    DecafParser::AssignStatementContext *ctx) {
  visitChildren(ctx);
  ta_code.gen(Operator::ASSIGN, ctx->location()->addr, ctx->expression()->addr);
  return nullptr;
}

Any InterCodeVisitor::visitLocation(DecafParser::LocationContext *ctx) {
  visitChildren(ctx);

  if (ctx->array_check) {
    auto size = make_shared<Literal>("int", to_string(4));
    ctx->addr = ta_code.gen(Operator::MUL, ctx->expression()->addr,
                            dynamic_pointer_cast<Address>(size));
  } else {
    ctx->addr = make_shared<Address>(ctx->out.offset());
  }

  if (ctx->child != nullptr) {
    ctx->addr = ctx->child->addr;
  }

  return nullptr;
}

Any InterCodeVisitor::visitLiteralExpr(DecafParser::LiteralExprContext *ctx) {
  visitChildren(ctx);
  ctx->addr = ctx->literal()->addr;

  if (control_flow && ctx->d_type == "boolean") {
    if (ctx->literal()->getText() == "true") {
      ctx->true_list = ta_code.make_list(ta_code.next_instr());
    } else {
      ctx->false_list = ta_code.make_list(ta_code.next_instr());
    }
    ta_code.gen(Operator::JUMP, nullptr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitLocationExpr(DecafParser::LocationExprContext *ctx) {
  visitChildren(ctx);
  ctx->addr = ctx->location()->addr;
  if (control_flow && ctx->d_type == "boolean") {
    // TODO handle locations
  }

  return nullptr;
}

Any InterCodeVisitor::visitParensExpr(DecafParser::ParensExprContext *ctx) {
  visitChildren(ctx);
  ctx->addr = ctx->expression()->addr;
  ctx->true_list = ctx->expression()->true_list;
  ctx->false_list = ctx->expression()->false_list;
  return nullptr;
}

Any InterCodeVisitor::visitNotExpr(DecafParser::NotExprContext *ctx) {
  visitChildren(ctx);
  if (control_flow) {
    ctx->true_list = ctx->expression()->false_list;
    ctx->false_list = ctx->expression()->true_list;
  } else {
    ctx->addr = ta_code.gen(Operator::NOT, ctx->expression()->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitMinusExpr(DecafParser::MinusExprContext *ctx) {
  visitChildren(ctx);
  ctx->addr = ta_code.gen(Operator::MINUS, ctx->expression()->addr);
  return nullptr;
}

Any InterCodeVisitor::visitAritHighExpr(DecafParser::AritHighExprContext *ctx) {
  visitChildren(ctx);
  ctx->addr =
      ta_code.gen(ctx->arith_high_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
  return nullptr;
}

Any InterCodeVisitor::visitAritLowExpr(DecafParser::AritLowExprContext *ctx) {
  visitChildren(ctx);
  ctx->addr =
      ta_code.gen(ctx->arith_low_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
  return nullptr;
}

Any InterCodeVisitor::visitRelExpr(DecafParser::RelExprContext *ctx) {
  visitChildren(ctx);

  if (control_flow) {
    auto label = make_shared<Literal>("string", ta_code.new_label());
    ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(label));
    auto comp =
        ta_code.gen(ctx->rel_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
    ta_code.gen(Operator::IF, comp);
    ctx->true_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
    ctx->false_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
  } else {
    ctx->addr =
        ta_code.gen(ctx->rel_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitEqExpr(DecafParser::EqExprContext *ctx) {
  visitChildren(ctx);
  if (control_flow) {
    auto label = make_shared<Literal>("string", ta_code.new_label());
    ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(label));
    auto comp =
        ta_code.gen(ctx->eq_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
    ta_code.gen(Operator::IF, comp);
    ctx->true_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
    ctx->false_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
  } else {
    ctx->addr =
        ta_code.gen(ctx->eq_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitAndExpr(DecafParser::AndExprContext *ctx) {
  visit(ctx->lexpr);
  visit(ctx->and_op());
  ctx->next_instr = ta_code.next_instr();
  visit(ctx->rexpr);

  if (control_flow) {
    ta_code.back_patch(ctx->lexpr->true_list, ctx->next_instr);
    ctx->true_list = ctx->rexpr->true_list;
    ctx->false_list =
        ta_code.merge(ctx->lexpr->false_list, ctx->rexpr->false_list);
  } else {
    ctx->addr = ta_code.gen(Operator::AND, ctx->lexpr->addr, ctx->rexpr->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitOrExpr(DecafParser::OrExprContext *ctx) {
  visit(ctx->lexpr);
  visit(ctx->or_op());
  ctx->next_instr = ta_code.next_instr();
  visit(ctx->rexpr);

  if (control_flow) {
    ta_code.back_patch(ctx->lexpr->false_list, ctx->next_instr);
    ctx->true_list =
        ta_code.merge(ctx->lexpr->true_list, ctx->rexpr->true_list);
    ctx->false_list = ctx->rexpr->false_list;
  } else {
    ctx->addr = ta_code.gen(Operator::OR, ctx->lexpr->addr, ctx->rexpr->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitIntLiteral(DecafParser::IntLiteralContext *ctx) {
  visitChildren(ctx);
  ctx->addr = make_shared<Literal>("int", ctx->getText());
  return nullptr;
}

Any InterCodeVisitor::visitCharLiteral(DecafParser::CharLiteralContext *ctx) {
  visitChildren(ctx);
  ctx->addr = make_shared<Literal>("char", ctx->getText());
  return nullptr;
}

Any InterCodeVisitor::visitBoolLiteral(DecafParser::BoolLiteralContext *ctx) {
  visitChildren(ctx);
  ctx->addr = make_shared<Literal>("boolean", ctx->getText());
  return nullptr;
}