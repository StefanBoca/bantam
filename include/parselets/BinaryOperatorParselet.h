#pragma once

#include "InfixParselet.h"

class BinaryOperatorParselet : public InfixParselet {
public:
	BinaryOperatorParselet(int precedence, bool isRight);

	virtual Expression& parse(Parser& parser, Expression& left, Token& token) override;

	virtual int getPrecedence() { return mPrecedence; }

private:
	int mPrecedence;
	bool mIsRight;
};