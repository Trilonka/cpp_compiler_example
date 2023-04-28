#ifndef _PARSER

#define _PARSER

using namespace std;

#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <string.h>

#include "exception/ParserExceptions.cpp"
#include "Token.cpp"
#include "Lexer.cpp"
#include "Node.cpp"
#include "enums/NodeTypes.cpp"
#include "enums/TokenTypes.cpp"

class Parser {
public:

    vector<Token> tokens;
    Token token;
    int tokenIndex = 0;

    Parser(vector<Token> tokens) {
        this->tokens = tokens;
        cout << "Parcer created";
    }

    //Первичные выражения - приоритет 1
    Node primary() {

        if (token.kind == TokenType::LPAR) {
            get_next_token();
            Node n(expression());
            //get_next_token();
            if (token.kind != TokenType::RPAR) {
                throw ParExpected(") expected");
            }
            get_next_token();
            return n;
        }
        else if (token.kind == TokenType::NUMBER) {
            Node n(NodeType::INT, token.value);
            get_next_token();
            return n;
        }
        else if (token.kind == TokenType::VAR) {
            Node n(NodeType::VAR, token.value);
            get_next_token();
            return n;
        }
        else
            throw InvalidSyntax("Invalid expression syntax");
            //cout << "Invalid expression syntax";
    };

    //выражения умножения и деления приориет 2
    Node multiplicator() {
        Node left = primary();

        if (token.kind == TokenType::MULTI) {
            Node n(NodeType::MULTI);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(primary());
            return n;
        }
        else if (token.kind == TokenType::DIV) {
            Node n(NodeType::DIV);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(primary());
            return n;
        }
        else
            return left;
    };

    //выражения + и - приеоритет 3
    Node summator() {
        Node left = multiplicator();

        if (token.kind == TokenType::PLUS) {
            Node n(NodeType::PLUS);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(multiplicator());
            return n;
        }
        else if (token.kind == TokenType::MINUS) {
            Node n(NodeType::MINUS);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(multiplicator());
            return n;
        }
        else
            return left;
    };

    //логические выражения больше меньше приоритет 4
    Node logicExp() {
        Node left = summator();

        if (token.kind == TokenType::LESS) {
            Node n(NodeType::LT);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(summator());
            return n;
        }
        else if (token.kind == TokenType::MORE) {
            Node n(NodeType::BT);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(summator());
            return n;
        }
        else
            return left;
    };

    //выражение равно не равно приориет 5
    Node eqExp() {
        Node left = logicExp();

        if (token.kind == TokenType::ASSIGMENT) {
            Node n(NodeType::EQUAL);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(logicExp());
            return n;
        }
        else if (token.kind == TokenType::UNEQUAL) {
            Node n(NodeType::UNEQUAL);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(logicExp());
            return n;
        }
        else
            return left;


    };

    // выражения И приориет 6
    Node andExp() {
        Node left = eqExp();

        if (token.kind == TokenType::AND) {
            Node n(NodeType::AND);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(eqExp());
            return n;
        }
        else
            return left;

    };

    //выражение or приориет 7
    Node orExp() {
        Node left = andExp();

        if (token.kind == TokenType::OR) {
            Node n(NodeType::OR);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(andExp());
            return n;
        }
        else
            return left;

    };

    Node expression() {
        Node left = orExp();

        if (token.kind == TokenType::ASSIGMENT) {
            Node n(NodeType::SET);
            n.operators.push_back(left);
            get_next_token();
            n.operators.push_back(orExp());
            return n;
        }
        else
            return left;
    }

    //условия циклов и ифов
    Node condition() {
        if (token.kind != TokenType::LPAR)
            throw ParExpected("( expected");
            //cout << "( expected";

        get_next_token();
        Node n = orExp();

        if (token.kind != TokenType::RPAR)
            throw ParExpected(") expected");
            //cout << ") expected";

        return n;
    };

    //очередь выполняемых поддеревьев в различных statemant (операторах)
    Node then() {
        if (token.kind != TokenType::LBRA)
            throw BraExpected("{ expected");
            //cout << "{ expected";

        Node n(NodeType::THEN);

        while (token.kind != TokenType::RBRA) {
            get_next_token();

            //if (token.kind == TokenType::RBRA) //тут надо доработать==============================================---------------------------------------------
                //break;

            if (token.kind == TokenType::EOFF) //скобка не закрылась а код закончился
                throw InvalidSyntax("Invalid statement syntax");
                //cout << "Invalid statement syntax";

            n.operators.push_back(statemant());

        }
        return n;
    }

    //Раздел созания оператора
    Node statemant() {

        Node n;

        //раздел с ифом
        if (token.kind == TokenType::IF) { //нашли иф
            
            n.kind = NodeType::IF;
            get_next_token();

            n.operators.push_back(condition());

            get_next_token();
            n.operators.push_back(then());

            if (token.kind == TokenType::ELSE) { //нашли елсе
                n.kind = NodeType::IFELSE;
                n.operators.push_back(then());
            }

            get_next_token();
            if (token.kind != TokenType::SEMICOLON)
                throw SemiliconExpected("; expected");
                //cout << "; expected";
            get_next_token();

        }
        //раздел с циклом while
        else if (token.kind == TokenType::WHILE) { //нашли цикл вайл
            n.kind = NodeType::WHILE;

            get_next_token();
            n.operators.push_back(condition());

            get_next_token();
            n.operators.push_back(then());

            get_next_token();
            if (token.kind == TokenType::SEMICOLON)
                throw SemiliconExpected("; expected");
                //cout << "; expected";
            get_next_token();// ===========================================--------------------------------------
        }
        //раздел пустого узла
        else if (token.kind == TokenType::SEMICOLON) {
            n.kind = NodeType::EMPTY;
        }
        //раздел выражения просто выражение
        else {
            n.kind = NodeType::EXPR;
            n.operators.push_back(expression());
            if (token.kind != TokenType::SEMICOLON)
                throw SemiliconExpected("; expected");
                //cout << "; expected";
            get_next_token(); // ==========================================--------------------------------

        }

        //остальные разделы
        return n;

    }

    Node parse() {
        Node tree(NodeType::PROG, "");

        while (tokenIndex < tokens.size()) {
            get_next_token();
            if (token.kind == TokenType::INT || token.kind == TokenType::BOOL) {
                continue;
            } else {
                tree.operators.push_back(statemant());
            }
        }

        if (token.kind != TokenType::EOFF)
            throw InvalidSyntax("Invalid statement syntax");
            //cout << "Invalid statement syntax";

        return tree;
    }

    void get_next_token() {
        token = tokens[tokenIndex++];
    }
};

#endif