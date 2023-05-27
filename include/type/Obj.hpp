#pragma once

#ifndef _TYPE_OBJ

#define _TYPE_OBJ

#include <string>
#include <iostream>

#include "../Variable.hpp"

class Obj {

protected:

    std::string _value;

public:

    Obj(std::string __value);

    virtual std::string toStr();

    virtual int toInt();

    virtual double toReal();

    virtual bool toBool();

    virtual char toChar();

    virtual VarType type();

    virtual std::string toStore();
};

#endif