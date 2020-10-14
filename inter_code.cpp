#include "inter_code.h"
#include <functional>

TACode &InterCodeVisitor::intermediate_code() { return ta_code; }

Any InterCodeVisitor::visitProgram(DecafParser::ProgramContext *ctx) {
  visitChildren(ctx);

  auto main_label = make_shared<Literal>("string", ctx->main.alias());
  auto call_main = make_shared<Triple>(
      Operator::CALL, dynamic_pointer_cast<Address>(main_label));

  ta_code.code().insert(ta_code.code().begin(), call_main);

  auto end_label = make_shared<Literal>("string", ta_code.new_label("_END_"));
  ta_code.gen(Operator::LABEL, end_label);
  auto jump_to_end = make_shared<Triple>(Operator::JUMP, end_label);
  ta_code.code().insert(ta_code.code().begin() + 1, jump_to_end);

  return nullptr;
}

Any InterCodeVisitor::visitMethodDeclaration(
    DecafParser::MethodDeclarationContext *ctx) {
  auto label = make_shared<Literal>("string", ctx->alias);
  ta_code.gen(Operator::LABEL, label);

  visitChildren(ctx);

  if (ctx->methodType()->d_type == "void") {
    ta_code.gen(Operator::RET, nullptr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitBlock(DecafParser::BlockContext *ctx) {
  visitChildren(ctx);
  ctx->next_list = ta_code.make_list(ta_code.next_instr());
  return nullptr;
}

Any InterCodeVisitor::visitIfStatement(DecafParser::IfStatementContext *ctx) {
  int marker;
  int second_marker;

  control_flow = true;
  visit(ctx->expression());
  control_flow = false;

  marker = ta_code.next_instr();
  auto new_label = make_shared<Literal>("string", ta_code.new_label());
  ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(new_label));

  visit(ctx->true_block);

  ta_code.back_patch(ctx->expression()->true_list, marker);
  ctx->next_list =
      ta_code.merge(ctx->expression()->false_list, ctx->true_block->next_list);

  if (ctx->false_block != nullptr) {
    ta_code.gen(Operator::JUMP, nullptr);

    second_marker = ta_code.next_instr();
    new_label = make_shared<Literal>("string", ta_code.new_label());
    ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(new_label));

    visit(ctx->false_block);

    ta_code.back_patch(ctx->expression()->false_list, second_marker);
    ctx->next_list =
        ta_code.merge(ctx->true_block->next_list, ctx->false_block->next_list);
  }

  marker = ta_code.next_instr();
  new_label = make_shared<Literal>("string", ta_code.new_label());
  ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(new_label));
  ta_code.back_patch(ctx->next_list, marker);

  return nullptr;
}

Any InterCodeVisitor::visitWhileStatement(
    DecafParser::WhileStatementContext *ctx) {
  int marker;
  int second_marker;
  int end_marker;

  marker = ta_code.next_instr();
  auto start_label = make_shared<Literal>("string", ta_code.new_label());
  ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(start_label));

  control_flow = true;
  visit(ctx->expression());
  control_flow = false;

  second_marker = ta_code.next_instr();
  auto secon_label = make_shared<Literal>("string", ta_code.new_label());
  ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(secon_label));
  ta_code.back_patch(ctx->expression()->true_list, second_marker);

  visit(ctx->block());
  ta_code.gen(Operator::JUMP, nullptr);
  ta_code.back_patch(ctx->block()->next_list, marker);

  end_marker = ta_code.next_instr();
  auto end_label = make_shared<Literal>("string", ta_code.new_label());
  ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(end_label));

  ctx->next_list = ctx->expression()->false_list;
  ta_code.back_patch(ctx->next_list, end_marker);

  return nullptr;
}

