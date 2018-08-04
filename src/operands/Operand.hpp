//
// Created by chv on 13.07.2018.
//

#ifndef OPERAND_HPP
#define OPERAND_HPP


#include "IOperand.hpp"

class Operand: public IOperand {
public:
//    virtual int getPrecision(void) const = 0;
//
//    virtual eOperandType getType(void) const = 0;

    IOperand const *operator+(IOperand const &rhs) const;

//    virtual IOperand const *operator-(IOperand const &rhs) const = 0;
//
//    virtual IOperand const *operator*(IOperand const &rhs) const = 0;
//
//    virtual IOperand const *operator/(IOperand const &rhs) const = 0;
//
//    virtual IOperand const *operator%(IOperand const &rhs) const = 0;
//
//    virtual std::string const &toString(void) const = 0;
};

#endif //OPERAND_HPP
