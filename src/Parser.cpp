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

        if (token.kind == TokenType::LSQBRA) {
            n.kind = NodeType::INTARR;
            get_next_token();
            if(token.kind != TokenType::NUMBER)
                throw InvalidSyntax("Invalid Initialization syntax");
            n.operators.push_back(primary());
            
            if (token.kind != TokenType::RSQBRA)
                throw InvalidSyntax("] expected");
            get_next_token();
        }

        return n;
    }
    else if (token.kind == TokenType::BOOL) {
        Node n(NodeType::BOOL);
        get_next_token();
        if (token.kind != TokenType::VAR)
            throw InvalidSyntax("Invalid Initialization syntax");
        n.value = token.value;
        get_next_token();

        if (token.kind == TokenType::LSQBRA) {
            n.kind = NodeType::INTARR;
            get_next_token();
            if (token.kind != TokenType::NUMBER)
                throw InvalidSyntax("Invalid Initialization syntax");
            n.operators.push_back(primary());

            if (token.kind != TokenType::RSQBRA)
                throw InvalidSyntax("] expected");
            get_next_token();
        }

        return n;
    }
    else if (token.kind == TokenType::STRING) {
        Node n(NodeType::STRING);
        get_next_token();
        if (token.kind != TokenType::VAR)
            throw InvalidSyntax("Invalid Initialization syntax");
        n.value = token.value;
        get_next_token();

        if (token.kind == TokenType::LSQBRA) {
            n.kind = NodeType::INTARR;
            get_next_token();
            if (token.kind != TokenType::NUMBER)
                throw InvalidSyntax("Invalid Initialization syntax");
            n.operators.push_back(primary());

            if (token.kind != TokenType::RSQBRA)
                throw InvalidSyntax("] expected");
            get_next_token();
        }

        return n;
    }
    else if (token.kind == TokenType::CHAR) {
        Node n(NodeType::CHAR);
        get_next_token();
        if (token.kind != TokenType::VAR)
            throw InvalidSyntax("Invalid Initialization syntax");
        n.value = token.value;
        get_next_token();

        if (token.kind == TokenType::LSQBRA) {
            n.kind = NodeType::INTARR;
            get_next_token();
            if (token.kind != TokenType::NUMBER)
                throw InvalidSyntax("Invalid Initialization syntax");
            n.operators.push_back(primary());

            if (token.kind != TokenType::RSQBRA)
                throw InvalidSyntax("] expected");
            get_next_token();
        }

        return n;
    }
    //������ ����������=================----------------------------
    else if (token.kind == TokenType::VAR) {
        Node n(NodeType::VAR, token.value);
        get_next_token();

        if (token.kind == TokenType::LSQBRA) {
            get_next_token();
            if (token.kind != TokenType::NUMBER)
                throw InvalidSyntax("Invalid Initialization syntax");
            n.operators.push_back(primary());

            if (token.kind != TokenType::RSQBRA)
                throw InvalidSyntax("] expected");
            get_next_token();
        }

        return n;
    }
    else
        throw InvalidSyntax("Invalid expression syntax");
    //cout << "Invalid expression syntax";
};

//��������� ��������� � ������� �������� 2
Node Parser::multiplicator() {
    Node left = primary();

    while (token.kind == TokenType::MULTI || token.kind == TokenType::DIV) {

        Node n;

        if (token.kind == TokenType::MULTI)
            n.kind = NodeType::MULTI;
  
        else if (token.kind == TokenType::DIV) 
            n.kind = NodeType::DIV;
            
        n.operators.push_back(left);
        get_next_token();
        n.operators.push_back(primary());
        
        left = n;
    }
    return left;
};

//��������� + � - ���������� 3
Node Parser::summator() {
    Node left = multiplicator();
    

    while (token.kind == TokenType::PLUS || token.kind == TokenType::MINUS) {

        Node n;

        if (token.kind == TokenType::PLUS) 
            n.kind = NodeType::PLUS;

        else if (token.kind == TokenType::MINUS) 
            n.kind = NodeType::MINUS;

        n.operators.push_back(left);
        get_next_token();
        n.operators.push_back(multiplicator());
        
        left = n;
   
    }

    return left;

};

