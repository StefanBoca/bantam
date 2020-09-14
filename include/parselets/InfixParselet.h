#pragma once

#include "Expressions.h"
#include "Parser.h"
#include "Token.h"

class Parser;
typedef std::shared_ptr<Parser> ParserSP;

class InfixParselet {
public:
	virtual ExpressionSP parse(ParserSP parser, ExpressionSP left, Token& token) = 0;
	virtual int getPrecedence() = 0;
};

typedef std::shared_ptr<InfixParselet> InfixParseletSP;
