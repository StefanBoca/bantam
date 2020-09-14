#pragma once

#include "Expression.h"

class AssignExpression : public Expression {
public:
	AssignExpression(std::string name, ExpressionSP right) : mName(name), mRight(right) {}

	virtual void print(std::ostream& out) const override {
		out << "(" << mName << " = ";
		out << *mRight;
		out << ")";
	}

private:
	std::string mName;
	ExpressionSP mRight;
};
