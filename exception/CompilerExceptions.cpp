#ifndef _EXCEPTION_COMPILER

#define _EXCEPTION_COMPILER

#include "Exception.cpp"

// встретили кракозябру, не можем понять кто это 
class VariableNotExistsException : public Exception
{
public:

	VariableNotExistsException(char* s) : Exception(s) { }

	VariableNotExistsException(const char* s) : Exception(s) { }
    
	VariableNotExistsException(const VariableNotExistsException& e){
		str = new char[strlen(e.str) + 1];
		strcpy_s(str, strlen(e.str) + 1, e.str);
	}

	virtual void print() {
		std::cout << "VariableNotExistsException: " << str << "; " << what() << "\n\n";
	}
};

#endif