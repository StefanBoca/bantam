#pragma once

#include "InfixParselet.h"
#include "Expressions.h"
#include "Precedence.h"
#include "Parser.h"
#include "ParseException.h"

class AssignParselet : public InfixParselet {
public:
	AssignParselet() = default;

	virtual ExpressionSP parse(ParserSP parser, ExpressionSP left, Token& token) override;

	virtual int getPrecedence() { return Precedence::ASSIGNMENT; }
};