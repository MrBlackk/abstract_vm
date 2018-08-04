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

OperandInt8::OperandInt8(std::string const &value) : Operand(value) {}

OperandInt8::OperandInt8(OperandInt8 const &src) {
    *this = src;
}

OperandInt8::~OperandInt8() {}

OperandInt8 &OperandInt8::operator=(OperandInt8 const &rhs) {
    (void) rhs;
    return *this;
}

int OperandInt8::getPrecision(void) const {
    return 0;
}

eOperandType OperandInt8::getType(void) const {
    return Int8;
}

IOperand const *OperandInt8::operator%(IOperand const &rhs) const {
    return new OperandInt8(std::to_string(std::stol(_str) % std::stol(rhs.toString())));
}

