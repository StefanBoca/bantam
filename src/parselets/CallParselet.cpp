#include "parselets/CallParselet.h"

ExpressionSP CallParselet::parse(ParserSP parser, ExpressionSP left, Token& token) {
	// Parse the comma-separated arguments until we hit, ")".
	std::vector<ExpressionSP> args = std::vector<ExpressionSP>();

	// There may be no arguments at all.
	if (!parser->match(TokenType::RIGHT_PAREN)) {
		do { args.push_back(parser->parseExpression()); } while (parser->match(TokenType::COMMA));
		parser->consume(TokenType::RIGHT_PAREN);
	}

	return std::make_shared<CallExpression>(left, args);
}
