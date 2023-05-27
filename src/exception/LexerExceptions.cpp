#include "exception/LexerExceptions.hpp"

UnknownSymbolException::UnknownSymbolException(char* s, std::string k) : Exception(s)
{ symbol = k; }

UnknownSymbolException::UnknownSymbolException(const char* s, std::string k) : Exception(s)
{ symbol = k; }

UnknownSymbolException::UnknownSymbolException(const UnknownSymbolException& e)
{
	str = new char[strlen(e.str) + 1];
	std::strncpy(str, e.str, strlen(e.str) + 1);
	symbol = e.symbol;
}

void UnknownSymbolException::print() {
	std::cout << "UnknownSymbolException: " << str << "; " << what() << "\n\n";
}
