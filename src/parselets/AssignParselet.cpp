#include "parselets/AssignParselet.h"

ExpressionSP AssignParselet::parse(ParserSP parser, ExpressionSP left, Token& token) {
	ExpressionSP right = parser->parseExpression(static_cast<int>(Precedence::ASSIGNMENT) - 1);

	NameExpressionSP l;
	if (!(l = dynamic_pointer_cast<NameExpression>(left))) {
		throw ParseException("The left-hand side of an assignment must be a name.");
	}

	std::string name = l->getName();
	return std::make_shared<AssignExpression>(name, right);
}