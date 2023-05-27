#include "exception/Exception.hpp"

Exception::Exception(const char* s)
{
	str = new char[strlen(s) + 1];
    std::strncpy(str, s, strlen(s) + 1);
}

Exception::Exception(char* s)
{
	str = new char[strlen(s) + 1];
    std::strncpy(str, s, strlen(s) + 1);
}

Exception::Exception()
{
	str = NULL;
}

Exception::Exception(const Exception& e)
{
	str = new char[strlen(e.str) + 1];
	std::strncpy(str, e.str, strlen(e.str) + 1);
}

Exception::~Exception()
{
	delete[] str;
}

void Exception::print()
{
	std::cout << "Exception: " << str << "; " << what() << "\n\n";
}
