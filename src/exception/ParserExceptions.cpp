#include "exception/ParserExceptions.hpp"



InvalidSyntax::InvalidSyntax() : Exception() {}

InvalidSyntax::InvalidSyntax(char* s) : Exception(s) {}

InvalidSyntax::InvalidSyntax(const char* s) : Exception(s) {}

InvalidSyntax::InvalidSyntax(const InvalidSyntax& e) //����������� �����
{
    str = new char[strlen(e.str) + 1];
    std::strncpy(str, e.str, strlen(e.str) + 1);
}

void InvalidSyntax::print() {
    std::cout << "InvalidSyntax : " << str << "; " << what() << "\n";
}



SemiliconExpected::SemiliconExpected(char* s) : InvalidSyntax(s) {}

SemiliconExpected::SemiliconExpected(const char* s) : InvalidSyntax(s) {}

SemiliconExpected::SemiliconExpected(const SemiliconExpected& e) //����������� �����
{
    str = new char[strlen(e.str) + 1];
    std::strncpy(str, e.str, strlen(e.str) + 1);
}

void SemiliconExpected::print() {
    std::cout << "SemiliconExpected : " << str << "; " << what() << "\n";
}



BraExpected::BraExpected(char* s) : InvalidSyntax(s) {}

BraExpected::BraExpected(const char* s) : InvalidSyntax(s) {}

BraExpected::BraExpected(const BraExpected& e) //����������� �����
{
    str = new char[strlen(e.str) + 1];
    std::strncpy(str, e.str, strlen(e.str) + 1);
}

void BraExpected::print() {
    std::cout << "BraExpected : " << str << "; " << what() << "\n";
}



ParExpected::ParExpected(char* s) : InvalidSyntax(s) {}

ParExpected::ParExpected(const char* s) : InvalidSyntax(s) {}

ParExpected::ParExpected(const ParExpected& e) //����������� �����
{
    str = new char[strlen(e.str) + 1];
    std::strncpy(str, e.str, strlen(e.str) + 1);
}

void ParExpected::print() {
    std::cout << "ParExpected : " << str << "; " << what() << "\n";
}