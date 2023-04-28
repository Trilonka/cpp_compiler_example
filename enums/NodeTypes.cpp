#ifndef _NODE_TYPE

#define _NODE_TYPE

enum class NodeType {
    VAR,
    INT,
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