#include "type/Bool.hpp"

Bool::Bool(std::string _value) : Obj(_value) {}

Bool::Bool(bool _value) : Obj(std::to_string(_value)) {}

std::string Bool::toStr() {
    return _value;
}

int Bool::toInt() {
    if (_value != "") return 1;
    return 0;
}

double Bool::toReal() {
    if (_value != "") return 1.0;
    return 0.0;
}

bool Bool::toBool() {
    if (_value != "" && _value != "0" && _value != "0.0" && _value != "false") return true;
    return false;
}

VarType Bool::type() {
    return VarType::BOOL;
}