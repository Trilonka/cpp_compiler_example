#ifndef _OPERATION_TYPE

#define _OPERATION_TYPE

#include <string>
#include <map>

enum class OperationType {
    FETCHNEW,
    FETCH,
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
    JZ,
    JNZ,
    JMP,
    HALT
};

std::map<OperationType, std::string> operationNames {
    {OperationType::FETCHNEW, "FETCHNEW"},
    {OperationType::FETCH, "FETCH"},
    {OperationType::UNFETCH, "UNFETCH"},
    {OperationType::STORE, "STORE"},
    {OperationType::PUSH, "PUSH"},
    {OperationType::POP, "POP"},
    {OperationType::ADD, "ADD"},
    {OperationType::SUB, "SUB"},
    {OperationType::MULTI, "MULTI"},
    {OperationType::DIV, "DIV"},
    {OperationType::LT, "LT"},
    {OperationType::BT, "BT"},
    {OperationType::EQUAL, "EQUAL"},
    {OperationType::NONEQUAL, "NONEQUAL"},
    {OperationType::JZ, "JZ"},
    {OperationType::JNZ, "JNZ"},
    {OperationType::JMP, "JMP"},
    {OperationType::HALT, "HALT"}
};

std::map<std::string, OperationType> operationNamesStr {
    {"FETCHNEW", OperationType::FETCHNEW},
    {"FETCH", OperationType::FETCH},
    {"UNFETCH", OperationType::UNFETCH},
    { "STORE",OperationType::STORE},
    { "PUSH",OperationType::PUSH},
    { "POP",OperationType::POP},
    { "ADD",OperationType::ADD},
    { "SUB",OperationType::SUB},
    { "MULTI",OperationType::MULTI},
    { "DIV",OperationType::DIV},
    {"LT",OperationType::LT },
    {"BT",OperationType::BT },
    { "EQUAL",OperationType::EQUAL},
    { "NONEQUAL",OperationType::NONEQUAL},
    { "JZ",OperationType::JZ},
    { "JNZ",OperationType::JNZ},
    { "JMP",OperationType::JMP},
    { "HALT",OperationType::HALT}
};

#endif