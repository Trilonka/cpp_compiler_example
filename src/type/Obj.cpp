#include "type/Obj.hpp"

Obj::Obj(std::string __value) {
    _value = __value;
}

std::string Obj::toStr() {
    return _value;
}

int Obj::toInt() {
    try {
        return std::stoi(_value);
    }
    catch (std::exception& e) {
        std::cout << _value << " to [Int] converison is not allowed.\n";
        exit(1);
    }
}

double Obj::toReal() {
    try {
        return std::stod(_value);
    }
    catch (std::exception& e) {
        std::cout << _value << " to [Real] converison is not allowed.\n";
        exit(1);
    }
}

bool Obj::toBool() {
    if (_value != "") return true;
    return false;
}

char Obj::toChar() {
    if (_value.size() == 1) return _value[0];
    std::cout << _value << " to [Char] converison is not allowed.\n";
}

VarType Obj::type() {
    return VarType::OBJ;
}

std::string Obj::toStore() {
    return vartype_to_string[type()] + " " + _value;
}
