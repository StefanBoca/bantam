#pragma once

#include <string>
#include <memory>
#include <ostream>

class Expression {
public:
	virtual void print(std::ostream& out) const = 0;
};

typedef std::shared_ptr<Expression> ExpressionSP;

static inline std::ostream& operator<<(std::ostream& out, const Expression& expr) {
	expr.print(out);
	return out;
}
