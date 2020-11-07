#ifndef __LEXER_P
#define __LEXER_P

#include "head.h"

struct Token {
	enum class Type {
		INDENTIFIER,
		OPERATOR,
		NUMBER,
		ROOT
	};
	Type type;
	string value;
	Token(Type type, string value);
};

#endif
