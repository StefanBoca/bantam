#pragma once

#include "TokenType.h"
#include "Token.h"

#include <string>
#include <map>

class Lexer {
public:
	Lexer(std::string text);

	Token next();

private:
	std::map<char, TokenType> mPunctuators = std::map<char, TokenType>();
	std::string mText;
	int mIndex = 0;
};
