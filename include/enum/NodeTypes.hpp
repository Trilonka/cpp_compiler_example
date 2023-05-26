#ifndef _NODE_TYPE

#define _NODE_TYPE

enum class NodeType {
    VAR,

    //���� ������
    INT,
    BOOL,//
    STRING,//
    CHAR,// 4
    REAL,//

    //����������� �������
    INTARR,
    BOOLARR,
    CHARARR,
    REALARR,

    //����������� ��������
    CONSTINT,//6
    CONSTCHAR,//
    CONSTSTRING,//
    CONSTREAL,// 9
    CONSTBOOL,

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