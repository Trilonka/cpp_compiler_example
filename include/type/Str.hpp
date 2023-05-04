#pragma once

#include "Obj.hpp"

class Str : public Obj {
public:

    Str(std::string _value);

    virtual VarType type();
};