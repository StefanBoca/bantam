#pragma once

#include "PrefixParselet.h"

class NameParselet : public PrefixParselet {
public:
	NameParselet() = default;

	virtual Expression& parse(Parser& parser, Token& token) override {
		std::string& text = token.getText();
		return *new NameExpression(text);
	}
};
