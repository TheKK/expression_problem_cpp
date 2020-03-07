#include <iostream>
#include <memory>

#include <basic_expr.hpp>
#include <simple_evaluator.hpp>

int
main() {
    const auto& forty_two = IntExpr{42};
    const auto& one = IntExpr{1};
    const auto& add_them = AddExpr{forty_two, one};

    std::cout << "forty_two: " << evaluate(forty_two) << "\n";
    std::cout << "one: " << evaluate(one) << "\n";
    std::cout << "add_them: " << evaluate(add_them) << "\n";

    return 0;
}
