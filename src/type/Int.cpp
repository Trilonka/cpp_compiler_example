#include "type/Int.hpp"

Int::Int(std::string _value) : Obj(_value) {}

Int::Int(int _value) : Obj(std::to_string(_value)) {}

bool Int::toBool() {
    if (_value == "0") return false;
    return true;
}

VarType Int::type() {
    return VarType::INT;
}
