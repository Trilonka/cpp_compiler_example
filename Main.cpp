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

    //std::string userProgram = "int a = 3; int b = 4; a = a + b;";
    //std::string userProgram = "int a = 3; if(a < 2){a = a + 1; int b = 4; b = a + b;};";
    std::string userProgram = "int a = 1; while(a<6){a=a+1;};";

    cout << userProgram << "\n\n\n\n";

    cout << userProgram << "\n\n\n";

    Lexer lexer(userProgram);
    lexer.tokenize();
    cout << "<<<< lexer good >>>>\n\n";

    Parser parser(lexer.lexems);
    Compiler compiler;
    VirtualMachine vm;

    cout << "<<<<<< Parser tree:\n\n";
    int count = 0; int turn = 0;
    print(parser.parse(), count, turn);
    cout << "Parser tree ending >>>>>>>>\n\n";

    vm.run(compiler.compile(parser.parse()));
}