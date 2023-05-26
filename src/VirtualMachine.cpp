#include "VirtualMachine.hpp"

void VirtualMachine::run(std::vector<std::string> program) {

    int pc = 0;

    while (true) {

        OperationType op = string_to_operation[program[pc]];
        std::string arg;

        if (pc < program.size() - 1) {
            arg = program[pc + 1];
        }
        if (op == OperationType::FETCHNEW) {
            fetch_new(arg);
            pc += 2;
        }
        if (op == OperationType::FETCH) {
            stack.push(vars[arg]);
            pc += 2;
        }
        if (op == OperationType::FETCHELEMENT) {
            compute_on_element(arg, wrap(stack.top())->toInt(),[this](Obj* obj) {
                stack.push(obj->toStore());
            });
            pc += 2;
        }
        if (op == OperationType::FETCHARR) {
            int size = std::stoi(arg.substr(0, arg.find(' ')));
            fetch_arr(arg.substr(arg.find(' ')+1), size);
            pc += 2;
        }
        if (op == OperationType::UNFETCH) {
            vars.erase(arg);
            arrays.erase(arg);
            pc += 2;
        }
        if (op == OperationType::STORE) {
            if (string_to_operation[arg] == OperationType::FETCH) {
                vars[program[pc + 2]] =
                        set(vars[program[pc+2]], stack.top().substr(stack.top().find(' ')+1))
                        ->toStore();
            }
            if (string_to_operation[arg] == OperationType::FETCHNEW) {
                vars[program[pc + 2].substr(program[pc + 2].find(' ') + 1)] =
                        set(program[pc + 2], stack.top().substr(stack.top().find(' ')+1))
                        ->toStore();
            }
            if (string_to_operation[arg] == OperationType::FETCHELEMENT) {
                int index = wrap(stack.top())->toInt(); stack.pop();
                store_array_element(program[pc+2], index, wrap(stack.top())->toStr());
            }
            stack.pop();
            pc += 3;
        }
        if (op == OperationType::PUSH) {
            stack.push(arg);
            pc += 2;
        }
        if (op == OperationType::POP) {
            pc += 1;
        }
        if (op == OperationType::ADD) {
            std::string second = stack.top(); stack.pop();
            std::string first = stack.top(); stack.pop();
            stack.push(sum(first, second)->toStore());
            pc += 1;
        }
        if (op == OperationType::SUB) {
            std::string second = stack.top(); stack.pop();
            std::string first = stack.top(); stack.pop();
            stack.push(sub(first, second)->toStore());
            pc += 1;
        }
        if (op == OperationType::MULTI) {
            std::string second = stack.top(); stack.pop();
            std::string first = stack.top(); stack.pop();
            stack.push(mul(first, second)->toStore());
            pc += 1;
        }
        if (op == OperationType::DIV) {
            std::string second = stack.top(); stack.pop();
            std::string first = stack.top(); stack.pop();
            stack.push(div(first, second)->toStore());
            pc += 1;
        }
        if (op == OperationType::LT) {
            std::string second = stack.top(); stack.pop();
            std::string first = stack.top(); stack.pop();
            stack.push(lessThen(first, second)->toStore());
            pc += 1;
        }
        if (op == OperationType::BT) {
            std::string second = stack.top(); stack.pop();
            std::string first = stack.top(); stack.pop();
            stack.push(biggerThen(first, second)->toStore());
            pc += 1;
        }
        if (op == OperationType::EQUAL) {
            std::string second = stack.top(); stack.pop();
            std::string first = stack.top(); stack.pop();
            stack.push(equal(first, second)->toStore());
            pc += 1;
        }
        if (op == OperationType::NONEQUAL) {
            std::string second = stack.top(); stack.pop();
            std::string first = stack.top(); stack.pop();
            stack.push(notEqual(first, second)->toStore());
            pc += 1;
        }
        if (op == OperationType::PRINT) {
            std::string valueToPrinted = stack.top(); stack.pop();
            std::cout << wrap(valueToPrinted)->toStr() << std::endl;
            pc += 1;
        }
        if (op == OperationType::READ) {
            if (arrays.find(arg) == arrays.end()) {
                std::string newValue; std::cin >> newValue;
                vars[arg] = set(vars[arg], newValue)->toStore();
                pc += 2;
            }
            else {
                int index = wrap(stack.top())->toInt(); stack.pop();
                std::string newValue; std::cin >> newValue;
                store_array_element(arg, index, newValue);
                pc += 2;
            }
        }
        if (op == OperationType::JZ) {
            if (isTrue(stack.top())) {
                pc += 2;
            }
            else {
                pc = stoi(arg);
            }
        }
        if (op == OperationType::JNZ) {
            if (isTrue(stack.top())) {
                pc = stoi(arg);
            }
            else {
                pc += 2;
            }
        }
        if (op == OperationType::GOTO) {
            pc = stoi(arg);
        }
        if (op == OperationType::HALT) break;
    }
}

