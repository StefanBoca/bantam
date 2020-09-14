#pragma once

#include "PrefixParselet.h"
#include "Parser.h"
#include "Token.h"

class GroupParselet : public PrefixParselet {
public:
	GroupParselet() = default;

	virtual Expression& parse(Parser& parser, Token& token) override;
};
