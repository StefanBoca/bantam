#include "parselets/BinaryOperatorParselet.h"

BinaryOperatorParselet::BinaryOperatorParselet(int precedence, bool isRight) :
	mPrecedence(precedence), mIsRight(isRight) {}

Expression& BinaryOperatorParselet::parse(Parser& parser, Expression& left, Token& token) {
	// To handle right-associative operators like "^", we allow a slightly
	// lower precedence when parsing the right-hand side. This will let a
	// parselet with the same precedence appear on the right, which will then
	// take *this* parselet's result as its left-hand argument.
	Expression& right = parser.parseExpression(mPrecedence - (mIsRight ? 1 : 0));

	return *new OperatorExpression(left, token.getType(), right);
}
