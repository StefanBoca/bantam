#include "parselets/ConditionalParselet.h"

#include "TokenType.h"

Expression& ConditionalParselet::parse(Parser& parser, Expression& left, Token& token) {
	Expression& thenArm = parser.parseExpression();
	parser.consume(TokenType::COLON);
	Expression& elseArm = parser.parseExpression(Precedence::CONDITIONAL - 1);

	return *new ConditionalExpression(left, thenArm, elseArm);
}
