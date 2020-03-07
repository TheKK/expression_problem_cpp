#pragma once

#include <unordered_map>

#include "basic_expr.hpp"

struct SimpleEvaluator : virtual ExprVisitor {
    double result_of(const Expr& e);

    void use_int(const IntExpr& e) override;
    void use_add(const AddExpr& e) override;

private:
    std::unordered_map<const Expr*, double> m_result_map{};
};

double evaluate(const IntExpr&);
double evaluate(const AddExpr&);
