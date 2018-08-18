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

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const {
    switch (type) {
        case Int8:
            return createInt8(value);
        case Int16:
            return createInt16(value);
        case Int32:
            return createInt32(value);
        case Float:
            return createFloat(value);
        case Double:
            return createDouble(value);
        default:
            // todo: exception
            return nullptr;
    }
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