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
        std::cout << _value << " to [Int] converison not allowed.\n";
        exit(1);
    }
}

double Obj::toReal() {
    try {
        return std::stod(_value);
    }
    catch (std::exception& e) {
        std::cout << _value << " to [Real] converison not allowed.\n";
        exit(1);
    }
}

bool Obj::toBool() {
    if (_value != "") return true;
    return false;
}

VarType Obj::type() {
    return VarType::OBJ;
}

std::string Obj::toStore() {
    return vartypeNames[type()] + " " + _value;
}
