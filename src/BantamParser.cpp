#include "BantamParser.h"

#include "Parselets.h"

BantamParser::BantamParser(Lexer lexer) : Parser(lexer) {
	// registerParselet the ones that need special parselets.
	PrefixParselet* nameParselet = dynamic_cast<PrefixParselet*>(new NameParselet());
	InfixParselet* assignParselet = dynamic_cast<InfixParselet*>(new AssignParselet());
	InfixParselet* conditionalParselet = dynamic_cast<InfixParselet*>(new ConditionalParselet());
	PrefixParselet* groupParselet = dynamic_cast<PrefixParselet*>(new GroupParselet());
	InfixParselet* callParselet = dynamic_cast<InfixParselet*>(new CallParselet());
	registerParselet(TokenType::NAME, *nameParselet);
	registerParselet(TokenType::ASSIGN, *assignParselet);
	registerParselet(TokenType::QUESTION, *conditionalParselet);
	registerParselet(TokenType::LEFT_PAREN, *groupParselet);
	registerParselet(TokenType::LEFT_PAREN, *callParselet);

	// registerParselet the simple operator parselets.
	prefix(TokenType::PLUS, Precedence::PREFIX);
	prefix(TokenType::MINUS, Precedence::PREFIX);
	prefix(TokenType::TILDE, Precedence::PREFIX);
	prefix(TokenType::BANG, Precedence::PREFIX);

	// For kicks, we'll make "!" both prefix and postfix, kind of like ++.
	postfix(TokenType::BANG, Precedence::POSTFIX);

	infixLeft(TokenType::PLUS, Precedence::SUM);
	infixLeft(TokenType::MINUS, Precedence::SUM);
	infixLeft(TokenType::ASTERISK, Precedence::PRODUCT);
	infixLeft(TokenType::SLASH, Precedence::PRODUCT);
	infixRight(TokenType::CARET, Precedence::EXPONENT);
}

void BantamParser::postfix(TokenType token, int precedence) {
	InfixParselet* postfixOperatorParselet = dynamic_cast<InfixParselet*>(new PostfixOperatorParselet(precedence));
	registerParselet(token, *postfixOperatorParselet);
}

void BantamParser::prefix(TokenType token, int precedence) {
	PrefixParselet* prefixOperatorParselet = dynamic_cast<PrefixParselet*>(new PrefixOperatorParselet(precedence));
	registerParselet(token, *prefixOperatorParselet);
}

void BantamParser::infixLeft(TokenType token, int precedence) {
	InfixParselet* binaryOperatorParselet = dynamic_cast<InfixParselet*>(new BinaryOperatorParselet(precedence, false));
	registerParselet(token, *binaryOperatorParselet);
}

void BantamParser::infixRight(TokenType token, int precedence) {
	InfixParselet* binaryOperatorParselet = dynamic_cast<InfixParselet*>(new BinaryOperatorParselet(precedence, true));
	registerParselet(token, *binaryOperatorParselet);
}