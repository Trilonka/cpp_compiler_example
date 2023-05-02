
using namespace std;

#include "iostream"
#include "enums/CompilerCommands.cpp"
#include <vector>
//#include <string>
#include <stack>
//#include <map>
#include "Variable.cpp"
#include "Calculations.cpp"
#include "types/Obj.cpp"

class VirtualMachine {
private:
public:

    map<string, string> vars;
    stack<string> stack;

    void run(vector<string> program) {

        cout << "VM started\n";
        int pc = 0;
        
        while (true) {

            OperationType op = operationNamesStr[program[pc]];
            string arg;

            if (pc < program.size()-1) {
                arg = program[pc+1];
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
                    if (stack.top().substr(0, stack.top().find(" ")) != vars[program[pc+2]].substr(0, vars[program[pc+2]].find(" "))) {
                        cout << "Wrong typesss!\n";
                        exit(1);
                    }
                    vars[program[pc+2]] = stack.top();
                } else if (arg == "FETCHNEW") {
                    if (stack.top().substr(0, stack.top().find(" ")) != program[pc+2].substr(0, program[pc+2].find(" "))) {
                        cout << "Wrong types!\n";
                        exit(1);
                    }
                    vars[program[pc+2].substr(program[pc+2].find(" ")+1)] = stack.top();
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
                string second = stack.top(); stack.pop();
                string first = stack.top(); stack.pop();
                stack.push(sum(first, second)->toStore()); // TODO?
                pc += 1;
            }
            if (op == OperationType::SUB) {
                string second = stack.top(); stack.pop();
                string first = stack.top(); stack.pop();
                stack.push(sub(first, second)->toStore()); // TODO?
                pc += 1;
            }
            if (op == OperationType::MULTI) {
                string second = stack.top(); stack.pop();
                string first = stack.top(); stack.pop();
                stack.push(mul(first, second)->toStore()); // TODO?
                pc += 1;
            }
            if (op == OperationType::DIV) {
                string second = stack.top(); stack.pop();
                string first = stack.top(); stack.pop();
                stack.push(div(first, second)->toStore()); // DIV?
                pc += 1;
            }
            if (op == OperationType::LT) {
                string second = stack.top(); stack.pop();
                string first = stack.top(); stack.pop();
                if (first < second) { // TODO
                    stack.push("true");
                } else {
                    stack.push("false");
                }
                pc += 1;
            }
            if (op == OperationType::BT) {
                string second = stack.top(); stack.pop();
                string first = stack.top(); stack.pop();
                if (first > second) { // TODO
                    stack.push("true");
                } else {
                    stack.push("false");
                }
                pc += 1;
            }
            if (op == OperationType::EQUAL) {
                string second = stack.top(); stack.pop();
                string first = stack.top(); stack.pop();
                if (first == second) {
                    stack.push("true");
                } else {
                    stack.push("false");
                }
                pc += 1;
            }
            if (op == OperationType::NONEQUAL) {
                string second = stack.top(); stack.pop();
                string first = stack.top(); stack.pop();
                if (first != second) {
                    stack.push("true");
                } else {
                    stack.push("false");
                }
                pc += 1;
            }
            if (op == OperationType::JZ) {
                if (stack.top() == "false") {
                    pc = stoi(arg);
                } else {
                    pc += 2;
                }
            }
            if (op == OperationType::JNZ) {
                if (stack.top() == "true") {
                    pc = stoi(arg);
                } else {
                    pc += 2;
                }
            }
            if (op == OperationType::JMP) {
                pc = stoi(arg);
            }
            if (op == OperationType::HALT) break;
        }
        cout << "Execution finished. Vars:\n";

        map<string, string>::iterator it;
        for (it = vars.begin(); it != vars.end(); it++)
        {
            std::cout << it->first    // string (key)
                    << " : "
                    << it->second   // string's value 
                    << std::endl;
        }
    };

    void fetch_new(string &arg) {
        string type = arg.substr(0, arg.find(" "));
        string name = arg.substr(arg.find(" ")+1);
        string value = type + " " + init_value(type);
        stack.push(value);
        vars[name] = value;
    }
};