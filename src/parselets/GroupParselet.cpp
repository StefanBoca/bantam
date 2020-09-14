#include "parselets/GroupParselet.h"

ExpressionSP GroupParselet::parse(ParserSP parser, Token& token) {
	ExpressionSP expression = parser->parseExpression();
	parser->consume(TokenType::RIGHT_PAREN);
	return expression;
}
