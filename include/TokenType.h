#pragma once

#include <string>

enum class TokenType {
	LEFT_PAREN,
	RIGHT_PAREN,
	COMMA,
	ASSIGN,
	PLUS,
	MINUS,
	ASTERISK,
	SLASH,
	CARET,
	TILDE,
	BANG,
	QUESTION,
	COLON,
	NAME,
	END
};

static inline std::string toString(TokenType tokenType) {
	switch (tokenType) {
		case TokenType::LEFT_PAREN: return "LEFT_PAREN";
		case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
		case TokenType::COMMA: return "COMMA";
		case TokenType::ASSIGN: return "ASSIGN";
		case TokenType::PLUS: return "PLUS";
		case TokenType::MINUS: return "MINUS";
		case TokenType::ASTERISK: return "ASTERISK";
		case TokenType::SLASH: return "SLASH";
		case TokenType::CARET: return "CARET";
		case TokenType::TILDE: return "TILDE";
		case TokenType::BANG: return "BANG";
		case TokenType::QUESTION: return "QUESTION";
		case TokenType::COLON: return "COLON";
		case TokenType::NAME: return "NAME";
		case TokenType::END: return "END";
	}
	return "";
}

static inline char punctuator(TokenType tokenType) {
	switch (tokenType) {
		case TokenType::LEFT_PAREN: return '(';
		case TokenType::RIGHT_PAREN: return ')';
		case TokenType::COMMA: return ',';
		case TokenType::ASSIGN: return '=';
		case TokenType::PLUS: return '+';
		case TokenType::MINUS: return '-';
		case TokenType::ASTERISK: return '*';
		case TokenType::SLASH: return '/';
		case TokenType::CARET: return '^';
		case TokenType::TILDE: return '~';
		case TokenType::BANG: return '!';
		case TokenType::QUESTION: return '?';
		case TokenType::COLON: return ':';
		default: return 0;
	}
}