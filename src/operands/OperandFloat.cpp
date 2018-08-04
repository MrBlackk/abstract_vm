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

#include <sstream>
#include <iomanip>
#include "OperandFloat.hpp"

OperandFloat::OperandFloat() {}

OperandFloat::OperandFloat(std::string const &value) {
    std::size_t pos = value.find('.');
    if (pos != std::string::npos)
        _precision = (int) (value.length() - pos - 1);
    else
        _precision = 1;

    _value = std::stold(value);
    _str = value;
}

OperandFloat::OperandFloat(OperandFloat const &src) {
    *this = src;
}

OperandFloat::~OperandFloat() {}

OperandFloat &OperandFloat::operator=(OperandFloat const &rhs) {
    _value = rhs._value;
    _precision = rhs._precision;
    _str = rhs._str;
    return *this;
}

std::string OperandFloat::getPreciseString(float value, int precision) const {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << value;
    return stream.str();
}

int OperandFloat::getPrecision(void) const {
    return 4;
}

eOperandType OperandFloat::getType(void) const {
    return Float;
}
//
//IOperand const *OperandFloat::operator+(IOperand const &rhs) const {
//    OperandFloat const *tmp = dynamic_cast<OperandFloat const *>(&rhs);
//    int maxPrecision = tmp->_precision > _precision ? tmp->_precision : _precision;
//    return new OperandFloat(getPreciseString(_value + tmp->_value, maxPrecision));
//}

IOperand const *OperandFloat::operator-(IOperand const &rhs) const {
    OperandFloat const *tmp = dynamic_cast<OperandFloat const *>(&rhs);
    int maxPrecision = tmp->_precision > _precision ? tmp->_precision : _precision;
    return new OperandFloat(getPreciseString(_value - tmp->_value, maxPrecision));
}

IOperand const *OperandFloat::operator*(IOperand const &rhs) const {
    OperandFloat const *tmp = dynamic_cast<OperandFloat const *>(&rhs);
    int maxPrecision = tmp->_precision > _precision ? tmp->_precision : _precision;
    return new OperandFloat(getPreciseString(_value * tmp->_value, maxPrecision));
}

IOperand const *OperandFloat::operator/(IOperand const &rhs) const {
    OperandFloat const *tmp = dynamic_cast<OperandFloat const *>(&rhs);
    int maxPrecision = tmp->_precision > _precision ? tmp->_precision : _precision;
    return new OperandFloat(getPreciseString(_value / tmp->_value, maxPrecision));
}

IOperand const *OperandFloat::operator%(IOperand const &rhs) const {
    // exception
    (void) rhs;
    return new OperandFloat("0");
}

std::string const &OperandFloat::toString(void) const {
    return _str;
}
