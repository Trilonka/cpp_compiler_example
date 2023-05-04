#include "Calculations.hpp"

Obj* wrap(std::string var) {
    VarType type = vartypeNamesStr[var.substr(0, var.find(" "))];
    std::string value = var.substr(var.find(" ") + 1);
    if (type == VarType::INT) {
        return new Int(value);
    }
}

std::string multi_str(std::string str, int count) {
    std::string res;
    for (int i = 0; i < count; ++i) {
        res += str;
    }
    return res;
}

Obj* sum(std::string left_operand, std::string right_operand) { // +
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING || right->type() == VarType::STRING) {
        return new Str(left->toStr() + right->toStr());
    }
    if (left->type() == VarType::REAL || right->type() == VarType::REAL) {
        return new Real(left->toReal() + right->toReal());
    }
    if (left->type() == VarType::BOOL && right->type() == VarType::BOOL) {
        std::cout << "Just boolean operation not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::INT || right->type() == VarType::INT) {
        return new Int(left->toInt() + right->toInt());
    }

    std::cout << "Type is not supported.\n";
    exit(1);
}

Obj* sub(std::string left_operand, std::string right_operand) { // -
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING || right->type() == VarType::STRING) {
        std::cout << "Operation (-) for [str] is not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::REAL || right->type() == VarType::REAL) {
        return new Real(left->toReal() - right->toReal());
    }
    if (left->type() == VarType::BOOL && right->type() == VarType::BOOL) {
        std::cout << "Just boolean operation not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::INT || right->type() == VarType::INT) {
        return new Int(left->toInt() - right->toInt());
    }

    std::cout << "Type not supported.\n";
    exit(1);
}

Obj* mul(std::string left_operand, std::string right_operand) { // *
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING && right->type() == VarType::INT) {
        return new Str(multi_str(left->toStr(), right->toInt()));
    }
    if (left->type() == VarType::INT && right->type() == VarType::STRING) {
        return new Str(multi_str(right->toStr(), left->toInt()));
    }
    if (left->type() == VarType::REAL || right->type() == VarType::REAL) {
        return new Real(left->toReal() * right->toReal());
    }
    if (left->type() == VarType::BOOL && right->type() == VarType::BOOL) {
        std::cout << "Just boolean operation not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::INT || right->type() == VarType::INT) {
        return new Int(left->toInt() * right->toInt());
    }

    std::cout << "Type not supported.\n";
    exit(1);
}

Obj* div(std::string left_operand, std::string right_operand) { // /
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING || right->type() == VarType::STRING) {
        std::cout << "Operation (/) for [str] is not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::REAL || right->type() == VarType::REAL) {
        return new Real(left->toReal() / right->toReal());
    }
    if (left->type() == VarType::BOOL && right->type() == VarType::BOOL) {
        std::cout << "Just boolean operation not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::INT || right->type() == VarType::INT) {
        return new Int(left->toInt() / right->toInt());
    }

    std::cout << "Type not supported.\n";
    exit(1);
}
