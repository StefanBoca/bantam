#include "Parser.h"

Parser::Parser(LexerSP tokens) :
	mRead(std::vector<Token>()), mPrefixParselets(std::map<TokenType, PrefixParseletSP>()),
	mInfixParselets(std::map<TokenType, InfixParseletSP>()), mTokens(tokens) {}

void Parser::registerParselet(TokenType token, PrefixParseletSP parselet) { mPrefixParselets[token] = parselet; }

void Parser::registerParselet(TokenType token, InfixParseletSP parselet) { mInfixParselets[token] = parselet; }

ExpressionSP Parser::parseExpression() { return parseExpression(0); }

ExpressionSP Parser::parseExpression(int precedence) {
	Token token = consume();
	PrefixParseletSP prefix;
	if (mPrefixParselets.contains(token.getType())) {
		prefix = mPrefixParselets[token.getType()];
	} else {
		throw ParseException("Could not parse \"" + token.getText() + "\".");
	}
	// try {
	// 	prefix = mPrefixParselets.at(token.getType());
	// } catch (std::out_of_range& e) { throw ParseException("Could not parse \"" + token.getText() + "\"."); }

	ExpressionSP left = prefix->parse(shared_from_this(), token);

	while (precedence < getPrecedence()) {
		token = consume();

		InfixParseletSP infix = mInfixParselets[token.getType()];
		left = infix->parse(shared_from_this(), left, token);
	}

	return left;
}

bool Parser::match(TokenType expected) {
	Token token = lookAhead(0);
	if (token.getType() != expected) { return false; }

	consume();
	return true;
}

Token Parser::consume(TokenType expected) {
	Token token = lookAhead(0);
	if (token.getType() != expected) {
		throw ParseException("Expected token " + toString(expected) + " and found " + toString(token.getType()));
	}

	return consume();
}

Token Parser::consume() {
	// Make sure we've read the token.
	lookAhead(0);

	Token first = mRead.front();
	mRead.erase(mRead.begin());
	return first;
}

Token Parser::lookAhead(int distance) {
	// Read in as many as needed.
	while (distance >= mRead.size()) { mRead.push_back(mTokens->next()); }

	// Get the queued token.
	return mRead[distance];
}

int Parser::getPrecedence() {
	TokenType t = lookAhead(0).getType();
	if (mInfixParselets.contains(t)) { return mInfixParselets[t]->getPrecedence(); }
	// InfixParseletSP parser = mInfixParselets[lookAhead(0).getType()];
	// if (parser != nullptr) {return parser->getPrecedence();}

	return 0;
}
