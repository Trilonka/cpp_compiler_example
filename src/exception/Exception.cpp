#include "exception/Exception.hpp"

Exception::Exception(const char* s)
{
	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
}

Exception::Exception(char* s)
{
	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
}

Exception::Exception()
{
	str = NULL;
}

Exception::Exception(const Exception& e)
{
	str = new char[strlen(e.str) + 1];
	strcpy_s(str, strlen(e.str) + 1, e.str);
}

Exception::~Exception()
{
	delete[] str;
}

void Exception::print()
{
	std::cout << "Exception: " << str << "; " << what() << "\n\n";
}
