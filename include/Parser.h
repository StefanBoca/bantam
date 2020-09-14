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
#include <memory>

class PrefixParselet;
class InfixParselet;

typedef std::shared_ptr<PrefixParselet> PrefixParseletSP;
typedef std::shared_ptr<InfixParselet> InfixParseletSP;

class Parser : public std::enable_shared_from_this<Parser> {
public:
	Parser() = delete;
	Parser(LexerSP tokens);

	void registerParselet(TokenType token, PrefixParseletSP parselet);
	void registerParselet(TokenType token, InfixParseletSP parselet);

	ExpressionSP parseExpression(int precedence);
	ExpressionSP parseExpression();

	bool match(TokenType expected);
	Token consume(TokenType expected);
	Token consume();

private:
	Token lookAhead(int distance);
	int getPrecedence();

	LexerSP mTokens;
	std::vector<Token> mRead;
	std::map<TokenType, PrefixParseletSP> mPrefixParselets;
	std::map<TokenType, InfixParseletSP> mInfixParselets;
};

typedef std::shared_ptr<Parser> ParserSP;
