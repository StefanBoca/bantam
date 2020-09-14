#pragma once

#include "Expression.h"

#include <memory>

class NameExpression : public Expression {
public:
	NameExpression(std::string name) : mName(name) {}

	std::string getName() { return mName; }

	virtual void print(std::ostream& out) const override { out << mName; }

private:
	std::string mName;
};

typedef std::shared_ptr<NameExpression> NameExpressionSP;
