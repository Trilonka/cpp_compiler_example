#ifndef _EXCEPTION_COMPILER

#define _EXCEPTION_COMPILER

#include "Exception.hpp"

class VariableNotExistsException : public Exception
{
public:

	VariableNotExistsException(char* s);

	VariableNotExistsException(const char* s);

	VariableNotExistsException(const VariableNotExistsException& e);

	virtual void print();
};

#endif