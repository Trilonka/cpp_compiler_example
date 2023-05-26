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

extern std::map<std::string, VarType> string_to_vartype;

extern std::map<VarType, std::string> vartype_to_string;

std::string init_value(VarType& type);

std::string init_value(std::string type_str);

#endif