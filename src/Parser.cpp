#include "Parser.hpp"

Parser::Parser(std::vector<Token> tokens) {
    this->tokens = tokens;
    Token EOFF(TokenType::EOFF, "");
    this->tokens.push_back(EOFF);
}

//��������� ��������� - ��������� 1
Node Parser::primary() {

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
    //����������� ��������================------------------------
    else if (token.kind == TokenType::NUMBER) {
        Node n(NodeType::CONSTINT, token.value);
        get_next_token();
        return n;
    }
    else if (token.kind == TokenType::CHARACTER) {
        Node n(NodeType::CONSTCHAR, token.value);
        get_next_token();
        return n;
    }
    else if (token.kind == TokenType::REAL) {
        Node n(NodeType::CONSTREAL, token.value);
        get_next_token();
        return n;
    }
    else if (token.kind == TokenType::CONSTSTRING) {
        Node n(NodeType::CONSTSTRING, token.value);
        get_next_token();
        return n;
    }
    //���������� � �� ����������================------------------------
    else if (token.kind == TokenType::INT) {
        Node n(NodeType::INT);
        get_next_token();
        if (token.kind != TokenType::VAR)
            throw InvalidSyntax("Invalid Initialization syntax");
        n.value = token.value;
        get_next_token();
        return n;
    }
    else if (token.kind == TokenType::BOOL) {
        Node n(NodeType::BOOL);
        get_next_token();
        if (token.kind != TokenType::VAR)
            throw InvalidSyntax("Invalid Initialization syntax");
        n.value = token.value;
        get_next_token();
        return n;
    }
    else if (token.kind == TokenType::STRING) {
        Node n(NodeType::STRING);
        get_next_token();
        if (token.kind != TokenType::VAR)
            throw InvalidSyntax("Invalid Initialization syntax");
        n.value = token.value;
        get_next_token();
        return n;
    }
    else if (token.kind == TokenType::CHAR) {
        Node n(NodeType::CHAR);
        get_next_token();
        if (token.kind != TokenType::VAR)
            throw InvalidSyntax("Invalid Initialization syntax");
        n.value = token.value;
        get_next_token();
        return n;
    }
    //������ ����������=================----------------------------
    else if (token.kind == TokenType::VAR) {
        Node n(NodeType::VAR, token.value);
        get_next_token();
        return n;
    }
    else
        throw InvalidSyntax("Invalid expression syntax");
    //cout << "Invalid expression syntax";
};

//��������� ��������� � ������� �������� 2
Node Parser::multiplicator() {
    Node left = primary();

    if (token.kind == TokenType::MULTI) {
        Node n(NodeType::MULTI);
        n.operators.push_back(left);
        get_next_token();
        n.operators.push_back(multiplicator());
        return n;
    }
    else if (token.kind == TokenType::DIV) {
        Node n(NodeType::DIV);
        n.operators.push_back(left);
        get_next_token();
        n.operators.push_back(multiplicator());
        return n;
    }
    else
        return left;
};

//��������� + � - ���������� 3
Node Parser::summator() {
    Node left = multiplicator();

    if (token.kind == TokenType::PLUS) {
        Node n(NodeType::PLUS);
        n.operators.push_back(left);
        get_next_token();
        n.operators.push_back(summator());
        return n;
    }
    else if (token.kind == TokenType::MINUS) {
        Node n(NodeType::MINUS);
        n.operators.push_back(left);
        get_next_token();
        n.operators.push_back(summator());
        return n;
    }
    else
        return left;
};

//���������� ��������� ������ ������ ��������� 4
Node Parser::logicExp() {
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

//��������� ����� �� ����� �������� 5
Node Parser::eqExp() {
    Node left = logicExp();

    if (token.kind == TokenType::EQUAL) {
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

// ��������� � �������� 6
Node Parser::andExp() {
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

//��������� or �������� 7
Node Parser::orExp() {
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

Node Parser::expression() {
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

//������� ������ � ����
Node Parser::condition() {
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

//������� ����������� ����������� � ��������� statemant (����������)
Node Parser::then() {
    if (token.kind != TokenType::LBRA)
        throw BraExpected("{ expected");
    //cout << "{ expected";

    Node n(NodeType::THEN);

    get_next_token();
    while (token.kind != TokenType::RBRA) {
        //get_next_token();

        //if (token.kind == TokenType::RBRA) //��� ���� ����������==============================================---------------------------------------------
            //break;

        if (token.kind == TokenType::EOFF) //������ �� ��������� � ��� ����������
            throw InvalidSyntax("Invalid statement syntax");
        //cout << "Invalid statement syntax";

        n.operators.push_back(statemant());

    }
    return n;
}

//������ ������� ���������
Node Parser::statemant() {

    Node n;

    //������ � ����
    if (token.kind == TokenType::IF) { //����� ��

        n.kind = NodeType::IF;
        get_next_token();

        n.operators.push_back(condition());

        get_next_token();
        n.operators.push_back(then());

        if (token.kind == TokenType::ELSE) { //����� ����
            n.kind = NodeType::IFELSE;
            n.operators.push_back(then());
        }

        get_next_token();
        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");
        //cout << "; expected";
        get_next_token();

    }
    //������ � ������ while
    else if (token.kind == TokenType::WHILE) { //����� ���� ����
        n.kind = NodeType::WHILE;

        get_next_token();
        n.operators.push_back(condition());

        get_next_token();
        n.operators.push_back(then());

        get_next_token();
        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");
        //cout << "; expected";
        get_next_token();// ===========================================--------------------------------------
    }
    //������ ������� ����
    else if (token.kind == TokenType::SEMICOLON) {
        n.kind = NodeType::EMPTY;
    }
    //������ ��������� ������ ���������
    else {
        n.kind = NodeType::EXPR;
        n.operators.push_back(expression());
        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");
        //cout << "; expected";
        get_next_token(); // ==========================================--------------------------------

    }

    //��������� �������
    return n;

}

Node Parser::parse() {

    Node tree(NodeType::PROG, "");
    get_next_token();

    while (token.kind != TokenType::EOFF) {
        tree.operators.push_back(statemant());
    }


    if (token.kind != TokenType::EOFF)
        throw InvalidSyntax("Invalid statement syntax");
    //cout << "Invalid statement syntax";

    tokenIndex = 0;
    return tree;
}

void Parser::get_next_token() {
    token = tokens[tokenIndex++];
}
