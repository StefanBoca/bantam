#include "Lexer.h"

#include <ctype.h>

Lexer::Lexer(std::string text) {
	mIndex = 0;
	mText = text;

	std::underlying_type_t<TokenType> i = static_cast<decltype(i)>(TokenType::LEFT_PAREN);
	do {
		TokenType type = static_cast<TokenType>(i);
		char p = punctuator(type);
		if (p != 0) { mPunctuators[p] = type; }
		i++;
	} while (static_cast<TokenType>(i) != TokenType::END);
}

Token Lexer::next() {
	while (mIndex < mText.length()) {
		char c = mText[mIndex++];

		if (mPunctuators.contains(c)) {
			// Handle punctuation.
			return Token(mPunctuators.at(c), std::string(1, c));
		} else if (isalpha(c)) {
			// Handle names.
			int start = mIndex - 1;
			while (mIndex < mText.length()) {
				if (!isalpha(mText[mIndex])) break;
				mIndex++;
			}

			std::string name = mText.substr(start, mIndex);
			return Token(TokenType::NAME, name);
		} else {
			// Ignore all other characters (whitespace, etc.)
		}
	}

	// Once we've reached the end of the string, just return END tokens. We'll
	// just keeping returning them as many times as we're asked so that the
	// parser's lookahead doesn't have to worry about running out of tokens.
	return Token(TokenType::END, "");
}
