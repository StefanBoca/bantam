#include "parselets/GroupParselet.h"

Expression& GroupParselet::parse(Parser& parser, Token& token) {
	Expression& expression = parser.parseExpression();
	parser.consume(TokenType::RIGHT_PAREN);
	return expression;
}
