#include "type/Char.hpp"

Char::Char(std::string _value) : Obj(_value) {}

Char::Char(int _value) : Obj(std::to_string(_value)) {
    if (_value < 0) {
        std::cout << "Not allowed to save (" << _value << ") as [Char].\n";
        exit(1);
    }
}

Char::Char(char _value) : Obj(std::to_string(_value)) {}

int Char::toInt() {
    return _value[0];
}

double Char::toReal() {
    return _value[0];
}

bool Char::toBool() {
    if (!_value.empty()) return true;
    return false;
}

VarType Char::type() {
    return VarType::CHAR;
}
