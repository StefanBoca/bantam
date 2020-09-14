#pragma once

#include "Lexer.h"
#include "Parser.h"
#include "TokenType.h"
#include "Precedence.h"

class BantamParser : public Parser {
public:
	BantamParser(Lexer lexer);

	void postfix(TokenType token, int precedence);
	void prefix(TokenType token, int precedence);

	void infixLeft(TokenType token, int precedence);
	void infixRight(TokenType token, int precedence);
};