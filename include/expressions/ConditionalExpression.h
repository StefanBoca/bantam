#pragma once

#include "Expression.h"

class ConditionalExpression : public Expression {
public:
	ConditionalExpression(ExpressionSP condition, ExpressionSP thenArm, ExpressionSP elseArm) :
		mCondition(condition), mThenArm(thenArm), mElseArm(elseArm) {}

	virtual void print(std::ostream& out) const override {
		out << "(" << *mCondition << " ? " << *mThenArm << " : " << *mElseArm << ")";
	}

private:
	ExpressionSP mCondition;
	ExpressionSP mThenArm;
	ExpressionSP mElseArm;
};
