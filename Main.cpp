#include <iostream>
#include <fstream>

#include "Main.hpp"

int main(int argc, char* argv[]) {

    try
    {
        Lexer lexer;

        if (argc < 2) {
            std::cout << "File name required!\n";
            exit(1);
        }

        std::ifstream fin(argv[1]);

        if (fin)
        {
            fin >> lexer;
            fin.close();
        }

        std::vector<std::string> l = lexer.tokenize();

        Parser parser(lexer.lexems);
        Compiler compiler;
        VirtualMachine vm;

        compiler.compile(parser.parse());
        vm.run(compiler.program);
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