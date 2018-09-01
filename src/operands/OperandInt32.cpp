/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt32.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:44:07 by vchornyi          #+#    #+#             */
/*   Updated: 2018/08/18 16:44:08 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandInt32.hpp"

OperandInt32::OperandInt32() {}

OperandInt32::OperandInt32(std::string const &value) : Operand(value) {
    checkNumberOverflow<int>("Int32", value);
}

OperandInt32::OperandInt32(OperandInt32 const &src) {
    *this = src;
}

OperandInt32::~OperandInt32() {}

OperandInt32 &OperandInt32::operator=(OperandInt32 const &rhs) {
    (void) rhs;
    return *this;
}

int OperandInt32::getPrecision(void) const {
    return 2;
}

eOperandType OperandInt32::getType(void) const {
    return Int32;
}

