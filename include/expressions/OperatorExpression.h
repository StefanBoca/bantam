#pragma once

#include "Expression.h"
#include "TokenType.h"

class OperatorExpression : public Expression {
public:
	OperatorExpression(Expression& left, TokenType op, Expression& right) : mLeft(left), mOperator(op), mRight(right) {}

	virtual std::string toString() {
		return std::string(
			"(" + mLeft.toString() + " " + std::string(1, punctuator(mOperator)) + " " + mRight.toString() + ")");
	}

private:
	Expression& mLeft;
	TokenType mOperator;
	Expression& mRight;
};
