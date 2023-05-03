#include "exception/ParserExceptions.hpp"



InvalidSyntax::InvalidSyntax() : Exception() {}

InvalidSyntax::InvalidSyntax(char* s) : Exception(s) {}

InvalidSyntax::InvalidSyntax(const char* s) : Exception(s) {}

InvalidSyntax::InvalidSyntax(const InvalidSyntax& e) //Конструктор копии
{
    str = new char[strlen(e.str) + 1];
    strcpy_s(str, strlen(e.str) + 1, e.str);
}

void InvalidSyntax::print() {
    std::cout << "InvalidSyntax : " << str << "; " << what() << "\n";
}



SemiliconExpected::SemiliconExpected(char* s) : InvalidSyntax(s) {}

SemiliconExpected::SemiliconExpected(const char* s) : InvalidSyntax(s) {}

SemiliconExpected::SemiliconExpected(const SemiliconExpected& e) //Конструктор копии
{
    str = new char[strlen(e.str) + 1];
    strcpy_s(str, strlen(e.str) + 1, e.str);
}

void SemiliconExpected::print() {
    std::cout << "SemiliconExpected : " << str << "; " << what() << "\n";
}



BraExpected::BraExpected(char* s) : InvalidSyntax(s) {}

BraExpected::BraExpected(const char* s) : InvalidSyntax(s) {}

BraExpected::BraExpected(const BraExpected& e) //Конструктор копии
{
    str = new char[strlen(e.str) + 1];
    strcpy_s(str, strlen(e.str) + 1, e.str);
}

void BraExpected::print() {
    std::cout << "BraExpected : " << str << "; " << what() << "\n";
}



ParExpected::ParExpected(char* s) : InvalidSyntax(s) {}

ParExpected::ParExpected(const char* s) : InvalidSyntax(s) {}

ParExpected::ParExpected(const ParExpected& e) //Конструктор копии
{
    str = new char[strlen(e.str) + 1];
    strcpy_s(str, strlen(e.str) + 1, e.str);
}

void ParExpected::print() {
    std::cout << "ParExpected : " << str << "; " << what() << "\n";
}