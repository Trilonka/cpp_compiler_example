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

	std::string source;						// �������� ��� 
	std::vector<Token> lexems;				// �������� �������
	std::set<std::string> identifiers;		// ������ ���������� � ����

	Lexer();
	Lexer(std::string src);

	~Lexer();

	// ����� ��� �� ������ � ��������� lexems
	std::vector<std::string> tokenize();

	// ������� ����� ����� 
	void add_token(int _i, TokenType _kind, std::vector<std::string>& _src);

	// ���������� ��� ������
	void kind_token(int i, std::vector<std::string>& src);

	friend std::istream& operator >>(std::istream& ustream, Lexer& L);
};

inline std::istream& operator >>(std::istream& ustream, Lexer& L);

#endif