Any InterCodeVisitor::visitReturnStatement(
    DecafParser::ReturnStatementContext *ctx) {
  visitChildren(ctx);

  if (ctx->expression() != nullptr) {
    ta_code.gen(Operator::PUSH, ctx->expression()->addr);
    ta_code.gen(Operator::RET, nullptr);
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
    auto size = make_shared<Literal>("int", to_string(ctx->type_info.size()));
    auto base_offset =
        make_shared<Literal>("int", to_string(ctx->out.offset()));
    auto mul_instr = ta_code.gen(Operator::MUL, ctx->expression()->addr,
                                 dynamic_pointer_cast<Address>(size));
    ctx->addr = ta_code.gen(Operator::SUM, base_offset, mul_instr, true);
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

Any InterCodeVisitor::visitMethodCallExpr(
    DecafParser::MethodCallExprContext *ctx) {
  visitChildren(ctx);
  ctx->addr = ctx->methodCall()->addr;
  return nullptr;
}

Any InterCodeVisitor::visitLocationExpr(DecafParser::LocationExprContext *ctx) {
  visitChildren(ctx);
  ctx->addr = ctx->location()->addr;
  if (control_flow && ctx->d_type == "boolean") {
    ta_code.gen(Operator::IF, ctx->addr);
    ctx->true_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
    ctx->false_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
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

Any InterCodeVisitor::visitRelExpr(DecafParser::RelExprContext *ctx) {
  if (control_flow) {
    auto label = make_shared<Literal>("string", ta_code.new_label());
    ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(label));

    visitChildren(ctx);

    auto comp =
        ta_code.gen(ctx->rel_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
    ta_code.gen(Operator::IF, comp);
    ctx->true_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
    ctx->false_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
  } else {
    visitChildren(ctx);
    ctx->addr =
        ta_code.gen(ctx->rel_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitEqExpr(DecafParser::EqExprContext *ctx) {
  if (control_flow) {
    auto label = make_shared<Literal>("string", ta_code.new_label());
    ta_code.gen(Operator::LABEL, dynamic_pointer_cast<Address>(label));

    visitChildren(ctx);

    auto comp =
        ta_code.gen(ctx->eq_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
    ta_code.gen(Operator::IF, comp);
    ctx->true_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
    ctx->false_list = ta_code.make_list(ta_code.next_instr());
    ta_code.gen(Operator::JUMP, nullptr);
  } else {
    visitChildren(ctx);
    ctx->addr =
        ta_code.gen(ctx->eq_op()->op, ctx->lexpr->addr, ctx->rexpr->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitAndExpr(DecafParser::AndExprContext *ctx) {
  int next_instr;
  visit(ctx->lexpr);
  visit(ctx->and_op());

  next_instr = ta_code.next_instr();
  visit(ctx->rexpr);

  if (control_flow) {
    ta_code.back_patch(ctx->lexpr->true_list, next_instr);
    ctx->true_list = ctx->rexpr->true_list;
    ctx->false_list =
        ta_code.merge(ctx->lexpr->false_list, ctx->rexpr->false_list);
  } else {
    ctx->addr = ta_code.gen(Operator::AND, ctx->lexpr->addr, ctx->rexpr->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitOrExpr(DecafParser::OrExprContext *ctx) {
  int next_instr;
  visit(ctx->lexpr);
  visit(ctx->or_op());

  next_instr = ta_code.next_instr();
  visit(ctx->rexpr);

  if (control_flow) {
    ta_code.back_patch(ctx->lexpr->false_list, next_instr);
    ctx->true_list =
        ta_code.merge(ctx->lexpr->true_list, ctx->rexpr->true_list);
    ctx->false_list = ctx->rexpr->false_list;
  } else {
    ctx->addr = ta_code.gen(Operator::OR, ctx->lexpr->addr, ctx->rexpr->addr);
  }

  return nullptr;
}

Any InterCodeVisitor::visitMethodCall(DecafParser::MethodCallContext *ctx) {
  visitChildren(ctx);

  auto label = make_shared<Literal>("string", ctx->out.alias());
  auto call_instr = ta_code.gen(Operator::CALL, label);
  if (ctx->out.type() != "void") {
    auto pop_addr = ta_code.gen(Operator::POP, call_instr);
    ctx->addr = pop_addr;
  }

  return nullptr;
}

Any InterCodeVisitor::visitArg(DecafParser::ArgContext *ctx) {
  visitChildren(ctx);

  ta_code.gen(Operator::PARAM, ctx->expression()->addr);

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