void VirtualMachine::fetch_new(std::string& arg) {
    std::string type = arg.substr(0, arg.find(' '));
    std::string name = arg.substr(arg.find(' ') + 1);
    std::string value = type + " " + init_value(type);
    stack.push(value);
    vars[name] = value;
}

void VirtualMachine::fetch_arr(std::string arg, int size) {
    VarType type = string_to_vartype[arg.substr(0, arg.find(' '))];
    std::string name = arg.substr(arg.find(' ') + 1);
    array_type[name] = type;
    if (type == VarType::INT) {
        ArrayContainer<Int*>* container = new ArrayContainer<Int*>(size);
        int i = 0;
        while (i < size) {
            container->operator[](i++) = new Int(init_value(type));
        }
        arrays[name] = container;
    }
    if (type == VarType::STRING) {
        ArrayContainer<Str*>* container = new ArrayContainer<Str*>(size);
        int i = 0;
        while (i < size) {
            container->operator[](i++) = new Str(init_value(type));
        }
        arrays[name] = container;
    }
    if (type == VarType::BOOL) {
        ArrayContainer<Bool*>* container = new ArrayContainer<Bool*>(size);
        int i = 0;
        while (i < size) {
            container->operator[](i++) = new Bool(init_value(type));
        }
        arrays[name] = container;
    }
    if (type == VarType::REAL) {
        ArrayContainer<Real*>* container = new ArrayContainer<Real*>(size);
        int i = 0;
        while (i < size) {
            container->operator[](i++) = new Real(init_value(type));
        }
        arrays[name] = container;
    }
    if (type == VarType::CHAR) {
        ArrayContainer<Char*>* container = new ArrayContainer<Char*>(size);
        int i = 0;
        while (i < size) {
            container->operator[](i++) = new Char(init_value(type));
        }
        arrays[name] = container;
    }
}

void VirtualMachine::store_array_element(std::string name, int index, std::string value) {
    VarType type = array_type[name];
    switch (type) {
        case (VarType::INT): {
            ArrayContainer<Int*>* arr = (std::any_cast<ArrayContainer<Int*>*>(arrays[name]));
            arr->operator[](index) =
                    dynamic_cast<Int*>(set(arr->operator[](index)->toStore(), value));
            break;
        }
        case (VarType::STRING): {
            ArrayContainer<Str*>* arr = (std::any_cast<ArrayContainer<Str*>*>(arrays[name]));
            arr->operator[](index) =
                    dynamic_cast<Str*>(set(arr->operator[](index)->toStore(), value));
            break;
        }
        case (VarType::BOOL): {
            ArrayContainer<Bool*>* arr = (std::any_cast<ArrayContainer<Bool*>*>(arrays[name]));
            arr->operator[](index) =
                    dynamic_cast<Bool*>(set(arr->operator[](index)->toStore(), value));
            break;
        }
        case (VarType::REAL): {
            ArrayContainer<Real*>* arr = (std::any_cast<ArrayContainer<Real*>*>(arrays[name]));
            arr->operator[](index) =
                    dynamic_cast<Real*>(set(arr->operator[](index)->toStore(), value));
            break;
        }
        case (VarType::CHAR): {
            ArrayContainer<Char*>* arr = (std::any_cast<ArrayContainer<Char*>*>(arrays[name]));
            arr->operator[](index) =
                    dynamic_cast<Char*>(set(arr->operator[](index)->toStore(), value));
            break;
        }
    }
}

void VirtualMachine::compute_on_element(std::string name, int index, const std::function<void(Obj*)>& compute) {
    VarType type = array_type[name];
    switch (type) {
        case (VarType::INT): {
            compute((*std::any_cast<ArrayContainer<Int*>*>(arrays[name]))[index]);
            break;
        }
        case (VarType::STRING): {
            compute((*std::any_cast<ArrayContainer<Str*>*>(arrays[name]))[index]);
            break;
        }
        case (VarType::BOOL): {
            compute((*std::any_cast<ArrayContainer<Bool*>*>(arrays[name]))[index]);
            break;
        }
        case (VarType::REAL): {
            compute((*std::any_cast<ArrayContainer<Real*>*>(arrays[name]))[index]);
            break;
        }
        case (VarType::CHAR): {
            compute((*std::any_cast<ArrayContainer<Char*>*>(arrays[name]))[index]);
            break;
        }
    }
}