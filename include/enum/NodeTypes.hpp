#ifndef _NODE_TYPE

#define _NODE_TYPE

enum class NodeType {
    VAR,

    //типы данных
    INT,
    BOOL,//
    STRING,//
    CHAR,// 4
    REAL,//

    //статические массивы
    INTARR,
    BOOLARR,
    CHARARR,
    REALARR,

    //константные значения
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

    SET, //
    IF, //
    IFELSE,
    WHILE,
    DOWHILE,
    FOR,
    THEN,//

    PRINT,
    READ,

    EMPTY,
    EXPR,//
    PROG//
};

#endif