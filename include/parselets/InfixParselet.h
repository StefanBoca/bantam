#pragma once

#include "Expressions.h"
#include "Parser.h"
#include "Token.h"

class Parser;

class InfixParselet {
public:
	virtual Expression& parse(Parser& parser, Expression& left, Token& token) = 0;
	virtual int getPrecedence() = 0;
};
