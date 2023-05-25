#include "Lexer.hpp"

Lexer::Lexer() { }
Lexer::Lexer(std::string src) { source = src; }

Lexer::~Lexer() { }

// делит код на токены и формирует lexems
std::vector<std::string> Lexer::tokenize()
{
	std::vector<std::string> res;
	std::regex regular("('.')|(\")|([\\w]+[.][\\w]+)|([\\w]+)|([\\W])");
	
	std::sregex_token_iterator iter(source.begin(), source.end(), regular);
	std::sregex_token_iterator end;

	for (int i = 0; iter != end; ++iter, ++i)
	{
		if (*iter == "\"")
		{
			std::string const_str;

			++iter;
			while (*iter != "\"") 
			{
				std::string char_str = *iter;
				const_str = const_str + char_str; 
				++iter;
			}

			res.push_back(const_str);
			add_token(res.size() - 1, TokenType::CONSTSTRING, res);
		}
		else if (*iter != " ")
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

	Token current(TokenType::EOFF, "/eof");
	lexems.push_back(current);

	return res;
}

// создает новый токен
void Lexer::add_token(int _i, TokenType _kind, std::vector<std::string>& _src)
{
	Token current(_kind, _src[_i]);
	lexems.push_back(current);
}

// определяет вид токена
void Lexer::kind_token(int i, std::vector<std::string>& src)
{
	if (IS_TYPE(src[i]))
	{
		if (src[i] == "int") add_token(i, TokenType::INT, src);
		if (src[i] == "bool") add_token(i, TokenType::BOOL, src);
		if (src[i] == "string") add_token(i, TokenType::STRING, src);
		if (src[i] == "char") add_token(i, TokenType::CHAR, src);
		if (src[i] == "real") add_token(i, TokenType::REAL, src);

		return;
	}

	std::regex regular("('.')");
	if (regex_search(src[i], regular))
	{
		src[i].erase(src[i].begin());
		src[i].erase(src[i].end() - 1);
		add_token(i, TokenType::CHARACTER, src);

		return;
	}

	regular = ("^[\\d]+[.][\\d]+");
	if (regex_search(src[i], regular))
	{
		if ((this->lexems[i - 1].kind == TokenType::MINUS) &&
			(this->lexems[i - 2].kind > TokenType::CHAR && this->lexems[i - 2].kind < TokenType::IF))
		{
			lexems.pop_back();
			src[i] = src[i - 1] + src[i];
			add_token(i, TokenType::REALNUMBER, src);
			src.erase(src.begin() + i - 1);
		}
		else add_token(i, TokenType::REALNUMBER, src);

		return;
	}

	regular = ("^[\\d]+");
	if (regex_search(src[i], regular))
	{
		if ((this->lexems[i - 1].kind == TokenType::MINUS) &&
			(this->lexems[i - 2].kind > TokenType::CHAR && this->lexems[i - 2].kind < TokenType::IF))
		{
			lexems.pop_back();
			src[i] = src[i - 1] + src[i];
			add_token(i, TokenType::NUMBER, src);
			src.erase(src.begin() + i - 1);
		}
		else add_token(i, TokenType::NUMBER, src);

		return;
	}

	regular = ("[\\W]");
	if (regex_search(src[i], regular))
	{
		if (src[i] == "(") add_token(i, TokenType::LPAR, src);
		if (src[i] == ")") add_token(i, TokenType::RPAR, src);
		if (src[i] == "{") add_token(i, TokenType::LBRA, src);
		if (src[i] == "}") add_token(i, TokenType::RBRA, src);
		if (src[i] == "<") add_token(i, TokenType::LESS, src);
		if (src[i] == ">") add_token(i, TokenType::MORE, src);
		if (src[i] == "+") add_token(i, TokenType::PLUS, src);
		if (src[i] == "-") add_token(i, TokenType::MINUS, src);
		if (src[i] == "*") add_token(i, TokenType::MULTI, src);
		if (src[i] == "/") add_token(i, TokenType::DIV, src);
		if (src[i] == "!") add_token(i, TokenType::NOT, src);
		if (src[i] == ";") add_token(i, TokenType::SEMICOLON, src);
		if (src[i] == ",") add_token(i, TokenType::COMMA, src);
		if (src[i] == "[") add_token(i, TokenType::LSQBRA, src);
		if (src[i] == "]") add_token(i, TokenType::RSQBRA, src);

		if (src[i] == "=") {
			if (src[i - 1] == "=")
			{
				lexems.pop_back();
				src[i] = src[i - 1] + src[i];
				add_token(i, TokenType::EQUAL, src);
				src.erase(src.begin() + i - 1);
			}
			else if (src[i - 1] == "!")
			{
				lexems.pop_back();
				src[i] = src[i - 1] + src[i];
				add_token(i, TokenType::UNEQUAL, src);
				src.erase(src.begin() + i - 1);
			}
			else add_token(i, TokenType::ASSIGMENT, src);
		}

		return;
	}

	regular = ("[\\w]+[\\d]*");
	if ((i > 0) && (regex_search(src[i], regular)))
	{
		if (lexems[i - 1].kind >= TokenType::INT && lexems[i - 1].kind <= TokenType::CHAR)
		{
			identifiers.insert(src[i]);
			add_token(i, TokenType::VAR, src); return;
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
	if (src[i] == "or") add_token(i, TokenType::OR, src);
	if (src[i] == "and") add_token(i, TokenType::AND, src);
	if (src[i] == "do") add_token(i, TokenType::DO, src);

	return;
}

std::istream& operator >>(std::istream& ustream, Lexer& L)
{
	std::string code;
	while (!ustream.eof()) {
		ustream >> code;
		L.source.append(code);
		//std::cout << code;
		L.source.append(" ");
	}
	return ustream;
}