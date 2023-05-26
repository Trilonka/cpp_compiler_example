#include "type/Real.hpp"

Real::Real(std::string _value) : Obj(_value) {
    try {
        std::stod(_value);
    }
    catch (std::exception& e) {
        std::cout << "Not allowed to save (" << _value << ") as [Real].\n";
        exit(1);
    }
}

Real::Real(double _value) : Obj(std::to_string(_value)) {}

bool Real::toBool() {
    if (_value == "0.0") return false;
    return true;
}

VarType Real::type() {
    return VarType::REAL;
}