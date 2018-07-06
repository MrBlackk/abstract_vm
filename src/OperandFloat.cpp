/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:09:46 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/06 13:09:47 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "OperandFloat.hpp"

OperandFloat::OperandFloat() {}

OperandFloat::OperandFloat(std::string const &value) {
    _value = std::stof(value);
    _str = value;
}

OperandFloat::OperandFloat(OperandFloat const &src) {
    *this = src;
}

OperandFloat::~OperandFloat() {}

OperandFloat &OperandFloat::operator=(OperandFloat const &rhs) {
    _value = rhs._value;
    return *this;
}

int OperandFloat::getPrecision(void) const {
    return 0;
}

eOperandType OperandFloat::getType(void) const {
    return Float;
}

IOperand const *OperandFloat::operator+(IOperand const &rhs) const {
    OperandFloat const *tmp = dynamic_cast<OperandFloat const *>(&rhs);
    return new OperandFloat(std::to_string(_value + tmp->_value));
}

IOperand const *OperandFloat::operator-(IOperand const &rhs) const {
    OperandFloat const *tmp = dynamic_cast<OperandFloat const *>(&rhs);
    return new OperandFloat(std::to_string(_value - tmp->_value));
}

IOperand const *OperandFloat::operator*(IOperand const &rhs) const {
    OperandFloat const *tmp = dynamic_cast<OperandFloat const *>(&rhs);
    return new OperandFloat(std::to_string(_value * tmp->_value));
}

IOperand const *OperandFloat::operator/(IOperand const &rhs) const {
    OperandFloat const *tmp = dynamic_cast<OperandFloat const *>(&rhs);
    return new OperandFloat(std::to_string(_value / tmp->_value));
}

IOperand const *OperandFloat::operator%(IOperand const &rhs) const {
    // exception
    return new OperandFloat("0");
}

std::string const &OperandFloat::toString(void) const {
    return _str;
}
