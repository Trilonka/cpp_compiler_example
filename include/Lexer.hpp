#ifndef _LEXER

#define _LEXER

#include <regex>
#include <vector>
#include <set>

#include "exception/LexerExceptions.hpp"
#include "Token.hpp"
#include "enum/TokenTypes.hpp"

#define IS_TYPE(c)	(c == "int" || c == "string" || c == "bool")

class Lexer {

public:

	std::string source;						// исходный код 
	std::vector<Token> lexems;				// итоговые лексемы
	std::set<std::string> identifiers;		// список переменных в коде

	Lexer();
	Lexer(std::string src);

	~Lexer();

	// делит код на токены и формирует lexems
	std::vector<std::string> tokenize();

	// создает новый токен 
	void add_token(int _i, TokenType _kind, std::vector<std::string>& _src);

	// определяет вид токена
	void kind_token(int i, std::vector<std::string>& src);

	friend std::istream& operator >>(std::istream& ustream, Lexer& L);
};

inline std::istream& operator >>(std::istream& ustream, Lexer& L);

#endif