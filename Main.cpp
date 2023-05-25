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



        Lexer lexer;
        //("int a = 1; int b = 2; for(int i = 0; i < 10; i = i + 1) a = a + b + i; int f = 12; if(a > b){ b = b + f; f = 0;}; string s = \"kek\"; for(int i = 0; i < 5; i = i + 1) {f = f - 1;}; a = a + 100;");

        std::ifstream fin("C:\\Users\\1\\Desktop\\Âóç\\Programm progect\\GitHub\\cpp_compiler_example\\tests\\calc_test_4.das");

        if (fin)
        {
            fin >> lexer;
            fin.close();
        }

        std::vector<std::string> l = lexer.tokenize();

        Parser parser(lexer.lexems);
        Compiler compiler;
        VirtualMachine vm;

        int i = 0; int j = 0;
        print(parser.parse(), i, j);

        compiler.compile(parser.parse());
        vm.run(compiler.program);

        char c; std::cin >> c;
    }
    catch (VariableNotExistsException e)
    {
        e.print();
    }
    catch (InvalidSyntax e)
    {
        e.print();
    }
    catch (SemiliconExpected e)
    {
        e.print();
    }
    catch (BraExpected e)
    {
        e.print();
    }
    catch (ParExpected e)
    {
        e.print();
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