#ifndef _EXCEPTION_PARSER

#define _EXCEPTION_PARSER

#include "Exception.hpp"

//Исключения
class InvalidSyntax : public Exception {

public:
    InvalidSyntax();

    InvalidSyntax(char* s);

    InvalidSyntax(const char* s);

    InvalidSyntax(const InvalidSyntax& e);

    virtual void print();
};

class SemiliconExpected : public InvalidSyntax {

public:
    SemiliconExpected(char* s);

    SemiliconExpected(const char* s);

    SemiliconExpected(const SemiliconExpected& e);

    virtual void print();
};

class BraExpected : public InvalidSyntax {

public:
    BraExpected(char* s);

    BraExpected(const char* s);

    BraExpected(const BraExpected& e);

    virtual void print();
};

class ParExpected : public InvalidSyntax {

public:
    ParExpected(char* s);

    ParExpected(const char* s);

    ParExpected(const ParExpected& e);

    virtual void print();
};

#endif