#pragma once

#include <string>
#include <unordered_map>

#include "basic_expr.hpp"

std::string ast(const IntExpr&);

template<typename LHS, typename RHS>
std::string
ast(const AddExpr<LHS, RHS>& e) {
    return "(" + ast(e.lhs) + " + " + ast(e.rhs) + ")";
}
