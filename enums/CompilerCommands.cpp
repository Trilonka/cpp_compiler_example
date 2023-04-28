#ifndef _OPERATION_TYPE

#define _OPERATION_TYPE

enum class OperationType {
    FETCH,
    STORE,
    PUSH,
    POP,
    ADD,
    SUB,
    MULTI,
    DIV,
    LT,
    BT,
    EQUAL,
    NONEQUAL,
    JZ,
    JNZ,
    JMP,
    HALT
};

#endif