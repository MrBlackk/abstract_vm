/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualMachine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:32:25 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/05 14:32:26 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "VirtualMachine.hpp"

VirtualMachine::VirtualMachine() {
}

void VirtualMachine::push(eOperandType type, std::string const &value) {
    std::cout << "Pushing " << value << std::endl;
    _operands.push_back(_factory.createOperand(type, value));
}

void VirtualMachine::add() {
    std::cout << "Adding" << std::endl;
    IOperand const *op1 = _operands.back();
    _operands.pop_back();

    IOperand const *op2 = _operands.back();
    _operands.pop_back();

    _operands.push_back(*op1 + *op2);
}

void VirtualMachine::dump() {
    std::cout << "Dump:" << std::endl;
    std::vector<IOperand const *>::iterator it;
    for (it = _operands.begin(); it != _operands.end(); it++)
        std::cout << (*it)->toString() << std::endl;
}