using namespace std;

#include "./Compiler/Compiler.cpp"
#include "./VM/VirtualMachine.cpp"

int main()
{
    /*
    token a(3, 0);
    token b(9, 0);
    token c(1, 'a');
    token d(15, 0);
    token e(1, 'b');
    token f(10, 0);
    token g(7, 0);
    token j(1, 'a');
    token k(22, 0);
    token l(1, 'a');
    token m(11, 0);
    token n(1, 'b');
    token o(21, 0);
    token p(8, 0);
    token x(21, 0);
    token y(23, 0);
    vector<token> Lexems = { a, b, c, d, e, f, g, j, k, l ,m, n, o, p, x, y};
    */
    
    token a(1, 'a');
    token b(22, 0);
    token c(9, 0);
    token d(2, 3);
    token e(11, 0);
    token f(2, 1);
    token g(10, 0);
    token j(13, 0);
    token k(2, 2);
    token l(21, 0);
    token m(23, 0);
    vector<token> Lexems = { a, b, c, d, e, f, g, j, k, l, m};

    // token a(1, 'a');
    // token b(13, 0);
    // token c(2, 43);
    // token cc(21, 0);
    // token d(1, 'b');
    // token e(13, 0);
    // token f(2, 77);
    // token ff(21, 0);

    // vector<token> Lexems = { a, b, c, cc, d, e, f, ff };

    Parser pars(Lexems);

    Compiler comp;

    VirtualMachine vm;

    vm.run(comp.compile(pars.parce()));
    
    
}