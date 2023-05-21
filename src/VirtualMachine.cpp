#include "VirtualMachine.hpp"

void VirtualMachine::run(std::vector<std::string> program) {

    std::cout << "VM started\n";
    int pc = 0;

    while (true) {

        OperationType op = operationNamesStr[program[pc]];
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
        if (op == OperationType::UNFETCH) {
            vars.erase(arg);
            pc += 2;
        }
        if (op == OperationType::STORE) {
            if (arg == "FETCH") {
                if (stack.top().substr(0, stack.top().find(" ")) != vars[program[pc + 2]].substr(0, vars[program[pc + 2]].find(" "))) {
                    std::cout << "Wrong typesss!\n";
                    exit(1);
                }
                vars[program[pc + 2]] = stack.top();
            }
            else if (arg == "FETCHNEW") {
                if (stack.top().substr(0, stack.top().find(" ")) != program[pc + 2].substr(0, program[pc + 2].find(" "))) {
                    std::cout << "Wrong types!\n";
                    exit(1);
                }
                vars[program[pc + 2].substr(program[pc + 2].find(" ") + 1)] = stack.top();
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
        if (op == OperationType::JMP) {
            pc = stoi(arg);
        }
        if (op == OperationType::HALT) break;
    }
    std::cout << "Execution finished. Vars:\n";

    std::map<std::string, std::string>::iterator it;
    for (it = vars.begin(); it != vars.end(); it++)
    {
        std::cout << it->first    // string (key)
            << " : "
            << it->second   // string's value 
            << std::endl;
    }
}

void VirtualMachine::fetch_new(std::string& arg) {
    std::string type = arg.substr(0, arg.find(" "));
    std::string name = arg.substr(arg.find(" ") + 1);
    std::string value = type + " " + init_value(type);
    stack.push(value);
    vars[name] = value;
}
