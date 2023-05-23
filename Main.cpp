#pragma once

#include <iostream>
#include <fstream>

#include "Main.hpp"

void print(Node root, int& count, int& turn) {

    int i = 0;

    while (i != root.operators.size()) {

        count += 1;
        print(root.operators[i], count, i);

        i += 1;
        if (i == root.operators.size()) cout << "|\n|\n|\n*";

    }
    //root.print();
    cout << "layer = " << count + 1 << " turn = " << turn + 1 << " : ";
    root.print();

    count -= 1;
}

int main() {

    try
    {
        Lexer lexer("int a = 1; while (a < 3) {a = a + 1; int b = 4; b = a + b;};");

        /*std::ifstream fin("D:\\Source\\Repos\\cpp_compiler_example\\test.txt");

        if (fin)
        {
            fin >> lexer;
            fin.close();
        }*/

        std::vector<std::string> l = lexer.tokenize();

        Parser parser(lexer.lexems);
        Compiler compiler;
        VirtualMachine vm;
        int i = 0; int j = 0;
        //print(parser.parse(), i, j);

        compiler.compile(parser.parse());
        vm.run(compiler.program);

        char c; std::cin >> c;
    }
    catch (UnknownSymbolException e)
    {
        e.print();
    }
    catch (Exception e)
    {
        e.print();
    }
}