#pragma once

#ifndef _TOKEN_TYPE

#define _TOKEN_TYPE

enum class TokenType {

	// IDENTIFIER
	VAR,

	// TYPE
	NUMBER,			// целое отрицательное или положительное число 
	CHARACTER,		// один символ в '_'
	REALNUMBER,		// вещественное число вида _._  
	CONSTSTRING,	// строка в "_"

	// VALUE
	INT,		// int
	BOOL,		// bool
	STRING,		// string
	CHAR,		// char
	REAL,		// real

	// SYMBOLS
	LPAR,		// (
	RPAR,		// )
	LBRA,		// {
	RBRA,		// }
	LESS,		// <
	MORE,		// >
	PLUS,		// +
	MINUS,		// -
	MULTI,		// *
	DIV,		// /
	MOD,		// %
	ASSIGMENT,	// =
	UNEQUAL,    // !=
	EQUAL,		// ==
	NOT,		// !
	SEMICOLON,	// ;
	COMMA,		// ,
	LSQBRA,		// [
	RSQBRA,		// ]

	// WORDS
	IF,			// if
	ELSE,		// else
	FOR,		// for
	WHILE,		// while
	PRINT,		// print
	PRINTLN,	// println
	READ,		// read
	OR,			// or
	AND,		// and
	DO,			// do

	EOFF		// конец файла
};

#endif