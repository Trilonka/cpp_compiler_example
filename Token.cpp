#ifndef _TOKEN

#define _TOKEN

#include <string>
#include <iostream>
#include "enums/TokenTypes.cpp"

class Token {

public:

	TokenType kind;
	std::string value;

	Token() {}
	Token(std::string _value) { value = _value; }
	Token(TokenType _kind, std::string _value) { kind = _kind, value = _value; }

	~Token() { }

	void print() {
		std::cout << "kind: " << int(kind) << ", value: " << value << std::endl;
	}
};

#endif