#ifndef _NODE_TYPE

#define _NODE_TYPE

enum class NodeType {
    //Переменная
    VAR,

    //Типы данных
    INT,
    BOOL,//
    STRING,//
    CHAR,// 4
    REAL,//

    //Инициализация массивов
    INTARR,
    BOOLARR,
    CHARARR,
    REALARR,

    //Константные значения
    CONSTINT,//6
    CONSTCHAR,//
    CONSTSTRING,//
    CONSTREAL,// 9
    CONSTBOOL,

    PLUS,
    MINUS,
    MULTI,
    DIV,
    MOD,

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
    PRINTLN,
    READ,

    EMPTY,
    EXPR,//
    PROG//
};

#endif