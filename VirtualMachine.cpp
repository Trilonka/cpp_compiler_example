using namespace std;

#include "iostream"
#include "enums/CompilerCommands.cpp"
#include <vector>
#include <string>
#include <stack>
#include <map>

class VirtualMachine {
public:

    void run(vector<int> program) {

        map<int, int> vars;
        stack<int> stack;
        int pc = 0;
        
        while (true) {

            int op = program[pc];
            int arg;

            if (pc < program.size()-1) {
                arg = program[pc+1];
            }

            if (op == int(OperationType::FETCH)) {
                if (vars.find(arg) == vars.end()) {
                    cout << "Variable {" << char(arg) << "} not exists!\n";
                    exit(1);
                }
                stack.push(vars[arg]);
                pc += 2;
            }
            if (op == int(OperationType::STORE)) {
                vars[arg] = stack.top();
                stack.pop();
                pc += 2;
            }
            if (op == int(OperationType::PUSH)) {
                stack.push(arg);
                pc += 2;
            }
            if (op == int(OperationType::POP)) {
                pc += 1;
            }
            if (op == int(OperationType::ADD)) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                stack.push(first + second);
                pc += 1;
            }
            if (op == int(OperationType::SUB)) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                stack.push(first - second);
                pc += 1;
            }
            if (op == int(OperationType::MULTI)) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                stack.push(first * second);
                pc += 1;
            }
            if (op == int(OperationType::DIV)) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                stack.push(first / second);
                pc += 1;
            }
            if (op == int(OperationType::LT)) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                if (first < second) {
                    stack.push(1);
                } else {
                    stack.push(0);
                }
                pc += 1;
            }
            if (op == int(OperationType::BT)) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                if (first > second) {
                    stack.push(1);
                } else {
                    stack.push(0);
                }
                pc += 1;
            }
            if (op == int(OperationType::EQUAL)) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                if (first == second) {
                    stack.push(1);
                } else {
                    stack.push(0);
                }
                pc += 1;
            }
            if (op == int(OperationType::NONEQUAL)) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                if (first != second) {
                    stack.push(1);
                } else {
                    stack.push(0);
                }
                pc += 1;
            }
            if (op == int(OperationType::JZ)) {
                if (stack.top() == 0) {
                    pc = arg;
                } else {
                    pc += 2;
                }
                break;
            }
            if (op == int(OperationType::JNZ)) {
                if (stack.top() == 1) {
                    pc = arg;
                } else {
                    pc += 2;
                }
                break;
            }
            if (op == int(OperationType::JMP)) {
                pc = arg;
            }
            if (op == int(OperationType::HALT)) break;
        }
        cout << "Execution finished. Vars:\n";
        for (const auto & [key, value] : vars) {
            cout << char(key) << " = " << value << "\n";
        }
    };
};