using namespace std;
#include <iostream>
#include <vector>

class token {
public:
    int kind;
    char value;
    token(int Kind = NULL, char Value = NULL) {
        kind = Kind;
        value = Value;
    }

    ~token() {};

    void print() {
        cout << kind << ' ' << value << endl;
    }
};



class lexer {
public:

    const int IntVAR = 1; //перменная
    const int NUMBER = 2; //число
    const int IF = 3; //if
    const int ELSE = 4; //else
    const int WHILE = 5; //
    const int DO = 6; //
    const int LBRA = 7;//{
    const int RBRA = 8;//}
    const int LPAR = 9; //(
    const int RPAR = 10; //)
    const int PLUS = 11; // +
    const int MINUS = 12; // _
    const int MULTI = 13; // *
    const int DIV = 14; // /
    const int LESS = 15; // <
    const int MORE = 16; // >
    const int EQUAL = 17; // ==
    const int UnEQUAL = 18; // !=
    const int OR = 19; // or
    const int AND = 20; // and
    const int SEMICOLON = 21; // ;
    const int SET = 22; // =
    const int EOFF = 23; // конец файла

    token Token;
    vector<token> lexems;

    int count;

    lexer() {
        count = 0;
        
        cout << "lexer created";
    }

    lexer(vector<token> Lexems) {
        lexems = Lexems;
        count = 0;
        Token = lexems[count];
        cout << "lexer created";
    }

    void get_next_tok() {
        Token = lexems[count];
        count += 1;
    }
};

//узел дерева парсера
class node
{
public:
    char value;
    int kind;
    vector<node> operators;

    node(int Kind = NULL, char val = NULL) {
        kind = Kind;
        value = val;
    }

    void print() {
        cout << kind << ' ' << value;
    }

    ~node() {}

};


class Parser {
public:
    static const int IntVAR = 1; //переменная
    static const int CONST = 2; //число
    static const int ADD = 3; //сумма +
    static const int SUB = 4; //разность -  
    static const int MULTI = 5; // *
    static const int DIV = 6; // /
    static const int LT = 7; //знак меньше <
    static const int BT = 8; // >
    static const int OR = 9; // or //miss
    static const int AND = 10; //and //miss
    static const int EQUAL = 11; // ==
    static const int UnEQUAL = 12; // !=
    static const int SET = 13; // =
    static const int IF = 14; // if
    static const int IfELSE = 15; //if - else
    static const int WHILE = 16; // while
    static const int DoWHILE = 17; //do{} while()
    static const int THEN = 18; //
    static const int EMPTY = 19; //пустой знак
    static const int EXPR = 20; //выражение
    static const int PROG = 21; //программа

    lexer Lexer;

    Parser(vector<token> Lexems) {
        Lexer.lexems = Lexems;
        cout << "Parcer created";
    }

    //Первичные выражения - приоритет 1
    node primary() {

        if (Lexer.Token.kind == Lexer.LPAR) {
            node n(expression());
            Lexer.get_next_tok();
            if (Lexer.Token.kind != Lexer.RPAR) {
                cout << ") expected";
            }
            Lexer.get_next_tok();
            return n;
        }
        else if (Lexer.Token.kind == Lexer.NUMBER) {
            node n(CONST, Lexer.Token.value);
            Lexer.get_next_tok();
            return n;
        }
        else if (Lexer.Token.kind == Lexer.IntVAR) {
            node n(IntVAR, Lexer.Token.value);
            Lexer.get_next_tok();
            return n;
        }
        else
            cout << "Invalid expression syntax";
    };

    //выражения умножения и деления приориет 2
    node multiplicator() {
        node left = primary();

        if (Lexer.Token.kind == Lexer.MULTI) {
            node n(MULTI);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(primary());
            return n;
        }
        else if (Lexer.Token.kind == Lexer.DIV) {
            node n(DIV);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(primary());
            return n;
        }
        else
            return left;
    };

    //выражения + и - приеоритет 3
    node summator() {
        node left = multiplicator();

        if (Lexer.Token.kind == Lexer.PLUS) {
            node n(ADD);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(multiplicator());
            return n;
        }
        else if (Lexer.Token.kind == Lexer.MINUS) {
            node n(SUB);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(multiplicator());
            return n;
        }
        else
            return left;
    };

    //логические выражения больше меньше приоритет 4
    node logicExp() {
        node left = summator();

        if (Lexer.Token.kind == Lexer.LESS) {
            node n(LT);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(summator());
            return n;
        }
        else if (Lexer.Token.kind == Lexer.MORE) {
            node n(BT);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(summator());
            return n;
        }
        else
            return left;
    };

