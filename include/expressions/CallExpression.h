#pragma once

#include "Expression.h"

#include <vector>

class CallExpression : public Expression {
public:
	CallExpression(ExpressionSP function, std::vector<ExpressionSP> args) : mFunction(function), mArgs(args) {}

	virtual void print(std::ostream& out) const override {
		out << *mFunction << "(";
		for (int i = 0; i < mArgs.size(); i++) {
			out << *(mArgs.at(i));
			if (i < mArgs.size() - 1) { out << ", "; }
		}
		out << ")";
	}

private:
	ExpressionSP mFunction;
	std::vector<ExpressionSP> mArgs;
};
