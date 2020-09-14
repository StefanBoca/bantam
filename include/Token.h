#pragma once

#include "TokenType.h"
#include <string>

class Token {
public:
	Token(TokenType type, std::string text) {
		mType = type;
		mText = text;
	}

	TokenType getType() { return mType; }
	std::string& getText() { return mText; }

	std::string toString() { return mText; }

private:
	TokenType mType;
	std::string mText;
};
