#include <iostream>

#include "Main.hpp"

int main() {
    Lexer lexer("int a = 4; int b = 10; a = a + b;");
    lexer.tokenize();

    Parser parser(lexer.lexems);
    Compiler compiler;
    VirtualMachine vm;

    compiler.compile(parser.parse());
    vm.run(compiler.program);
}