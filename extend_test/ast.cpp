#include <iostream>
#include <memory>
#include <stdexcept>

#include <basic_expr.hpp>
#include <simple_ast.hpp>

template<typename LHS, typename RHS>
struct MinusExpr {
    const LHS& lhs;
    const RHS& rhs;
};

template<typename LHS, typename RHS>
MinusExpr<LHS, RHS>
MkMinusExpr(const LHS& l, const RHS& r) {
    return {l, r};
}

template<typename LHS, typename RHS>
std::string
ast(const MinusExpr<LHS, RHS>& e) {
    return "(" + ast(e.lhs) + " - " + ast(e.rhs) + ")";
}

int
main() {
    const auto& forty_two = IntExpr{42};
    const auto& one = IntExpr{1};
    const auto& minus_them = MkMinusExpr(forty_two, one);

    const auto& add_terrible = MkAddExpr(forty_two, minus_them);

    std::cout << "minus_them: " << ast(minus_them) << "\n";
    std::cout << "add_terrible: " << ast(add_terrible) << "\n";

    return 0;
}
