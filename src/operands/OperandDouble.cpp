/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:43:32 by vchornyi          #+#    #+#             */
/*   Updated: 2018/08/18 16:43:33 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandDouble.hpp"

OperandDouble::OperandDouble() {}

OperandDouble::OperandDouble(std::string const &value) : Operand(value) {
    checkNumberOverflow<double>("Double", value);
}

OperandDouble::OperandDouble(OperandDouble const &src) {
    *this = src;
}

OperandDouble::~OperandDouble() {}

OperandDouble &OperandDouble::operator=(OperandDouble const &rhs) {
    (void) rhs;
    return *this;
}

int OperandDouble::getPrecision(void) const {
    return 4;
}

eOperandType OperandDouble::getType(void) const {
    return Double;
}
