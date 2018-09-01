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

IOperand const *Operand::operator+(IOperand const &rhs) const {
    OperandFactory factory;
    prepareOperands(rhs);
    return factory.createOperand(_type, getStringWithoutTrailingZeros(_first + _second));
}

IOperand const *Operand::operator-(IOperand const &rhs) const {
    OperandFactory factory;
    prepareOperands(rhs);
    return factory.createOperand(_type, getStringWithoutTrailingZeros(_first - _second));
}

IOperand const *Operand::operator*(IOperand const &rhs) const {
    OperandFactory factory;
    prepareOperands(rhs);
    return factory.createOperand(_type, getStringWithoutTrailingZeros(_first * _second));
}

IOperand const *Operand::operator/(IOperand const &rhs) const {
    OperandFactory factory;
    prepareOperands(rhs);
    if (_second == 0) {
        throw WrongOperationException("Division by zero");
    }
    return factory.createOperand(_type, getStringWithoutTrailingZeros(_first / _second));
}

IOperand const *Operand::operator%(IOperand const &rhs) const {
    OperandFactory factory;
    if (this->getPrecision() >= Float || rhs.getPrecision() >= Float) {
        throw WrongOperationException("Floating point number modulo operation");
    }
    _type = this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType();
    long long first = std::stol(this->toString());
    long long second = std::stol(rhs.toString());
    if (second == 0) {
        throw WrongOperationException("Modulo by zero");
    }
    return factory.createOperand(_type, getStringWithoutTrailingZeros(first % second));
}

std::string const &Operand::toString(void) const {
    return _str;
}

const char *Operand::WrongOperationException::what() const throw() {
    return _message.c_str();
}

Operand::WrongOperationException::WrongOperationException() {}

Operand::WrongOperationException::WrongOperationException(std::string const &message) {
    _message = "Wrong Operation: " + message;
}

Operand::WrongOperationException::WrongOperationException(WrongOperationException const &src) { *this = src; }

Operand::WrongOperationException &Operand::WrongOperationException::operator=(WrongOperationException const &rhs) {
    this->_message = rhs._message;
    return *this;
}

Operand::WrongOperationException::~WrongOperationException() throw() {}

const char *Operand::OverUnderflowException::what() const throw() {
    return _message.c_str();
}

Operand::OverUnderflowException::OverUnderflowException() {}

Operand::OverUnderflowException::OverUnderflowException(std::string const &type, std::string const &value,
                                                        bool isOverflow) {
    _message = type + " " + (isOverflow ? "over" : "under") + "flow on: " + value;
}

Operand::OverUnderflowException::OverUnderflowException(OverUnderflowException const &src) { *this = src; }

Operand::OverUnderflowException &Operand::OverUnderflowException::operator=(OverUnderflowException const &rhs) {
    this->_message = rhs._message;
    return *this;
}

Operand::OverUnderflowException::~OverUnderflowException() throw() {}