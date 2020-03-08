#pragma once

#include <unordered_map>

#include "basic_expr.hpp"

double evaluate(const IntExpr&);

template<typename LHS, typename RHS>
double
evaluate(const AddExpr<LHS, RHS>& e) {
    return evaluate(e.lhs) + evaluate(e.rhs);
}
