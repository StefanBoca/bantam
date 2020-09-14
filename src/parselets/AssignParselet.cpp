#include "parselets/AssignParselet.h"

Expression& AssignParselet::parse(Parser& parser, Expression& left, Token& token) {
	Expression& right = parser.parseExpression(static_cast<int>(Precedence::ASSIGNMENT) - 1);

	NameExpression* l;
	if (!(l = dynamic_cast<NameExpression*>(&left))) {
		throw ParseException("The left-hand side of an assignment must be a name.");
	}

	std::string name = l->getName();
	return *new AssignExpression(name, right);
}