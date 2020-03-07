#include <iostream>
#include <memory>
#include <stdexcept>

#include <basic_expr.hpp>
#include <simple_ast.hpp>

struct MinusExpr;

struct ExprVisitorWithMinusExpr : virtual ExprVisitor {
    virtual void use_minus(const MinusExpr&) = 0;
};

struct MinusExpr : Expr {
    const Expr& lhs;
    const Expr& rhs;

    MinusExpr(const Expr& l, const Expr& r)
        : lhs{l}
        , rhs{r} {}

    void
    use_me(ExprVisitor& v) const override {
        const auto& supported_v = dynamic_cast<ExprVisitorWithMinusExpr*>(&v);
        if (!supported_v) {
            throw std::runtime_error{"expr visitor unable to handle minus expr!!"};
        }

        supported_v->use_minus(*this);
    };
};

struct SimpleAstWithMinusExpr
    : SimpleAst
    , ExprVisitorWithMinusExpr {

    void
    use_minus(const MinusExpr& e) {
        e.lhs.use_me(*this);
        e.rhs.use_me(*this);

        this->m_result_map[&e] =
            "(" + this->result_of(e.lhs) + " - " + this->result_of(e.rhs) + ")";
    }
};

std::string
extend_ast(const Expr& e) {
    auto eval = SimpleAstWithMinusExpr{};
    e.use_me(eval);
    return eval.result_of(e);
}

int
main() {
    const auto& forty_two = IntExpr{42};
    const auto& one = IntExpr{1};
    const auto& minus_them = MinusExpr{forty_two, one};

    const auto& add_terrible = AddExpr{forty_two, minus_them};

    std::cout << "minus_them: " << extend_ast(minus_them) << "\n";

    try {
        // Use original "ast" here.
        std::cout << "add_terrible: " << ast(add_terrible) << "\n";

    } catch (const std::exception& e) {
        std::cerr << "oops error: " << e.what() << "\n";
    }

    std::cout << "add_terrible: " << extend_ast(add_terrible) << "\n";

    return 0;
}
