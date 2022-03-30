#ifndef CASTCLASS_HPP
#define CASTCLASS_HPP

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

class CastClass {
public:
    CastClass(std::string value);
    ~CastClass();
    CastClass(CastClass const&);

    CastClass& operator=(CastClass const&);

    char castToChar();
    int castToInt();
    float castToFloat();
    double castToDouble(std::string value);
    bool regexValue(std::string value);

    void printCharValue();
    void printIntValue();
    void printDoubleValue();
    void printFloatValue();

    enum InputType {
        Number = 0,
        Char,
        NaN,
        Inf,
        CantCasting
    };
    CastClass::InputType getType();
    class Imposible : public std::exception {
        const char * what() const throw();
    };
    class NonDisplayable : public std::exception {
        const char * what() const throw();
    };

private:
    double value;
    InputType type;
};

#endif
