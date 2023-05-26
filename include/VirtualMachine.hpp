#pragma once

#ifndef _VM

#define _VM

#include "iostream"
#include "enum/VMCommands.hpp"
#include <vector>
#include <string>
#include <stack>
#include <map>
#include "Calculations.hpp"

class VirtualMachine {
public:

    std::map<std::string, std::string> vars;
    std::map<std::string, std::string> arrays;
    std::stack<std::string> stack;

    void run(std::vector<std::string> program);

    void fetch_new(std::string& arg);

    void fetch_arr(std::string type, std::string name);
};

#endif