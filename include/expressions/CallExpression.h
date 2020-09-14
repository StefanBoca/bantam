#pragma once

#include "Expression.h"

#include <vector>

class CallExpression : public Expression {
public:
	CallExpression(Expression& function, std::vector<Expression*>& args) : mFunction(function), mArgs(args) {}

	virtual std::string toString() override {
		std::string str = mFunction.toString();
		str += "(";
		for (int i = 0; i < mArgs.size(); i++) {
			str += mArgs[i]->toString();
			if (i < mArgs.size() - 1) { str += ", "; }
		}
		str += ")";
		return str;
	}

private:
	Expression& mFunction;
	std::vector<Expression*>& mArgs;
};
