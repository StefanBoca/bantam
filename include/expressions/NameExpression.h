#pragma once

#include "Expression.h"

class NameExpression : public Expression {
public:
	NameExpression(std::string name) : mName(name) {}

	std::string getName() { return mName; }

	virtual std::string toString() override { return mName; }

private:
	std::string mName;
};
