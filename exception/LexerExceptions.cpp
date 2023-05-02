#ifndef _EXCEPTION_LEXER

#define _EXCEPTION_LEXER



#include "Exception.cpp"

// встретили кракозябру, не можем понять кто это 
class UnknownSymbolException : public Exception
{
protected:
	std::string symbol;
public:

	UnknownSymbolException(char* s, std::string k) : Exception(s) { symbol = k; }
	UnknownSymbolException(const char* s, std::string k) : Exception(s) { symbol = k; }
	UnknownSymbolException(const UnknownSymbolException& e){
		str = new char[strlen(e.str) + 1];
		strcpy_s(str, strlen(e.str) + 1, e.str);
		symbol = e.symbol;
	}

	virtual void print() {
		std::cout << "UnknownSymbolException: " << str << "; " << what() << "\n\n";
	}
};

#endif