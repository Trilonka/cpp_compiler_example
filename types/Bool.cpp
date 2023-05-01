#include "Obj.cpp"

class Bool : public Obj {
public:

    Bool(std::string _value) : Obj(_value) {}

    Bool(bool _value) : Obj(std::to_string(_value)) {}

    virtual std::string toStr() {
        return _value;
    }

    virtual int toInt() {
        if (_value != "") return 1;
        return 0;
    }

    virtual double toReal() {
        if (_value != "") return 1.0;
        return 0.0;
    }

    virtual bool toBool() {
        if (_value != "") return true;
        return false;
    }

    virtual VarType type() {
        return VarType::BOOL;
    }
};