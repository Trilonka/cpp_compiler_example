#ifndef _EXCEPTION_LEXER

#define _EXCEPTION_LEXER

#include "Exception.hpp"

// встретили кракозябру, не можем понять кто это 
class UnknownSymbolException : public Exception
{
protected:

	std::string symbol;

public:

	UnknownSymbolException(char* s, std::string k);

	UnknownSymbolException(const char* s, std::string k);

	UnknownSymbolException(const UnknownSymbolException& e);

	virtual void print();
};

#endif