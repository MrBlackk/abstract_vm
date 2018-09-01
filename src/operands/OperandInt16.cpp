/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt16.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:43:48 by vchornyi          #+#    #+#             */
/*   Updated: 2018/08/18 16:43:49 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandInt16.hpp"

OperandInt16::OperandInt16() {}

OperandInt16::OperandInt16(std::string const &value) : Operand(value) {
    checkNumberOverflow<short>("Int16", value);
}

OperandInt16::OperandInt16(OperandInt16 const &src) {
    *this = src;
}

OperandInt16::~OperandInt16() {}

OperandInt16 &OperandInt16::operator=(OperandInt16 const &rhs) {
    (void) rhs;
    return *this;
}

int OperandInt16::getPrecision(void) const {
    return 1;
}

eOperandType OperandInt16::getType(void) const {
    return Int16;
}

