#ifndef _OPERATION_TYPE

#define _OPERATION_TYPE

#include <string>
#include <map>

enum class OperationType {
    FETCHNEW,
    FETCH,
    FETCHARR,
    FETCHARRFILL,
    FETCHELEMENT,
    UNFETCH,
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
    PRINT,
    READ,
    JZ,
    JNZ,
    GOTO,
    HALT
};

extern std::map<OperationType, std::string> operation_to_string;

extern std::map<std::string, OperationType> string_to_operation;

#endif