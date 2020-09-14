#pragma once

#include "InfixParselet.h"

class BinaryOperatorParselet : public InfixParselet {
public:
	BinaryOperatorParselet(int precedence, bool isRight);

	virtual ExpressionSP parse(ParserSP parser, ExpressionSP left, Token& token) override;

	virtual int getPrecedence() { return mPrecedence; }

private:
	int mPrecedence;
	bool mIsRight;
};