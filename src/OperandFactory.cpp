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
#include "OperandInt8.hpp"

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const {
    if (type == Int8) {
        return createInt8(value);
    }
    return createInt8(value);
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
    return new OperandInt8(value);
}
