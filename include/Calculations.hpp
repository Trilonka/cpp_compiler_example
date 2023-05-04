#pragma once

#ifndef _CALCULATIONS

#define _CALCULATIONS

#include <string>
#include "Variable.hpp"
#include "type/Vars.hpp"

Obj* wrap(std::string var);

std::string multi_str(std::string str, int count);

Obj* sum(std::string left_operand, std::string right_operand);

Obj* sub(std::string left_operand, std::string right_operand);

Obj* mul(std::string left_operand, std::string right_operand);

Obj* div(std::string left_operand, std::string right_operand);

#endif
