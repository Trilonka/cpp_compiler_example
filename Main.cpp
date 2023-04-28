using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

#include "Lexer.cpp"
#include "Parser.cpp"
#include "Compiler.cpp"
#include "VirtualMachine.cpp"

int main(int argc, char *argv[])
{
    char *fileName = argv[1];

    // std::ifstream file(fileName);
    // std::string userProgram((std::istreambuf_iterator<char>(file)),
    //              std::istreambuf_iterator<char>());

    std::string userProgram = "int a = 3; int b = 4; a = a + b;";

    cout << userProgram << "\n\n\n\n";

    Lexer lexer(userProgram);
    lexer.tokenize();
    cout << "lexer\n\n\n";
    Parser parser(lexer.lexems);
    Compiler compiler;
    VirtualMachine vm;

    parser.parse();
    cout << "parser\n\n\n";

    vm.run(compiler.compile(parser.parse()));
}