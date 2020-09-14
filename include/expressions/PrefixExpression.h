#pragma once

#include "Expression.h"
#include "TokenType.h"

class PrefixExpression : public Expression {
public:
	PrefixExpression(TokenType op, ExpressionSP right) : mOperator(op), mRight(right) {}

    virtual void print(std::ostream& out) const override {
        out << "(" << punctuator(mOperator) << *mRight << ")";
    }

private:
	TokenType mOperator;
	ExpressionSP mRight;
};
