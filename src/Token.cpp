#include <iostream>

#include "Token.hpp"

Token::Token() {}

Token::Token(std::string _value) { value = _value; }

Token::Token(TokenType _kind, std::string _value) { kind = _kind, value = _value; }

Token::~Token() { }

void Token::print() {
	std::cout << "kind: " << int(kind) << ", value: " << value << std::endl;
}
