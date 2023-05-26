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
#include <any>
#include <functional>

class VirtualMachine {
public:

    std::map<std::string, std::string> vars;
    std::map<std::string, std::any> arrays;
    std::map<std::string, VarType> array_type;
    std::stack<std::string> stack;

    void run(std::vector<std::string> program);

    void fetch_new(std::string& arg);

    void fetch_arr(std::string type, int size);

    void store_array_element(std::string name, int index, std::string value);

    void compute_on_element(std::string name, int index, const std::function<void(Obj*)>& compute);
};

#endif