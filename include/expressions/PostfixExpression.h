#pragma once

#include "Expression.h"
#include "TokenType.h"

class PostfixExpression : public Expression {
public:
	PostfixExpression(Expression& left, TokenType op) : mLeft(left), mOperator(op) {}

	virtual std::string toString() { return std::string("(" + mLeft.toString() + std::string(1, punctuator(mOperator)) + ")"); }

private:
	Expression& mLeft;
	TokenType mOperator;
};
