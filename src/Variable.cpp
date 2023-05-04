#include "Variable.hpp" 

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

std::string init_value(std::string type_str) {
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