#include "simple_ast.hpp"

#include <string>
#include <unordered_map>

std::string
SimpleAst::result_of(const Expr& e) {
    return this->m_result_map[&e];
}

void
SimpleAst::use_int(const IntExpr& e) {
    this->m_result_map[&e] = std::to_string(e.val);
}

void
SimpleAst::use_add(const AddExpr& e) {
    e.lhs.use_me(*this);
    e.rhs.use_me(*this);

    this->m_result_map[&e] = "(" + this->result_of(e.lhs) + " + " + this->result_of(e.rhs) + ")";
}

std::string
ast(const Expr& e) {
    auto eval = SimpleAst{};
    e.use_me(eval);
    return eval.result_of(e);
}
