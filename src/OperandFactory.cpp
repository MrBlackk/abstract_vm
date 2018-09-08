/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:12:41 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/04 16:12:42 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "OperandFactory.hpp"
#include "operands/OperandInt8.hpp"
#include "operands/OperandInt16.hpp"
#include "operands/OperandInt32.hpp"
#include "operands/OperandFloat.hpp"
#include "operands/OperandDouble.hpp"

OperandFactory::OperandFactory() {}

OperandFactory::OperandFactory(OperandFactory const &src) {
    *this = src;
}

OperandFactory::~OperandFactory() {}

OperandFactory &OperandFactory::operator=(OperandFactory const &rhs) {
    (void) rhs;
    return *this;
}

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const {
    typedef IOperand const *(OperandFactory::*Create)(std::string const &value) const;
    Create create[5] = {&OperandFactory::createInt8,
                        &OperandFactory::createInt16,
                        &OperandFactory::createInt32,
                        &OperandFactory::createFloat,
                        &OperandFactory::createDouble};
    return (this->*(create[type]))(value);
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
    return new OperandInt8(value);
}

IOperand const *OperandFactory::createInt16(std::string const &value) const {
    return new OperandInt16(value);
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
    return new OperandInt32(value);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
    return new OperandFloat(value);
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
    return new OperandDouble(value);
}