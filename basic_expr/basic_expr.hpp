#pragma once

#include <memory>

struct Expr;
struct IntExpr;
struct AddExpr;
struct ExprVisitor;

struct Expr {
    virtual void use_me(ExprVisitor&) const = 0;

    friend ExprVisitor;
};

struct ExprVisitor {
    virtual void use_int(const IntExpr&) = 0;
    virtual void use_add(const AddExpr&) = 0;
};

struct IntExpr : Expr {
    int val;

    IntExpr(int val)
        : val{val} {}

    void
    use_me(ExprVisitor& v) const override {
        v.use_int(*this);
    };
};

struct AddExpr : Expr {
    const Expr& lhs;
    const Expr& rhs;

    AddExpr(const Expr& l, const Expr& r)
        : lhs{l}
        , rhs{r} {}

    void
    use_me(ExprVisitor& v) const override {
        v.use_add(*this);
    };
};
