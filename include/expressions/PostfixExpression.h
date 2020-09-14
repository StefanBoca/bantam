#pragma once

#include "Expression.h"
#include "TokenType.h"

class PostfixExpression : public Expression {
public:
	PostfixExpression(ExpressionSP left, TokenType op) : mLeft(left), mOperator(op) {}

	virtual void print(std::ostream& out) const override { out << "(" << *mLeft << punctuator(mOperator) << ")"; }

private:
	ExpressionSP mLeft;
	TokenType mOperator;
};
