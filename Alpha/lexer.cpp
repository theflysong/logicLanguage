#include "lexer.h"

Token::Token(Type type, string value) {
	this->type = type;
	this->value = value;
}
