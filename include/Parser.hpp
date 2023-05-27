#ifndef _PARSER

#define _PARSER

#include <iostream>
#include <vector>
#include <string>

#include "exception/ParserExceptions.hpp"
#include "Token.hpp"
#include "Lexer.hpp"
#include "Node.hpp"
#include "enum/NodeTypes.hpp"
#include "enum/TokenTypes.hpp"

class Parser {
public:

    std::vector<Token> tokens;
    Token token;
    int tokenIndex = 0;

    Parser(std::vector<Token> tokens);

    //Первичные выражения - приоритет 1
    Node primary();

    //выражения умножения и деления приориет 2
    Node multiplicator();

    //выражения + и - приеоритет 3
    Node summator();

    //логические выражения больше меньше приоритет 4
    Node logicExp();

    //выражение равно не равно приориет 5
    Node eqExp();

    // выражения И приориет 6
    Node andExp();

    //выражение or приориет 7
    Node orExp();

    Node expression();

    //условия циклов и ифов
    Node condition();

    //очередь выполняемых поддеревьев в различных statemant (операторах)
    Node then();

    void arrayInit(Node &n);

    //Раздел созания оператора
    Node statemant();

    Node parse();

    void get_next_token();
};

//печать итога парсинга
inline void printTree(Node root, int& count, int& turn) {

    int i = 0;

    while (i != root.operators.size()) {

        count += 1;
        printTree(root.operators[i], count, i);

        i += 1;
        if (i == root.operators.size()) std::cout << "|\n|\n|\n*";

    }
    //root.print();
    std::cout << "layer = " << count + 1 << " turn = " << turn + 1 << " : ";
    root.print();

    count -= 1;
}

#endif