/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:46:05 by vchornyi          #+#    #+#             */
/*   Updated: 2018/08/04 17:46:08 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Operand.hpp"
#include "../OperandFactory.hpp"

Operand::Operand() {}

Operand::Operand(std::string const &value) {
    _str = value;
}

std::string Operand::getStringWithoutTrailingZeros(long double value) const {
    std::string str = std::to_string(value);
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    str.erase(str.find_last_not_of('.') + 1, std::string::npos);
    return str;
}

void Operand::prepareOperands(IOperand const &rhs) const {
    _type = this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType();
    _first = std::stold(this->toString());
    _second = std::stold(rhs.toString());
}

IOperand const *Operand::operator+(IOperand const &rhs) const{
    OperandFactory factory;
    prepareOperands(rhs);
    return factory.createOperand(_type, getStringWithoutTrailingZeros(_first + _second));
}

IOperand const *Operand::operator-(IOperand const &rhs) const{
    OperandFactory factory;
    prepareOperands(rhs);
    return factory.createOperand(_type, getStringWithoutTrailingZeros(_first - _second));
}

IOperand const *Operand::operator*(IOperand const &rhs) const{
    OperandFactory factory;
    prepareOperands(rhs);
    return factory.createOperand(_type, getStringWithoutTrailingZeros(_first * _second));
}

IOperand const *Operand::operator/(IOperand const &rhs) const{
    OperandFactory factory;
    prepareOperands(rhs);
    return factory.createOperand(_type, getStringWithoutTrailingZeros(_first / _second));
}

std::string const &Operand::toString(void) const {
    return _str;
}
