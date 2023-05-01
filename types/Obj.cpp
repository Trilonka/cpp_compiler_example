#ifndef _TYPE_OBJ

#define _TYPE_OBJ

#include <string>
#include <iostream>
#include <exception>
#include "../Variable.cpp"

class Obj {

protected:

    std::string _value;

public:

    Obj(std::string __value) {
        _value = __value;
    }

    virtual std::string toStr() {
        return _value;
    }

    virtual int toInt() {
        try {
            return std::stoi(_value);
        } catch (std::exception &e) {
            std::cout << _value << " to [Int] converison not allowed.\n";
            exit(1);
        }
    }

    virtual double toReal() {
        try {
            return std::stod(_value);
        } catch (std::exception &e) {
            std::cout << _value << " to [Real] converison not allowed.\n";
            exit(1);
        }
    }

    virtual bool toBool() {
        if (_value != "") return true;
        return false;
    }

    virtual VarType type() {
        return VarType::OBJ;
    }

    virtual std::string toStore() {
        return vartypeNames[type()] + " " + _value;
    }
};

#endif