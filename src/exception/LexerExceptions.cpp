#include "exception/LexerExceptions.hpp"

UnknownSymbolException::UnknownSymbolException(char* s, std::string k) : Exception(s)
{ symbol = k; }

UnknownSymbolException::UnknownSymbolException(const char* s, std::string k) : Exception(s)
{ symbol = k; }

UnknownSymbolException::UnknownSymbolException(const UnknownSymbolException& e)
{
	str = new char[strlen(e.str) + 1];
	strcpy_s(str, strlen(e.str) + 1, e.str);
	symbol = e.symbol;
}

void UnknownSymbolException::print() {
	std::cout << "UnknownSymbolException: " << str << "; " << what() << "\n\n";
}
