#ifndef _EXCEPTION_PARENT

#define _EXCEPTION_PARENT

#include <exception>
#include <string>
#include <iostream>

class Exception : public std::exception
{
protected:

	char* str;

public:

	Exception(const char* s);

	Exception(char* s);

	Exception();

	Exception(const Exception& e);

	~Exception();

	virtual void print();
};

#endif