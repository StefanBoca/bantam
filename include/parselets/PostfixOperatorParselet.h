#pragma once

#include "InfixParselet.h"

class PostfixOperatorParselet : public InfixParselet {
public:
	PostfixOperatorParselet(int precedence) { mPrecedence = precedence; }

	virtual ExpressionSP parse(ParserSP parser, ExpressionSP left, Token& token) override {
		return std::make_shared<PostfixExpression>(left, token.getType());
	}

	virtual int getPrecedence() { return mPrecedence; }

private:
	int mPrecedence;
};
