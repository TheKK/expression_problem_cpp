#pragma once

#include <string>
#include <unordered_map>

#include "basic_expr.hpp"

struct SimpleAst : virtual ExprVisitor {
    std::string result_of(const Expr& e);

    void use_int(const IntExpr& e) override;
    void use_add(const AddExpr& e) override;

protected:
    std::unordered_map<const Expr*, std::string> m_result_map{};
};

std::string ast(const IntExpr&);
std::string ast(const AddExpr&);
