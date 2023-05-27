#include "Calculations.hpp"

Obj* wrap(std::string var) {
    VarType type = string_to_vartype[var.substr(0, var.find(' '))];
    std::string value = var.substr(var.find(' ') + 1);
    if (type == VarType::INT) {
        return new Int(value);
    }
    if (type == VarType::BOOL) {
        return new Bool(value);
    }
    if (type == VarType::REAL) {
        return new Real(value);
    }
    if (type == VarType::STRING) {
        return new Str(value);
    }
    if (type == VarType::CHAR) {
        return new Char(value);
    }
}

Obj* set(std::string var, std::string value) {
    VarType type = string_to_vartype[var.substr(0, var.find(' '))];
    if (type == VarType::STRING) {
        return new Str(value);
    }
    if (type == VarType::INT) {
        return new Int(value);
    }
    if (type == VarType::BOOL) {

        return new Bool(value);
    }
    if (type == VarType::REAL) {
        return new Real(value);
    }
    if (type == VarType::CHAR) {
        return new Char(value);
    }
}

std::string multi_str(std::string str, int count) {
    std::string res;
    for (int i = 0; i < count; ++i) {
        res += str;
    }
    return res;
}

bool isTrue(std::string logical_operand) {
    Obj* logical = wrap(logical_operand);
    return logical->toBool();
}

Obj* sum(std::string left_operand, std::string right_operand) {
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
    if (left->type() == VarType::CHAR || right->type() == VarType::CHAR) {
        return new Char(left->toInt() + right->toInt());
    }

    std::cout << "Type is not supported.\n";
    exit(1);
}

Obj* sub(std::string left_operand, std::string right_operand) {
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING || right->type() == VarType::STRING) {
        std::cout << "Operation (-) for [Str] is not allowed.\n";
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
    if (left->type() == VarType::CHAR || right->type() == VarType::CHAR) {
        return new Char(left->toInt() - right->toInt());
    }

    std::cout << "Type not supported.\n";
    exit(1);
}

Obj* mul(std::string left_operand, std::string right_operand) {
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING && right->type() == VarType::INT) {
        return new Str(multi_str(left->toStr(), right->toInt()));
    }
    if (left->type() == VarType::INT && right->type() == VarType::STRING) {
        return new Str(multi_str(right->toStr(), left->toInt()));
    }
    if (left->type() == VarType::STRING && right->type() == VarType::STRING) {
        std::cout << "Operation (*) for [Str] is not allowed.\n";
        exit(1);
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
    if (left->type() == VarType::CHAR || right->type() == VarType::CHAR) {
        std::cout << "Operation (*) for [Char] is not allowed.\n";
        exit(1);
    }

    std::cout << "Type not supported.\n";
    exit(1);
}

Obj* div(std::string left_operand, std::string right_operand) {
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING || right->type() == VarType::STRING) {
        std::cout << "Operation (/) for [Str] is not allowed.\n";
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
    if (left->type() == VarType::CHAR || right->type() == VarType::CHAR) {
        std::cout << "Operation (/) for [Char] is not allowed.\n";
        exit(1);
    }

    std::cout << "Type not supported.\n";
    exit(1);
}

Obj* mod(std::string left_operand, std::string right_operand) {
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING || right->type() == VarType::STRING) {
        std::cout << "Operation (%) for [Str] is not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::REAL || right->type() == VarType::REAL) {
        std::cout << "Operation (%) for [Real] is not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::BOOL && right->type() == VarType::BOOL) {
        std::cout << "Just boolean operation not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::INT || right->type() == VarType::INT) {
        return new Int(left->toInt() % right->toInt());
    }
    if (left->type() == VarType::CHAR || right->type() == VarType::CHAR) {
        std::cout << "Operation (%) for [Char] is not allowed.\n";
        exit(1);
    }

    std::cout << "Type not supported.\n";
    exit(1);
}

Obj* lessThen(std::string left_operand, std::string right_operand) {
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING || right->type() == VarType::STRING) {
        return new Bool(left->toStr() < right->toStr());
    }
    if (left->type() == VarType::REAL || right->type() == VarType::REAL) {
        return new Bool(left->toReal() < right->toReal());
    }
    if (left->type() == VarType::BOOL && right->type() == VarType::BOOL) {
        std::cout << "Just boolean operation not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::INT || right->type() == VarType::INT) {
        return new Bool(left->toInt() < right->toInt());
    }
    if (left->type() == VarType::CHAR || right->type() == VarType::CHAR) {
        return new Bool(left->toInt() < right->toInt());
    }

    std::cout << "Type not supported.\n";
    exit(1);
}

Obj* biggerThen(std::string left_operand, std::string right_operand) {
    Obj* left = wrap(left_operand);
    Obj* right = wrap(right_operand);

    if (left->type() == VarType::STRING || right->type() == VarType::STRING) {
        return new Bool(left->toStr() > right->toStr());
    }
    if (left->type() == VarType::REAL || right->type() == VarType::REAL) {
        return new Bool(left->toReal() > right->toReal());
    }
    if (left->type() == VarType::BOOL && right->type() == VarType::BOOL) {
        std::cout << "Just boolean operation not allowed.\n";
        exit(1);
    }
    if (left->type() == VarType::INT || right->type() == VarType::INT) {
        return new Bool(left->toInt() > right->toInt());
    }
    if (left->type() == VarType::CHAR || right->type() == VarType::CHAR) {
        return new Bool(left->toInt() > right->toInt());
    }

    std::cout << "Type not supported.\n";
    exit(1);
}

Obj* equal(std::string left_operand, std::string right_operand) {
    return new Bool(left_operand == right_operand);
}

Obj* notEqual(std::string left_operand, std::string right_operand) {
    return new Bool(left_operand != right_operand);
}
