#pragma once

#ifndef _TOKEN

#define _TOKEN

#include <string>

#include "enum/TokenTypes.hpp"

class Token {

public:

	TokenType kind;
	std::string value;

	Token();
	Token(std::string _value);
	Token(TokenType _kind, std::string _value);

	~Token();

	void print();
};

#endif