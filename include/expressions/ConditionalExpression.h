#pragma once

#include "Expression.h"

class ConditionalExpression : public Expression {
public:
	ConditionalExpression(Expression& condition, Expression& thenArm, Expression& elseArm) :
		mCondition(condition), mThenArm(thenArm), mElseArm(elseArm) {}

	virtual std::string toString() {
		return std::string(
			"(" + mCondition.toString() + " ? " + mThenArm.toString() + " : " + mElseArm.toString() + ")");
	}

private:
	Expression& mCondition;
	Expression& mThenArm;
	Expression& mElseArm;
};
