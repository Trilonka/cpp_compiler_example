#ifndef _EXCEPTION_PARENT

#define _EXCEPTION_PARENT

#include <fstream>
#include <iostream>

class Exception : public std::exception
{
protected:
	char* str;
public:
	Exception(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy_s(str, strlen(s) + 1, s);
	}
	Exception(char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy_s(str, strlen(s) + 1, s);
	}
	Exception()
	{
		str = NULL;
	}
	Exception(const Exception& e)
	{
		str = new char[strlen(e.str) + 1];
		strcpy_s(str, strlen(e.str) + 1, e.str);
	}
	~Exception()
	{
		delete[] str;
	}

	virtual void print()
	{
		std::cout << "Exception: " << str << "; " << what() << "\n\n";
	}
};

#endif