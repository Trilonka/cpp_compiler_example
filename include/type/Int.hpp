#pragma once

#ifndef _TYPE_INT

#define _TYPE_INT

#include "Obj.hpp"

class Int : public Obj {
public:

    Int(std::string _value);

    Int(int _value);

    virtual bool toBool();

    virtual VarType type();
};

#endif