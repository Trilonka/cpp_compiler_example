#ifndef _COMPILER

#define _COMPILER

using namespace std;

#include <vector>
#include <string>
#include <stack>
#include "enums/CompilerCommands.cpp"
#include "Parser.cpp"
#include <iostream>
#include "Node.cpp"
#include "enums/NodeTypes.cpp"

class Compiler {
    
public:

    vector<int> program;
    int programCounter = 0;

    void gen(int command) {
        program.push_back(command);
        programCounter++;
    }

    vector<int> compile(Node node) {
        if (node.kind == NodeType::VAR) {
            gen(int(OperationType::FETCH));
            gen(char(node.value.at(0))); // TODO:
        }
        else if (node.kind == NodeType::INT) {
            gen(int(OperationType::PUSH));
            gen(stoi(node.value)); // TODO:
        }
        else if (node.kind == NodeType::PLUS) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::ADD));
        }
        else if (node.kind == NodeType::MINUS) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::SUB));
        }
        else if (node.kind == NodeType::MULTI) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::MULTI));
        }
        else if (node.kind == NodeType::DIV) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::DIV));
        }
        else if (node.kind == NodeType::LT) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::LT));
        }
        else if (node.kind == NodeType::BT) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::BT));
        }
        else if (node.kind == NodeType::EQUAL) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::EQUAL));
        }
        else if (node.kind == NodeType::UNEQUAL) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::NONEQUAL));
        }
        else if (node.kind == NodeType::SET) {
            compile(node.operators[1]);
            gen(int(OperationType::STORE));
            gen(char(node.operators[0].value.at(0))); // TODO: 
        }
        else if (node.kind == NodeType::IF) {
            compile(node.operators[0]);
            gen(int(OperationType::JZ));
            int addr = programCounter;
            gen(0);
            compile(node.operators[1]);
            program[addr] = programCounter;
        }
        else if (node.kind == NodeType::IFELSE) {
            compile(node.operators[0]);
            gen(int(OperationType::JZ)); int addr1 = programCounter; gen(0);
            compile(node.operators[1]);
            gen(int(OperationType::JMP)); int addr2 = programCounter; gen(0);
            program[addr1] = programCounter;
            compile(node.operators[2]);
            program[addr2] = programCounter;
        }
        else if (node.kind == NodeType::WHILE) {
            int addr1 = programCounter;
            compile(node.operators[0]);
            gen(int(OperationType::JZ)); int addr2 = programCounter; gen(0);
            compile(node.operators[1]);
            gen(int(OperationType::JMP)); gen(addr1);
            program[addr2] = programCounter;
        }
        else if (node.kind == NodeType::DOWHILE) {
            int addr = programCounter;
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(int(OperationType::JNZ));
            gen(addr);
        }
        else if (node.kind == NodeType::THEN) {
            compile(node.operators[0]);
        }
        else if (node.kind == NodeType::EXPR) {
            compile(node.operators[0]);
        }
        else if (node.kind == NodeType::PROG) {
            int i = 0;
            while (i < node.operators.size()) {
                compile(node.operators[i++]);
            }
            gen(int(OperationType::HALT));
        }
        return program;
    }
};

#endif