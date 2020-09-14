#pragma once

#include "PrefixParselet.h"

class NameParselet : public PrefixParselet {
public:
	NameParselet() = default;

	virtual ExpressionSP parse(ParserSP parser, Token& token) override {
		std::string& text = token.getText();
		return std::make_shared<NameExpression>(text);
	}
};
