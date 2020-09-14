#pragma once

#include "Expression.h"

class AssignExpression : public Expression {
public:
	AssignExpression(std::string& name, Expression& right) : mName(name), mRight(right) {}

	virtual std::string toString() override { return std::string("(" + mName + " = " + mRight.toString() + ")"); }

private:
	std::string& mName;
	Expression& mRight;
};
