#pragma once

class Precedence {
public:
	// Ordered in increasing Precedence
	static const int ASSIGNMENT = 1;
	static const int CONDITIONAL = 2;
	static const int SUM = 3;
	static const int PRODUCT = 4;
	static const int EXPONENT = 5;
	static const int PREFIX = 6;
	static const int POSTFIX = 7;
	static const int CALL = 8;
};
