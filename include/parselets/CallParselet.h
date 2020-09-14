#pragma once

#include "InfixParselet.h"
#include "Parser.h"
#include "Expressions.h"
#include "Token.h"
#include "Precedence.h"

class CallParselet : public InfixParselet {
public:
	CallParselet() = default;

	virtual Expression& parse(Parser& parser, Expression& left, Token& token) override;

	virtual int getPrecedence() { return Precedence::CALL; }
};