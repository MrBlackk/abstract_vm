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
    std::cout << "Pushing type:" << type << " val: " << value << std::endl;
    _operands.push_back(_factory.createOperand(type, value));
}

void VirtualMachine::pop() {
    std::cout << "Pop" << std::endl;
    _operands.pop_back();
}

void VirtualMachine::add() {
    std::cout << "Adding" << std::endl;
    setOperands();
    _operands.push_back(*_op1 + *_op2);
}

void VirtualMachine::setOperands() {
    _op1 = _operands.back();
    _operands.pop_back();
    std::cout << "First type: " << (*_op1).getType();

    _op2 = _operands.back();
    _operands.pop_back();
    std::cout << " Second type: " << (*_op2).getType() << std::endl;
}

void VirtualMachine::dump() {
    std::cout << "Dump:" << std::endl;
    std::vector<IOperand const *>::iterator it;
    for (it = _operands.begin(); it != _operands.end(); it++)
        std::cout << (*it)->toString() << std::endl;
}

void VirtualMachine::sub() {
    std::cout << "Sub" << std::endl;
    setOperands();
    _operands.push_back(*_op1 - *_op2);
}

void VirtualMachine::mul() {
    std::cout << "Mul" << std::endl;
    setOperands();
    _operands.push_back(*_op1 * *_op2);
}


void VirtualMachine::div() {
    std::cout << "Div" << std::endl;
    setOperands();
    _operands.push_back(*_op1 / *_op2);
}

void VirtualMachine::mod() {
    std::cout << "Mod" << std::endl;
    setOperands();
    _operands.push_back(*_op1 % *_op2);
}
