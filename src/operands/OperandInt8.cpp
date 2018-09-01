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

#include "OperandInt8.hpp"

OperandInt8::OperandInt8() {}

OperandInt8::OperandInt8(std::string const &value) : Operand(value) {
    checkNumberOverflow<signed char>("Int8", value);
}

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
