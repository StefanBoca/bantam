#pragma once

#include "PrefixParselet.h"

class PrefixOperatorParselet : public PrefixParselet {
public:
	PrefixOperatorParselet(int precedence) { mPrecedence = precedence; }

	virtual Expression& parse(Parser& parser, Token& token) override;

	virtual int getPrecedence() { return mPrecedence; }

private:
	int mPrecedence;
};
