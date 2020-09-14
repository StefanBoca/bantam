#pragma once

#include "Expression.h"
#include "TokenType.h"

class OperatorExpression : public Expression {
public:
	OperatorExpression(ExpressionSP left, TokenType op, ExpressionSP right) :
		mLeft(left), mOperator(op), mRight(right) {}

	virtual void print(std::ostream& out) const override {
		out << "(" << *mLeft << " " << punctuator(mOperator) << " " << *mRight << ")";
	}

private:
	ExpressionSP mLeft;
	TokenType mOperator;
	ExpressionSP mRight;
};
