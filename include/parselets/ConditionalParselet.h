#pragma once

#include "InfixParselet.h"
#include "Expressions.h"
#include "Precedence.h"

class ConditionalParselet : public InfixParselet {
public:
	ConditionalParselet() = default;

	virtual ExpressionSP parse(ParserSP parser, ExpressionSP left, Token& token) override;

	virtual int getPrecedence() { return Precedence::CONDITIONAL; }
};