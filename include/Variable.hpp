#pragma once

#ifndef _VARIABLE

#define _VARIABLE

#include <string>
#include <map>

enum class VarType {
    OBJ,

    INT,
    REAL,

    STRING,
    CHAR,

    BOOL
};

class Var {
public:
    std::string name;
    VarType type;
    int address;
    std::string value;
};

extern std::map<std::string, VarType> vartypeNamesStr;

extern std::map<VarType, std::string> vartypeNames;

std::string init_value(std::string type_str);

#endif