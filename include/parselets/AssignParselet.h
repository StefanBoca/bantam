#pragma once

#include "InfixParselet.h"
#include "Expressions.h"
#include "Precedence.h"
#include "Parser.h"
#include "ParseException.h"

class AssignParselet : public InfixParselet {
public:
	AssignParselet() = default;

	virtual Expression& parse(Parser& parser, Expression& left, Token& token) override;

	virtual int getPrecedence() { return Precedence::ASSIGNMENT; }
};