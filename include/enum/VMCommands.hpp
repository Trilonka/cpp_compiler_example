#ifndef _OPERATION_TYPE

#define _OPERATION_TYPE

#include <string>
#include <map>

enum class OperationType {
    FETCHNEW,
    FETCH,
    FETCHARR,
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
    JMP,
    HALT
};

extern std::map<OperationType, std::string> operationNames;

extern std::map<std::string, OperationType> operationNamesStr;

#endif