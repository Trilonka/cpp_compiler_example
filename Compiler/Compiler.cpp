using namespace std;

#include <vector>
#include <string>
#include <stack>
#include "../Parser/Parser.cpp"
#include "CompilerCommands.cpp"

class Compiler {
    
public:

    vector<int> program;
    int programCounter = 0;

    void gen(int command) {
        program.push_back(command);
        programCounter++;
    }

    vector<int> compile(node node) {
        if (node.kind == Parser::IntVAR) {
            gen(FETCH);
            gen(node.value);
        }
        else if (node.kind == Parser::CONST) {
            gen(PUSH);
            gen(node.value);
        }
        else if (node.kind == Parser::ADD) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(ADD);
        }
        else if (node.kind == Parser::SUB) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(SUB);
        }
        else if (node.kind == Parser::MULTI) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(MULTI);
        }
        else if (node.kind == Parser::DIV) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(DIV);
        }
        else if (node.kind == Parser::LT) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(LT);
        }
        else if (node.kind == Parser::BT) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(BT);
        }
        else if (node.kind == Parser::EQUAL) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(EQUAL);
        }
        else if (node.kind == Parser::UnEQUAL) {
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(NONEQUAL);
        }
        else if (node.kind == Parser::SET) {
            compile(node.operators[1]);
            gen(STORE);
            gen(node.operators[0].value);
        }
        else if (node.kind == Parser::IF) {
            compile(node.operators[0]);
            gen(JZ);
            int addr = programCounter;
            gen(0);
            compile(node.operators[1]);
            program[addr] = programCounter;
        }
        else if (node.kind == Parser::IfELSE) {
            compile(node.operators[0]);
            gen(JZ); int addr1 = programCounter; gen(0);
            compile(node.operators[1]);
            gen(JMP); int addr2 = programCounter; gen(0);
            program[addr1] = programCounter;
            compile(node.operators[2]);
            program[addr2] = programCounter;
        }
        else if (node.kind == Parser::WHILE) {
            int addr1 = programCounter;
            compile(node.operators[0]);
            gen(JZ); int addr2 = programCounter; gen(0);
            compile(node.operators[1]);
            gen(JMP); gen(addr1);
            program[addr2] = programCounter;
        }
        else if (node.kind == Parser::DoWHILE) {
            int addr = programCounter;
            compile(node.operators[0]);
            compile(node.operators[1]);
            gen(JNZ);
            gen(addr);
        }
        else if (node.kind == Parser::THEN) {
            compile(node.operators[0]);
        }
        else if (node.kind == Parser::EXPR) {
            compile(node.operators[0]);
        }
        else if (node.kind == Parser::PROG) {
            int i = 0;
            while (i < node.operators.size()) {
                compile(node.operators[i++]);
            }
            gen(HALT);
        }
        return program;
    }
};