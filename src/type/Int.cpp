#include "type/Int.hpp"

Int::Int(std::string _value) : Obj(_value) {
    try {
        std::stoi(_value);
    }
    catch (std::exception& e) {
        std::cout << "Not allowed to save (" << _value << ") as [Int].\n";
        exit(1);
    }
}

Int::Int(int _value) : Obj(std::to_string(_value)) {}

bool Int::toBool() {
    if (_value == "0") return false;
    return true;
}

char Int::toChar() {
    try {
        return static_cast<char>(std::stoi(_value));
    }
    catch (std::exception& e) {
        std::cout << "Not allowed to save (" << _value << ") as [Char].\n";
        exit(1);
    }
}

VarType Int::type() {
    return VarType::INT;
}
