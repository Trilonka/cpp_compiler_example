#include <iostream>

#include "Main.hpp"

int main() {
    Lexer lexer("int a = 4;");
    lexer.tokenize();

    Parser parser(lexer.lexems);
    Compiler compiler;
    VirtualMachine vm;

    compiler.compile(parser.parse());
    vm.run(compiler.program);
}