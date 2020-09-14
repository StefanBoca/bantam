#pragma once

#include "InfixParselet.h"
#include "Expressions.h"
#include "Precedence.h"

class ConditionalParselet : public InfixParselet {
public:
	ConditionalParselet() = default;

	virtual Expression& parse(Parser& parser, Expression& left, Token& token) override;

	virtual int getPrecedence() { return Precedence::CONDITIONAL; }
};