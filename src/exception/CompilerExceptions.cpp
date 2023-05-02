#include "exception/CompilerExceptions.hpp"

VariableNotExistsException::VariableNotExistsException(char* s) : Exception(s)
{ }

VariableNotExistsException::VariableNotExistsException(const char* s) : Exception(s)
{ }

VariableNotExistsException::VariableNotExistsException(const VariableNotExistsException& e)
{
	str = new char[strlen(e.str) + 1];
	strcpy_s(str, strlen(e.str) + 1, e.str);
}

void VariableNotExistsException::print()
{
	std::cout << "VariableNotExistsException: " << str << "; " << what() << "\n\n";
}