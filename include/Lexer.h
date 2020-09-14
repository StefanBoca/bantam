#pragma once

#include "TokenType.h"
#include "Token.h"

#include <string>
#include <map>
#include <memory>

class Lexer {
public:
	Lexer(std::string text);

	Token next();

private:
	std::map<char, TokenType> mPunctuators = std::map<char, TokenType>();
	std::string mText;
	int mIndex = 0;
};

typedef std::shared_ptr<Lexer> LexerSP;
