#pragma once

#ifndef _TOKEN_TYPE

#define _TOKEN_TYPE

enum class TokenType {
	// IDENTIFIER
	VAR,

	// TYPE
	NUMBER,
	CHARACTER,
	REAL, //----
	CONSTSTRING,  //-----

	// VALUE
	INT,		// int
	BOOL,		// bool
	STRING,		// string
	CHAR, //-----

	// SYMBOLS
	LPAR,		// (
	RPAR,		// )
	LBRA,		// {
	RBRA,		// }
	LESS,		// <
	PLUS,		// +
	MINUS,		// -
	ASSIGMENT,	// =
	UNEQUAL,    // != ---------------------------��������
	EQUAL,		// ==
	NOT,		// !
	SEMICOLON,	// ;
	QUOTE,		// '

	// WORDS
	IF,			// if
	ELSE,		// else
	FOR,		// for
	WHILE,		// while
	PRINT,		// print
	READ,		// read

	// TEMP_TYPES // ��������� ����, ����������� ��� ������������� � ��������
	DO,
	MULTI,
	DIV,
	MORE,

	OR,
	AND,
	EOFF
};

#endif