    //выражение равно не равно приориет 5
    node eqExp() {
        node left = logicExp();

        if (Lexer.Token.kind == Lexer.EQUAL) {
            node n(EQUAL);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(logicExp());
            return n;
        }
        else if (Lexer.Token.kind == Lexer.UnEQUAL) {
            node n(UnEQUAL);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(logicExp());
            return n;
        }
        else
            return left;


    };

    // выражения И приориет 6
    node andExp() {
        node left = eqExp();

        if (Lexer.Token.kind == Lexer.AND) {
            node n(AND);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(eqExp());
            return n;
        }
        else
            return left;

    };

    //выражение or приориет 7
    node orExp() {
        node left = andExp();

        if (Lexer.Token.kind == Lexer.OR) {
            node n(OR);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(andExp());
            return n;
        }
        else
            return left;

    };

    node expression() {
        node left = orExp();

        if (Lexer.Token.kind == Lexer.SET) {
            node n(SET);
            n.operators.push_back(left);
            Lexer.get_next_tok();
            n.operators.push_back(orExp());
            return n;
        }
        else
            return left;
    }

    //условия циклов и ифов
    node condition() {
        if (Lexer.Token.kind != Lexer.LPAR)
            cout << "( expected";

        Lexer.get_next_tok();
        node n = orExp();

        if (Lexer.Token.kind != Lexer.RPAR)
            cout << ") expected";

        return n;
    };

    //очередь выполняемых поддеревьев в различных statemant (операторах)
    node then() {
        if (Lexer.Token.kind != Lexer.LBRA)
            cout << "{ expected";

        node n(THEN);

        while (Lexer.Token.kind != Lexer.RBRA) {
            Lexer.get_next_tok();

            if (Lexer.Token.kind == Lexer.RBRA) //тут надо доработать==============================================---------------------------------------------
                break;

            if (Lexer.Token.kind == Lexer.EOFF) //скобка не закрылась а код закончился
                cout << "Invalid statement syntax";

            n.operators.push_back(statemant());

        }
        return n;
    }

    //Раздел созания оператора
    node statemant() {

        node n;
        
        //раздел с ифом
        if (Lexer.Token.kind == Lexer.IF) { //нашли иф
            
            n.kind = IF;
            Lexer.get_next_tok();

            n.operators.push_back(condition());

            Lexer.get_next_tok();
            n.operators.push_back(then());

            if (Lexer.Token.kind == Lexer.ELSE) { //нашли елсе
                n.kind = IfELSE;
                n.operators.push_back(then());
            }

            Lexer.get_next_tok();
            if (Lexer.Token.kind != Lexer.SEMICOLON)
                cout << "; expected";

        }
        //раздел с циклом while
        else if (Lexer.Token.kind == Lexer.WHILE) { //нашли цикл вайл
            n.kind = WHILE;

            Lexer.get_next_tok();
            n.operators.push_back(condition());

            Lexer.get_next_tok();
            n.operators.push_back(then());

            Lexer.get_next_tok();
            if (Lexer.Token.kind == Lexer.SEMICOLON)
                cout << "; expected";
        }
        //раздел пустого узла
        else if (Lexer.Token.kind == Lexer.SEMICOLON) {
            n.kind = EMPTY;
        }
        //раздел выражения просто выражение
        else {
            n.kind = EXPR;
            n.operators.push_back(expression());
            if (Lexer.Token.kind != Lexer.SEMICOLON)
                cout << "; expected";
        }

        //остальные разделы
        return n;

    }

    node parce() {



        node tree(PROG, NULL);

        while (Lexer.Token.kind != Lexer.EOFF) {
            Lexer.get_next_tok();
            if (Lexer.Token.kind == Lexer.EOFF)
                break;
            tree.operators.push_back(statemant());
            //надо добавить иключений
        }

        if (Lexer.Token.kind != Lexer.EOFF)
            cout << "Invalid statement syntax";

        return tree;

    }

};


void print(node root, int level = 0, node parent = NULL) {

    cout << "level: " << level << ", parent: ";
    if (level != 0) {
        parent.print();
    }
    cout << ", node: ";
    root.print();
    cout << "\n";

    int i = 0;
    while (i != root.operators.size()) {
        print(root.operators[i], level+1, root);
        i += 1;

    }

}

int main()
{

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
    token z(21, 0);

    vector<token> Lexems = { a, b, c, d, e, f, g, j, k, l ,m, n, o, p, x, y, z };

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
    
    cout << '\n';
    print(pars.parce());
}

