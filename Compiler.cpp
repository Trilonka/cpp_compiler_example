

#ifndef _COMPILER

#define _COMPILER

using namespace std;

#include <vector>
//#include <string>
#include <stack>
#include "enums/CompilerCommands.cpp"
#include "Parser.cpp"
#include <iostream>
#include "Node.cpp"
#include "enums/NodeTypes.cpp"
#include "Variable.cpp"
//#include <map>
#include <set>
#include "exception/CompilerExceptions.cpp"

class Compiler {
    
public:

    vector<string> program;
    int programCounter = 0;
    
    set<string> vars;

    void gen(int command) {
        program.push_back(to_string(command));
        programCounter++;
    }

    void gen(string operand) {
        program.push_back(operand);
        programCounter++;
    }

    void gen(OperationType operation) {
        program.push_back(operationNames[operation]);
        programCounter++;
    }

    void compile(Node node) {
        if (processVariables(node)) {
            return;
        }
        if (processConstants(node)) {
            return;
        }
        else if (node.kind == NodeType::PLUS) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::ADD);
        }
        else if (node.kind == NodeType::MINUS) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::SUB);
        }
        else if (node.kind == NodeType::MULTI) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::MULTI);
        }
        else if (node.kind == NodeType::DIV) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::DIV);
        }
        else if (node.kind == NodeType::LT) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::LT);
        }
        else if (node.kind == NodeType::BT) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::BT);
        }
        else if (node.kind == NodeType::EQUAL) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::EQUAL);
        }
        else if (node.kind == NodeType::UNEQUAL) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::NONEQUAL);
        }
        else if (node.kind == NodeType::SET) {
            compile(node.operators[1]);
            gen(OperationType::STORE);
            compile(node.operators[0]);
        }
        else if (node.kind == NodeType::IF) {
            compile(node.operators[0]);
            gen(OperationType::JZ);
            int addr = programCounter;
            gen(0);
            compile(node.operators[1]);
            program[addr] = to_string(programCounter);
        }
        else if (node.kind == NodeType::IFELSE) {
            compile(node.operators[0]);
            gen(OperationType::JZ); int addr1 = programCounter; gen(0);
            compile(node.operators[1]);
            gen(OperationType::JMP); int addr2 = programCounter; gen(0);
            program[addr1] = to_string(programCounter);
            compile(node.operators[2]);
            program[addr2] = to_string(programCounter);
        }
        else if (node.kind == NodeType::WHILE) {
            int addr1 = programCounter;
            compile(node.operators[0]);
            gen(OperationType::JZ); int addr2 = programCounter; gen(0);
            compile(node.operators[1]);
            gen(OperationType::JMP); gen(addr1);
            program[addr2] = to_string(programCounter);
        }
        else if (node.kind == NodeType::DOWHILE) {
            int addr = programCounter;
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(OperationType::JNZ);
            gen(addr);
        }
        else if (node.kind == NodeType::THEN) {
            int i = 0;
            set<string> oldVars = vars;
            while (i < node.operators.size()) {
                compile(node.operators[i++]);
            }
            // ставим метку - удаляем локальные переменные
            set<string>::iterator it = oldVars.begin();
            while (it != oldVars.end()) {
                vars.erase(*it);
                it++;
            }
            it = vars.begin();
            while (it != vars.end()) {
                gen(OperationType::UNFETCH);
                gen(*it);
                it++;
            };
            vars = oldVars;
        }
        else if (node.kind == NodeType::EXPR) {
            int i = 0;
            while (i < node.operators.size()) {
                compile(node.operators[i++]);
            }
        }
        else if (node.kind == NodeType::PROG) {
            int i = 0;
            while (i < node.operators.size()) {
                compile(node.operators[i++]);
            }
            gen(OperationType::HALT);
        }
    }

    bool processVariables(Node &node) {
        if (node.kind == NodeType::VAR) {
            gen(OperationType::FETCH);
            checkNotExistsVariable(node.value);
            gen(node.value);
            return true;
        }
        else if (node.kind == NodeType::INT) {
            saveVariable(node.value, VarType::INT);
            return true;
        }
        else if (node.kind == NodeType::BOOL) {
            saveVariable(node.value, VarType::BOOL);
            return true;
        }
        else if (node.kind == NodeType::STRING) {
            saveVariable(node.value, VarType::STRING);
            return true;
        }
        else if (node.kind == NodeType::CHAR) {
            saveVariable(node.value, VarType::CHAR);
            return true;
        }
        else if (node.kind == NodeType::REAL) {
            saveVariable(node.value, VarType::REAL);
            return true;
        }
        return false;
    }

    bool processConstants(Node &node) {
        if (node.kind == NodeType::CONSTINT) {
            gen(OperationType::PUSH);
            gen("INT " + node.value);
            return true;
        }
        if (node.kind == NodeType::CONSTCHAR) {
            gen(OperationType::PUSH);
            gen("CHAR " + node.value);
            return true;
        }
        if (node.kind == NodeType::CONSTREAL) {
            gen(OperationType::PUSH);
            gen("REAL " + node.value);
            return true;
        }
        if (node.kind == NodeType::CONSTSTRING) {
            gen(OperationType::PUSH);
            gen("STRING " + node.value);
            return true;
        }
        return false;
    }

    void saveVariable(string varName, VarType varType) {
        gen(OperationType::FETCHNEW);
        checkExistsVariable(varName);
        vars.insert(varName);
        // vars[varName] = {varName, varType, programCounter, ""};
        gen(vartypeNames[varType] + " " + varName);
    }

    void saveConst(string value) {
        gen(OperationType::PUSH);
        gen(value);
    }

    void checkExistsVariable(string &varName) {
        if (vars.find(varName) != vars.end()) {
            string message = "Variable {" + varName + "} already exists!\n";
            cout << message;
            throw VariableNotExistsException(message.c_str());
        }
    }

    void checkNotExistsVariable(string &varName) {
        if (vars.find(varName) == vars.end()) {
            string message = "Variable {" + varName + "} not exists!\n";
            cout << message;
            throw VariableNotExistsException(message.c_str());
        }
    }
};

#endif