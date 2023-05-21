#include "Parser.hpp"

Parser::Parser(std::vector<Token> tokens) {
    this->tokens = tokens;
    Token EOFF(TokenType::EOFF, "");
    this->tokens.push_back(EOFF);
}

//Первичные выражения - приоритет 1
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
    //КОНСТАНТНЫЕ ЗНАЧЕНИЯ================------------------------
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
    //ПЕРЕМЕННЫЕ И ИХ ОБЪЯВЛЕНИЕ================------------------------
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
    //ПРОСТО ПЕРЕМЕННАЯ=================----------------------------
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

//выражения + и - приеоритет 3
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

//логические выражения больше меньше приоритет 4
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

//выражение равно не равно приориет 5
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

// выражения И приориет 6
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

//выражение or приориет 7
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



//условия циклов и ифов
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


//очередь выполняемых поддеревьев в различных statemant (операторах)
/*

Node Parser::then() {
    if (token.kind != TokenType::LBRA)
        throw BraExpected("{ expected");
    //cout << "{ expected";

    Node n(NodeType::THEN);

    get_next_token();
    while (token.kind != TokenType::RBRA) {

        if (token.kind == TokenType::EOFF) //скобка не закрылась а код закончился
            throw InvalidSyntax("Invalid statement syntax");

        n.operators.push_back(statemant());

    }
    return n;
}*/

//Раздел созания оператора
Node Parser::statemant() {

    Node n;

    //раздел с ифом
    if (token.kind == TokenType::IF) { //нашли иф

        n.kind = NodeType::IF;
        get_next_token();

        n.operators.push_back(condition());

        get_next_token();
        n.operators.push_back(statemant());

        if (token.kind == TokenType::ELSE) { //нашли елсе
            n.kind = NodeType::IFELSE;
            n.operators.push_back(statemant());
        }

        //get_next_token();

        //if (token.kind != TokenType::SEMICOLON)
            //throw SemiliconExpected("; expected");

        //get_next_token();

    }
    //раздел с циклом while
    else if (token.kind == TokenType::WHILE) { //нашли цикл вайл
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

    //раздел с for
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
        get_next_token();
        n.operators.push_back(forNode);
    }

    //раздел пустого узла
    else if (token.kind == TokenType::SEMICOLON) {
        n.kind = NodeType::EMPTY;
    }
    //==============================================-------------------------------------------
    else if (token.kind == TokenType::LBRA) {
        n.kind = NodeType::THEN;
        get_next_token();
        while (token.kind != TokenType::RBRA) {

            if (token.kind == TokenType::EOFF) //скобка не закрылась а код закончился
                throw InvalidSyntax("Invalid statement syntax");

            n.operators.push_back(statemant());

        }

        get_next_token();

        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");

        get_next_token();

        return n;

    }

    //==============================================-------------------------------------------
    //раздел выражения просто выражение
    else {
        n.kind = NodeType::EXPR;
        n.operators.push_back(expression());

        if (token.kind != TokenType::SEMICOLON)
            throw SemiliconExpected("; expected");

        get_next_token(); 

    }

    //остальные разделы
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
