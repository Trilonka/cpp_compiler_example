#include "Obj.cpp"

class Int : public Obj {
public:

    Int(std::string _value) : Obj(_value) {}

    Int(int _value) : Obj(std::to_string(_value)) {}

    virtual bool toBool() {
        if (_value == "0") return false;
        return true;
    }

    virtual VarType type() {
        return VarType::INT;
    }
};