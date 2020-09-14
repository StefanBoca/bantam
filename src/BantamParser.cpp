#include "BantamParser.h"

#include "Parselets.h"

BantamParser::BantamParser(LexerSP lexer) : Parser(lexer) {
	registerParselet(TokenType::NAME, std::make_shared<NameParselet>());
	registerParselet(TokenType::ASSIGN, std::make_shared<AssignParselet>());
	registerParselet(TokenType::QUESTION, std::make_shared<ConditionalParselet>());
	registerParselet(TokenType::LEFT_PAREN, std::make_shared<GroupParselet>());
	registerParselet(TokenType::LEFT_PAREN, std::make_shared<CallParselet>());

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
	registerParselet(token, std::make_shared<PostfixOperatorParselet>(precedence));
}

void BantamParser::prefix(TokenType token, int precedence) {
	registerParselet(token, std::make_shared<PrefixOperatorParselet>(precedence));
}

void BantamParser::infixLeft(TokenType token, int precedence) {
	registerParselet(token, std::make_shared<BinaryOperatorParselet>(precedence, false));
}

void BantamParser::infixRight(TokenType token, int precedence) {
	registerParselet(token, std::make_shared<BinaryOperatorParselet>(precedence, true));
}