//���������� ��������� ������ ������ ��������� 4
Node Parser::logicExp() { //ERROR ====================================================
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
Node Parser::eqExp() { //ERROR ====================================================
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
/*

Node Parser::then() {
    if (token.kind != TokenType::LBRA)
        throw BraExpected("{ expected");
    //cout << "{ expected";

    Node n(NodeType::THEN);

    get_next_token();
    while (token.kind != TokenType::RBRA) {

        if (token.kind == TokenType::EOFF) //������ �� ��������� � ��� ����������
            throw InvalidSyntax("Invalid statement syntax");

        n.operators.push_back(statemant());

    }
    return n;
}*/

//������ ������� ���������
Node Parser::statemant() {

    Node n;

    //������ � ����
    if (token.kind == TokenType::IF) { //����� ��

        n.kind = NodeType::IF;
        get_next_token();

        n.operators.push_back(condition());

        get_next_token();
        n.operators.push_back(statemant());

        if (token.kind == TokenType::ELSE) { //����� ����
            n.kind = NodeType::IFELSE;
            n.operators.push_back(statemant());
        }

        //get_next_token();

        //if (token.kind != TokenType::SEMICOLON)
            //throw SemiliconExpected("; expected");

        //get_next_token();

    }
    //������ � ������ while
    else if (token.kind == TokenType::WHILE) { //����� ���� ����
        n.kind = NodeType::WHILE;

        get_next_token();
        n.operators.push_back(condition());

        get_next_token();
        n.operators.push_back(statemant());

        //get_next_token();

        //if (token.kind != TokenType::SEMICOLON)
            //throw SemiliconExpected("; expected");

        //get_next_token();
    }

    //������ � for
    else if (token.kind == TokenType::FOR) {
        n.kind = NodeType::THEN;
        Node forNode(NodeType::FOR);

        get_next_token();

        if (token.kind != TokenType::LPAR)
            throw ParExpected("( expected");

        get_next_token();

        Node temp_1(NodeType::EXPR);
        temp_1.operators.push_back(expression());
        forNode.operators.push_back(temp_1);

        if(token.kind != TokenType::SEMICOLON)
            throw InvalidSyntax("Invalid FOR syntax ; expected");
        get_next_token();

        forNode.operators.push_back(orExp());

        if (token.kind != TokenType::SEMICOLON)
            throw InvalidSyntax("Invalid FOR syntax ; expected");
        get_next_token();

        Node temp_2(NodeType::EXPR);
        temp_2.operators.push_back(expression());
        forNode.operators.push_back(temp_2);


        if (token.kind != TokenType::RPAR)
            throw ParExpected(") expected");
        get_next_token();

        forNode.operators.insert(forNode.operators.end() - 1, statemant());

        n.operators.push_back(forNode);
    }

    //������ ������� ����
    else if (token.kind == TokenType::SEMICOLON) {
        n.kind = NodeType::EMPTY;
        get_next_token();
    }
    //==============================================-------------------------------------------
    else if (token.kind == TokenType::LBRA) {
        n.kind = NodeType::THEN;
        get_next_token();
        while (token.kind != TokenType::RBRA) {

            if (token.kind == TokenType::EOFF) //������ �� ��������� � ��� ����������
                throw InvalidSyntax("Invalid statement syntax");

            n.operators.push_back(statemant());

        }

        get_next_token();

        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");

        get_next_token();

        return n;

    }

    else if (token.kind == TokenType::PRINT) {
        n.kind = NodeType::PRINT;

        get_next_token();

        if (token.kind != TokenType::LPAR)
            throw ParExpected("( expected");

        get_next_token();

        while (token.kind != TokenType::RPAR) {

            if (token.kind == TokenType::EOFF) //������ �� ��������� � ��� ����������
                throw InvalidSyntax("Invalid print syntax");

            Node temp(NodeType::EXPR);
            temp.operators.push_back(expression());
            n.operators.push_back(temp);

            if(token.kind != TokenType::COMMA && token.kind != TokenType::RPAR)
                throw InvalidSyntax("Invalid print syntax");

            if (token.kind == TokenType::COMMA)
                get_next_token();
        }
        
        get_next_token();

        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");

        get_next_token();

    }
    
    else if (token.kind == TokenType::READ) {
        n.kind = NodeType::READ;

        get_next_token();

        if (token.kind != TokenType::LPAR)
            throw ParExpected("( expected");

        get_next_token();

        while (token.kind != TokenType::RPAR) {

            if (token.kind == TokenType::EOFF) //������ �� ��������� � ��� ����������
                throw InvalidSyntax("Invalid print syntax");

            n.operators.push_back(primary());

            if (token.kind != TokenType::COMMA && token.kind != TokenType::RPAR)
                throw InvalidSyntax("Invalid print syntax");

            if (token.kind == TokenType::COMMA)
                get_next_token();
        }

        get_next_token();

        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");

        get_next_token();


    }

    //==============================================-------------------------------------------
    //������ ��������� ������ ���������
    else {
        n.kind = NodeType::EXPR;
        n.operators.push_back(expression());

        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");

        get_next_token(); 

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

    tokenIndex = 0;
    return tree;
}

void Parser::get_next_token() {
    token = tokens[tokenIndex++];
}
