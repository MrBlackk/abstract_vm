/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt8.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:48:30 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/04 15:48:31 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "OperandInt8.hpp"

OperandInt8::OperandInt8() {}

OperandInt8::OperandInt8(std::string const &value) {
    _value = (char)std::stoi(value);
    _str = std::to_string(_value);
}

OperandInt8::OperandInt8(OperandInt8 const &src) {
    *this = src;
}

OperandInt8::~OperandInt8() {}

OperandInt8 &OperandInt8::operator=(OperandInt8 const &rhs) {
    _value = rhs._value;
    return *this;
}

int OperandInt8::getPrecision(void) const {
    return 0;
}

eOperandType OperandInt8::getType(void) const {
    return Int8;
}

//IOperand const *OperandInt8::operator+(IOperand const &rhs) const {
//    OperandInt8 const *tmp = dynamic_cast<OperandInt8 const *>(&rhs);
//    return new OperandInt8(std::to_string(_value + tmp->_value));
//}

IOperand const *OperandInt8::operator-(IOperand const &rhs) const {
    OperandInt8 const *tmp = dynamic_cast<OperandInt8 const *>(&rhs);
    return new OperandInt8(std::to_string(_value - tmp->_value));
}

IOperand const *OperandInt8::operator*(IOperand const &rhs) const {
    OperandInt8 const *tmp = dynamic_cast<OperandInt8 const *>(&rhs);
    return new OperandInt8(std::to_string(_value * tmp->_value));
}

IOperand const *OperandInt8::operator/(IOperand const &rhs) const {
    OperandInt8 const *tmp = dynamic_cast<OperandInt8 const *>(&rhs);
    return new OperandInt8(std::to_string(_value / tmp->_value));
}

IOperand const *OperandInt8::operator%(IOperand const &rhs) const {
    OperandInt8 const *tmp = dynamic_cast<OperandInt8 const *>(&rhs);
    return new OperandInt8(std::to_string(_value % tmp->_value));
}

std::string const &OperandInt8::toString(void) const {
    return _str;
}
