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

#include "OperandFloat.hpp"

OperandFloat::OperandFloat() {}

OperandFloat::OperandFloat(std::string const &value) : Operand(value) {
    checkNumberOverflow<float>("Float", value);
}

OperandFloat::OperandFloat(OperandFloat const &src) {
    *this = src;
}

OperandFloat::~OperandFloat() {}

OperandFloat &OperandFloat::operator=(OperandFloat const &rhs) {
    (void) rhs;
    return *this;
}

int OperandFloat::getPrecision(void) const {
    return 3;
}

eOperandType OperandFloat::getType(void) const {
    return Float;
}

