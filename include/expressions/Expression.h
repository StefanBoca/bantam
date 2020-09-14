#pragma once

#include <string>
#include <memory>

class Expression {
public:
	virtual std::string toString() = 0;
};

typedef std::shared_ptr<Expression> ExpressionSP;
