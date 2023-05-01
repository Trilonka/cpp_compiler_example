#ifndef _NODE_TYPE

#define _NODE_TYPE

enum class NodeType {
    VAR,
    INT,
    BOOL,//
    STRING,//
    CHAR,// 4
    REAL,//

    CONSTINT,//6
    CONSTCHAR,//
    CONSTSTRING,//
    CONSTREAL,// 9

    PLUS,
    MINUS,
    MULTI,
    DIV,

    LT,
    BT,
    OR,
    AND,
    EQUAL,
    UNEQUAL,
    
    SET, //20
    IF, //21
    IFELSE,
    WHILE,
    DOWHILE,
    THEN,//25
    
    EMPTY,
    EXPR,//27
    PROG//28
};

#endif