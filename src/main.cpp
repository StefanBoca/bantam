#include "ParseException.h"
#include "expressions/Expression.h"
#include "Lexer.h"
#include "Parser.h"
#include "BantamParser.h"

#include <iostream>
#include <string>  
#include <sstream>

bool test(std::string source, std::string expected);

int main() {
	int total = 0;
	int passed = 0;

	// Function call.
	passed += test("a()", "a()");
	total++;
	passed += test("a(b)", "a(b)");
	total++;
	passed += test("a(b, c)", "a(b, c)");
	total++;
	passed += test("a(b)(c)", "a(b)(c)");
	total++;
	passed += test("a(b) + c(d)", "(a(b) + c(d))");
	total++;
	passed += test("a(b ? c : d, e + f)", "a((b ? c : d), (e + f))");
	total++;

	// Unary Precedence::
	passed += test("~!-+a", "(~(!(-(+a))))");
	total++;
	passed += test("a!!!", "(((a!)!)!)");
	total++;

	// Unary and binary predecence.
	passed += test("-a * b", "((-a) * b)");
	total++;
	passed += test("!a + b", "((!a) + b)");
	total++;
	passed += test("~a ^ b", "((~a) ^ b)");
	total++;
	passed += test("-a!", "(-(a!))");
	total++;
	passed += test("!a!", "(!(a!))");
	total++;

	// Binary Precedence::
	passed += test("a = b + c * d ^ e - f / g", "(a = ((b + (c * (d ^ e))) - (f / g)))");
	total++;

	// Binary associativity.
	passed += test("a = b = c", "(a = (b = c))");
	total++;
	passed += test("a + b - c", "((a + b) - c)");
	total++;
	passed += test("a * b / c", "((a * b) / c)");
	total++;
	passed += test("a ^ b ^ c", "(a ^ (b ^ c))");
	total++;

	// Conditional operator.
	passed += test("a ? b : c ? d : e", "(a ? b : (c ? d : e))");
	total++;
	passed += test("a ? b ? c : d : e", "(a ? (b ? c : d) : e)");
	total++;
	passed += test("a + b ? c * d : e / f", "((a + b) ? (c * d) : (e / f))");
	total++;

	// Grouping.
	passed += test("a + (b + c) + d", "((a + (b + c)) + d)");
	total++;
	passed += test("a ^ (b + c)", "(a ^ (b + c))");
	total++;
	passed += test("(!a)!", "((!a)!)");
	total++;

	int failed = total - passed;

	// Show the results.
	if (failed == 0) {
		std::cout << "Passed all " << total << " tests." << std::endl;
	} else {
		std::cout << "----" << std::endl;
		std::cout << "Failed " << failed << ", passed " << passed << " tests out of " << total << " tests."
				  << std::endl;
	}
}

/**
 * Parses the given chunk of code and verifies that it matches the expected
 * pretty-printed result.
 */
bool test(std::string source, std::string expected) {
	LexerSP lexer = std::make_shared<Lexer>(source);
	ParserSP parser = std::make_shared<BantamParser>(lexer);

	try {
		ExpressionSP result = parser->parseExpression();
        std::stringstream a;
        a << *result;
		std::string actual = a.str();

		if (expected == actual) {
			// passed
			return true;
		} else {
			// failed
			std::cout << "[FAIL] Expected: " << expected << std::endl;
			std::cout << "         Actual: " << actual << std::endl;
			return false;
		}
	} catch (ParseException& ex) {
		// failed
		std::cout << "[FAIL] Expected: " << expected << std::endl;
		std::cout << "          Error: " << ex.what();
		return false;
	}
}
