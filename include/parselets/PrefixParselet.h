#pragma once

#include "Expressions.h"
#include "Parser.h"
#include "Token.h"

class Parser;

class PrefixParselet {
public:
	virtual Expression& parse(Parser& parser, Token& token) = 0;
};
