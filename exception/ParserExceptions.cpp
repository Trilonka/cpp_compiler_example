#include "Exception.cpp"

//Исключения
class InvalidSyntax : public Exception {

public:
    InvalidSyntax() : Exception() {}

    InvalidSyntax(char* s) : Exception(s) {}

    InvalidSyntax(const char* s) : Exception(s) {}

    InvalidSyntax(const InvalidSyntax& e) //Конструктор копии
    {
        str = new char[strlen(e.str) + 1];
        strcpy_s(str, strlen(e.str) + 1, e.str);
    }

    virtual void print() {
        std::cout << "InvalidSyntax : " << str << "; " << what() << "\n";
    }
};

class SemiliconExpected : public InvalidSyntax {

public:
    SemiliconExpected(char* s) : InvalidSyntax(s){}

    SemiliconExpected(const char* s) : InvalidSyntax(s){}

    SemiliconExpected(const SemiliconExpected& e) //Конструктор копии
    {
        str = new char[strlen(e.str) + 1];
        strcpy_s(str, strlen(e.str) + 1, e.str);
    }

    virtual void print() {
        std::cout << "SemiliconExpected : " << str << "; " << what() << "\n";
    }
};

class BraExpected : public InvalidSyntax {

public:
    BraExpected(char* s) : InvalidSyntax(s) {}

    BraExpected(const char* s) : InvalidSyntax(s) {}

    BraExpected(const BraExpected& e) //Конструктор копии
    {
        str = new char[strlen(e.str) + 1];
        strcpy_s(str, strlen(e.str) + 1, e.str);
    }

    virtual void print() {
        std::cout << "BraExpected : " << str << "; " << what() << "\n";
    }
};

class ParExpected : public InvalidSyntax {

public:
    ParExpected(char* s) : InvalidSyntax(s) {}

    ParExpected(const char* s) : InvalidSyntax(s) {}

    ParExpected(const ParExpected& e) //Конструктор копии
    {
        str = new char[strlen(e.str) + 1];
        strcpy_s(str, strlen(e.str) + 1, e.str);
    }

    virtual void print() {
        std::cout << "ParExpected : " << str << "; " << what() << "\n";
    }
};