using namespace std;

#include "iostream"
#include "../Compiler/CompilerCommands.cpp"
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

            if (op == FETCH) {
                if (vars.find(arg) == vars.end()) {
                    cout << "Variable {" << char(arg) << "} not exists!\n";
                    exit(1);
                }
                stack.push(vars[arg]);
                pc += 2;
            }
            if (op == STORE) {
                vars[arg] = stack.top();
                stack.pop();
                pc += 2;
            }
            if (op == PUSH) {
                stack.push(arg);
                pc += 2;
            }
            if (op == POP) {
                pc += 1;
            }
            if (op == ADD) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                stack.push(first + second);
                pc += 1;
            }
            if (op == SUB) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                stack.push(first - second);
                pc += 1;
            }
            if (op == MULTI) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                stack.push(first * second);
                pc += 1;
            }
            if (op == DIV) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                stack.push(first / second);
                pc += 1;
            }
            if (op == LT) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                if (first < second) {
                    stack.push(1);
                } else {
                    stack.push(0);
                }
                pc += 1;
            }
            if (op == BT) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                if (first > second) {
                    stack.push(1);
                } else {
                    stack.push(0);
                }
                pc += 1;
            }
            if (op == EQUAL) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                if (first == second) {
                    stack.push(1);
                } else {
                    stack.push(0);
                }
                pc += 1;
            }
            if (op == NONEQUAL) {
                int second = stack.top(); stack.pop();
                int first = stack.top(); stack.pop();
                if (first != second) {
                    stack.push(1);
                } else {
                    stack.push(0);
                }
                pc += 1;
            }
            if (op == JZ) {
                if (stack.top() == 0) {
                    pc = arg;
                } else {
                    pc += 2;
                }
                break;
            }
            if (op == JNZ) {
                if (stack.top() == 1) {
                    pc = arg;
                } else {
                    pc += 2;
                }
                break;
            }
            if (op == JMP) {
                pc = arg;
            }
            if (op == HALT) break;
        }
        cout << "Execution finished. Vars:\n";
        for (const auto & [key, value] : vars) {
            cout << char(key) << " = " << value << "\n";
        }
    };
};