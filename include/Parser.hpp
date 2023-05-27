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

    //��������� ��������� - ��������� 1
    Node primary();

    //��������� ��������� � ������� �������� 2
    Node multiplicator();

    //��������� + � - ���������� 3
    Node summator();

    //���������� ��������� ������ ������ ��������� 4
    Node logicExp();

    //��������� ����� �� ����� �������� 5
    Node eqExp();

    // ��������� � �������� 6
    Node andExp();

    //��������� or �������� 7
    Node orExp();

    Node expression();

    //������� ������ � ����
    Node condition();

    //������� ����������� ����������� � ��������� statemant (����������)
    Node then();

    void arrayInit(Node &n);

    //������ ������� ���������
    Node statemant();

    Node parse();

    void get_next_token();
};

//������ ����� ��������
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