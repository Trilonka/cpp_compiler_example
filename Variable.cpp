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
    string value;
};

std::map<std::string, VarType> vartypeNamesStr {
    {"OBJ", VarType::OBJ},
    {"INT", VarType::INT},
    {"STRING", VarType::STRING},
    {"BOOL", VarType::BOOL},
    {"CHAR", VarType::CHAR},
    {"REAL", VarType::REAL}
};

std::map<VarType, std::string> vartypeNames {
    {VarType::OBJ, "OBJ"},
    {VarType::INT, "INT"},
    {VarType::STRING, "STRING"},
    {VarType::BOOL, "BOOL"},
    {VarType::CHAR, "CHAR"},
    {VarType::REAL, "REAL"}
};

string init_value(string type_str) {
    VarType type = vartypeNamesStr[type_str];

    switch (type) {
        case VarType::OBJ: {
            return "";
        }
        case VarType::INT: {
            return "0";
        }
        case VarType::STRING: {
            return "";
        }
        case VarType::BOOL: {
            return "true";
        }
        case VarType::CHAR: {
            return "";
        }
        case VarType::REAL: {
            return "0.0";
        }
    }
};

#endif