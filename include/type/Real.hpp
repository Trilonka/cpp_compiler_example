#pragma once

#ifndef _TYPE_REAL

#define _TYPE_REAL

#include "Obj.hpp"
#include <sstream>
#include <iomanip>

class Real : public Obj {
public:

    Real(std::string _value);

    Real(double _value);

    virtual bool toBool();

    virtual VarType type();
};

#endif