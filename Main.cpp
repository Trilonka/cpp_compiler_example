#include <iostream>

#include "Main.hpp"

void print(Node root, int& count, int& turn) {

    int i = 0;

    while (i != root.operators.size()) {

        count += 1;
        print(root.operators[i], count, i);

        i += 1;
        if (i == root.operators.size()) cout << "|\n|\n|\n*";

    }
    root.print();
    cout << "layer = " << count + 1 << " turn = " << turn + 1 << " : ";
    root.print();

    count -= 1;
}

int main() {
    Lexer lexer("int a = 2; for(int i = 0; i < 10; i = i + 1) a = a + 1;");
    lexer.tokenize();

    Parser parser(lexer.lexems);
    Compiler compiler;
    VirtualMachine vm;
    int i = 0; int j = 0;
    print(parser.parse(), i, j);

    compiler.compile(parser.parse());
    vm.run(compiler.program);
    char c; std::cin >> c;
}