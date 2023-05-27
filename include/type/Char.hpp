#pragma once

#ifndef _TYPE_CHAR

#define _TYPE_CHAR

#include "Obj.hpp"

class Char : public Obj {
public:

    Char(std::string _value);

    Char(int _value);

    Char(char _value);

    virtual int toInt();

    virtual double toReal();

    virtual bool toBool();

    virtual VarType type();
};

#endif