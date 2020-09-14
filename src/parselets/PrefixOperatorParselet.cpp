#include "parselets/PrefixOperatorParselet.h"

ExpressionSP PrefixOperatorParselet::parse(ParserSP parser, Token& token) {
	// To handle right-associative operators like "^", we allow a slightly
	// lower precedence when parsing the right-hand side. This will let a
	// parselet with the same precedence appear on the right, which will then
	// take *this* parselet's result as its left-hand argument.
	ExpressionSP right = parser->parseExpression(mPrecedence);

	return std::make_shared<PrefixExpression>(token.getType(), right);
}
