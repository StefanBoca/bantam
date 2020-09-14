#pragma once

#include "TokenType.h"
#include "Lexer.h"
#include "Token.h"
#include "Expressions.h"
#include "ParseException.h"
#include "parselets/PrefixParselet.h"
#include "parselets/InfixParselet.h"

#include <vector>
#include <map>

class PrefixParselet;
class InfixParselet;

class Parser {
public:
	Parser() = delete;
	Parser(Lexer& tokens);

	void registerParselet(TokenType token, PrefixParselet& parselet);
	void registerParselet(TokenType token, InfixParselet& parselet);

	Expression& parseExpression(int precedence);
	Expression& parseExpression();

	bool match(TokenType expected);
	Token consume(TokenType expected);
	Token consume();

private:
	Token lookAhead(int distance);
	int getPrecedence();

	Lexer& mTokens;
	std::vector<Token> mRead;
	std::map<TokenType, PrefixParselet*> mPrefixParselets;
	std::map<TokenType, InfixParselet*> mInfixParselets;
};