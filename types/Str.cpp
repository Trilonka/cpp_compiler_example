#include "Obj.cpp"

class Str : public Obj {
public:

    Str(std::string _value) : Obj(_value) {}

    virtual VarType type() {
        return VarType::STRING;
    }
};