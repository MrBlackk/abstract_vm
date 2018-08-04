//
// Created by chv on 13.07.2018.
//

#include "Operand.hpp"
#include "../OperandFactory.hpp"

IOperand const *Operand::operator+(IOperand const &rhs) const{
    OperandFactory factory;
    eOperandType type = this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType();
    double result = std::stold(this->toString()) + std::stold(rhs.toString());
    return factory.createOperand(type, std::to_string(result));
}