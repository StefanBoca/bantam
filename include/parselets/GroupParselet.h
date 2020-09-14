#pragma once

#include "PrefixParselet.h"
#include "Parser.h"
#include "Token.h"

class GroupParselet : public PrefixParselet {
public:
	GroupParselet() = default;

	virtual ExpressionSP parse(ParserSP parser, Token& token) override;
};
