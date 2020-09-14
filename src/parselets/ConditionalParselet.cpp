#include "parselets/ConditionalParselet.h"

#include "TokenType.h"

ExpressionSP ConditionalParselet::parse(ParserSP parser, ExpressionSP left, Token& token) {
	ExpressionSP thenArm = parser->parseExpression();
	parser->consume(TokenType::COLON);
	ExpressionSP elseArm = parser->parseExpression(Precedence::CONDITIONAL - 1);

	return std::make_shared<ConditionalExpression>(left, thenArm, elseArm);
}
