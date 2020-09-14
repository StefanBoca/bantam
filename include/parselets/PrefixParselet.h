#pragma once

#include "Expressions.h"
#include "Parser.h"
#include "Token.h"

class Parser;
typedef std::shared_ptr<Parser> ParserSP;

class PrefixParselet {
public:
	virtual ExpressionSP parse(ParserSP parser, Token& token) = 0;
};

typedef std::shared_ptr<PrefixParselet> PrefixParseletSP;
