#pragma once

#include "Expression.h"
#include "TokenType.h"

class PrefixExpression : public Expression {
public:
	PrefixExpression(TokenType op, Expression& right) : mOperator(op), mRight(right) {}

	virtual std::string toString() {
		return std::string("(" + std::string(1, punctuator(mOperator)) + mRight.toString() + ")");
	}

private:
	TokenType mOperator;
	Expression& mRight;
};
