#include <iostream>
#include <memory>

#include <basic_expr.hpp>
#include <simple_ast.hpp>

int
main() {
    const auto& forty_two = IntExpr{42};
    const auto& one = IntExpr{1};
    const auto& add_them = MkAddExpr(forty_two, one);

    std::cout << "forty_two: " << ast(forty_two) << "\n";
    std::cout << "one: " << ast(one) << "\n";
    std::cout << "add_them: " << ast(add_them) << "\n";

    return 0;
}
