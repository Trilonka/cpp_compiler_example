#include "Variable.hpp" 

std::map<std::string, VarType> string_to_vartype {
    {"OBJ", VarType::OBJ},
    {"INT", VarType::INT},
    {"STRING", VarType::STRING},
    {"BOOL", VarType::BOOL},
    {"CHAR", VarType::CHAR},
    {"REAL", VarType::REAL}
};

std::map<VarType, std::string> vartype_to_string {
    {VarType::OBJ, "OBJ"},
    {VarType::INT, "INT"},
    {VarType::STRING, "STRING"},
    {VarType::BOOL, "BOOL"},
    {VarType::CHAR, "CHAR"},
    {VarType::REAL, "REAL"}
};


std::string init_value(VarType& type) {
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
            return "0";
        }
        case VarType::CHAR: {
            return "";
        }
        case VarType::REAL: {
            return "0.0";
        }
    }
};

std::string init_value(std::string type_str) {
    VarType type = string_to_vartype[type_str];

    return init_value(type);
};