#ifndef _NODE_TYPE

#define _NODE_TYPE

enum class NodeType {
    VAR,
    INT,
    BOOL,//
    STRING,//
    CHAR,//
    REAL,//
    CONSTINT,//
    CONSTCHAR,//
    CONSTSTRING,//
    CONSTREAL,//
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
    SET,
    IF,
    IFELSE,
    WHILE,
    DOWHILE,
    THEN,
    EMPTY,
    EXPR,
    PROG
};

#endif