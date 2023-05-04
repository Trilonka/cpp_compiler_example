#include "type/Str.hpp"

Str::Str(std::string _value) : Obj(_value) {}

VarType Str::type() {
    return VarType::STRING;
}