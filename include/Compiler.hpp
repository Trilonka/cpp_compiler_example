#pragma once

#ifndef _COMPILER

#define _COMPILER

using namespace std;

#include <vector>
#include <stack>
#include "enum/VMCommands.hpp"
#include "Parser.hpp"
#include <iostream>
#include "Node.hpp"
#include "enum/NodeTypes.hpp"
#include "Variable.hpp"
#include <map>
#include <set>
#include "exception/CompilerExceptions.hpp"

class Compiler {

public:

    vector<string> program;
    int programCounter = 0;

    set<string> vars;

    void gen(int command);

    void gen(string operand);

    void gen(OperationType operation);

    void compile(Node node);

    bool processVariables(Node& node);

    bool processArray(Node& node);

    bool processConstants(Node& node);

    void saveVariable(string varName, VarType varType);

    void saveConst(string value);

    void checkExistsVariable(string& varName);

    void checkNotExistsVariable(string& varName);
};

#endif