#include "simple_evaluator.hpp"

#include <unordered_map>

double
SimpleEvaluator::result_of(const Expr& e) {
    return this->m_result_map[&e];
}

void
SimpleEvaluator::use_int(const IntExpr& e) {
    this->m_result_map[&e] = e.val;
}

void
SimpleEvaluator::use_add(const AddExpr& e) {
    e.lhs.use_me(*this);
    e.rhs.use_me(*this);

    this->m_result_map[&e] = this->result_of(e.lhs) + this->result_of(e.rhs);
}

double
evaluate(const IntExpr& e) {
    auto eval = SimpleEvaluator{};
    eval.use_int(e);
    return eval.result_of(e);
}

double
evaluate(const AddExpr& e) {
    auto eval = SimpleEvaluator{};
    eval.use_add(e);
    return eval.result_of(e);
}
