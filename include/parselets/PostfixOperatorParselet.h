#pragma once

#include "InfixParselet.h"

class PostfixOperatorParselet : public InfixParselet {
public:
	PostfixOperatorParselet(int precedence) { mPrecedence = precedence; }

	virtual Expression& parse(Parser& parser, Expression& left, Token& token) override {
		return *new PostfixExpression(left, token.getType());
	}

	virtual int getPrecedence() { return mPrecedence; }

private:
	int mPrecedence;
};
