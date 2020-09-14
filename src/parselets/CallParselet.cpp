#include "parselets/CallParselet.h"

Expression& CallParselet::parse(Parser& parser, Expression& left, Token& token) {
	// Parse the comma-separated arguments until we hit, ")".
	std::vector<Expression*> args = std::vector<Expression*>();

	// There may be no arguments at all.
	if (!parser.match(TokenType::RIGHT_PAREN)) {
		do { args.push_back(&parser.parseExpression()); } while (parser.match(TokenType::COMMA));
		parser.consume(TokenType::RIGHT_PAREN);
	}

	return *new CallExpression(left, args);
}
