#pragma once

#ifndef _TYPE_BOOL

#define _TYPE_BOOL

#include "Obj.hpp"

class Bool : public Obj {
public:

    Bool(std::string _value);

    Bool(bool _value);

    virtual std::string toStr();

    virtual int toInt();

    virtual double toReal();

    virtual bool toBool();

    virtual VarType type();
};

#endif