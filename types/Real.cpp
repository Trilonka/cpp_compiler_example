#include "Obj.cpp"

class Real : public Obj {
public:

    Real(std::string _value) : Obj(_value) {}

    Real(double _value) : Obj(std::to_string(_value)) {}

    virtual bool toBool() {
        if (_value == "0.0") return false;
        return true;
    }

    virtual VarType type() {
        return VarType::REAL;
    }
};