#pragma once

#include <memory>

struct IntExpr {
    int val;
};

template<typename LHS, typename RHS>
struct AddExpr {
    const LHS& lhs;
    const RHS& rhs;
};

template<typename LHS, typename RHS>
AddExpr<LHS, RHS> MkAddExpr(const LHS& l, const RHS& r) {
  return {l, r};
}
