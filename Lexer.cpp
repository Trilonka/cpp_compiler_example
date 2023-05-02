// lexer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#ifndef _LEXER

#define _LEXER

//#include "/Users/1/Desktop/Вуз/Programm progect/GitHub/cpp_compiler_example/Includes.cpp"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <set>

#include "exception/LexerExceptions.cpp"
#include "Token.cpp"
#include "enums/TokenTypes.cpp"

#define IS_TYPE(c)	(c == "int" || c == "string" || c == "bool")

class Lexer {

public:

	std::string source;						// исходный код 
	std::vector<Token> lexems;				// итоговые лексемы
	std::set<std::string> identifiers;		// список переменных в коде

	Lexer() { }
	Lexer(std::string src) { source = src; }

	~Lexer() { }

	// делит код на токены и формирует lexems
	std::vector<std::string> tokenize()
	{
		std::vector<std::string> res;
		std::regex regular("([\\w]+)|([\\W])");

		std::sregex_token_iterator iter(source.begin(), source.end(), regular);
		std::sregex_token_iterator end;

		for (int i = 0; iter != end; ++iter, ++i) {

			if (*iter != " ")
			{
				res.push_back(*iter);
				kind_token(res.size() - 1, res);
			}

			// когда встречается неизвестный символ
			if (res.size() - 1 == this->lexems.size())
			{
				throw UnknownSymbolException("An unexpected symbol was encountered", res[res.size() - 1]);
			}
		}

		return res;
	}

	// создает новый токен 
	void add_token(int _i, TokenType _kind, std::vector<std::string>& _src)
	{
		Token current(_kind, _src[_i]);
		lexems.push_back(current); 
	}

	// определяет вид токена
	void kind_token(int i, std::vector<std::string>& src)
	{
		std::regex regular("([\\W])");

		if (IS_TYPE(src[i])) 
		{
			if (src[i] == "int") add_token(i, TokenType::INT, src);
			if (src[i] == "bool") add_token(i, TokenType::BOOL, src);
			if (src[i] == "string") add_token(i, TokenType::STRING, src);

			return;
		}

		if (regex_search(src[i], regular)) 
		{
			if (src[i] == "(") add_token(i, TokenType::LPAR, src);
			if (src[i] == ")") add_token(i, TokenType::RPAR, src);
			if (src[i] == "{") add_token(i, TokenType::LBRA, src);
			if (src[i] == "}") add_token(i, TokenType::RBRA, src);
			if (src[i] == "<") add_token(i, TokenType::LESS, src);
			if (src[i] == "+") add_token(i, TokenType::PLUS, src);
			if (src[i] == "-") add_token(i, TokenType::MINUS, src);
			if (src[i] == "*") add_token(i, TokenType::MULTI, src);
			if (src[i] == "/") add_token(i, TokenType::DIV, src);
			if (src[i] == "=") add_token(i, TokenType::ASSIGMENT, src);
			if (src[i] == "==") add_token(i, TokenType::EQUAL, src);
			if (src[i] == "!") add_token(i, TokenType::NOT, src);
			if (src[i] == ";") add_token(i, TokenType::SEMICOLON, src);
			if (src[i] == "'") add_token(i, TokenType::QUOTE, src);

			return;
		}

		regular = ("([\\d]+)");

		if (regex_search(src[i], regular)) 
		{
			add_token(i, TokenType::NUMBER, src); return;
		}

		regular = ("([\\w]+)");

		if ((i > 0) && (regex_search(src[i], regular)))
		{
			if (lexems[i - 1].kind >= TokenType::INT && lexems[i - 1].kind <= TokenType::STRING)
			{
				identifiers.insert(src[i]);
				add_token(i, TokenType::VAR, src); return;
			}

			if (lexems[i - 1].kind == TokenType::QUOTE || lexems[i - 1].kind == TokenType::CHARACTER)
			{
				add_token(i, TokenType::CHARACTER, src); return;
			}

			if (identifiers.find(src[i]) != identifiers.end())
			{
				add_token(i, TokenType::VAR, src); return;
			}
		}

		if (src[i] == "if") add_token(i, TokenType::IF, src);
		if (src[i] == "else") add_token(i, TokenType::ELSE, src);
		if (src[i] == "for") add_token(i, TokenType::FOR, src);
		if (src[i] == "while") add_token(i, TokenType::WHILE, src);
		if (src[i] == "print") add_token(i, TokenType::PRINT, src);
		if (src[i] == "read") add_token(i, TokenType::READ, src);

		return;
	}

	friend std::istream& operator >>(std::istream& ustream, Lexer& L);
};

inline std::istream& operator >>(std::istream& ustream, Lexer& L)
{

	std::string code;
	while (!ustream.eof()) {
		ustream >> code;
		L.source.append(code);
		L.source.append(" ");
	}
	return ustream;
}

#endif