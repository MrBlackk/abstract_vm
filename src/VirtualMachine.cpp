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
    line = 0;
}

VirtualMachine::VirtualMachine(VirtualMachine const &src) {
    *this = src;
}

VirtualMachine::~VirtualMachine() {
    std::vector<IOperand const *>::iterator it;
    for (it = _operands.begin(); it != _operands.end(); it++) {
        delete *it;
    }
    _operands.clear();
}

VirtualMachine &VirtualMachine::operator=(VirtualMachine const &rhs) {
    (void) rhs;
    return *this;
}

void VirtualMachine::push(eOperandType type, std::string const &value) {
    _operands.push_back(_factory.createOperand(type, value));
}

void VirtualMachine::assert(eOperandType type, std::string const &value) {
    checkStackSize("assert");
    IOperand const *operand = _operands.back();
    if (operand->getType() != type) {
        throw VirtualMachineException(
                "Assertion error - Wrong type: " + std::to_string(operand->getType()) + " vs " + std::to_string(type),
                line);
    }
    if (operand->toString() != value) {
        throw VirtualMachineException("Assertion error - Wrong value: " + operand->toString() + " vs " + value, line);
    }
}

void VirtualMachine::print() {
    checkStackSize("print");
    IOperand const *operand = _operands.back();
    assert(Int8, operand->toString());
    char ch = (char) std::stoi(operand->toString());
    std::cout << ch << std::endl;
}

void VirtualMachine::pop() {
    checkStackSize("pop");
    _operands.pop_back();
}

void VirtualMachine::add() {
    setOperands();
    _operands.push_back(*_op1 + *_op2);
    deleteOperands();
}

void VirtualMachine::setOperands() {
    checkStackSize("getting first operand");
    _op2 = _operands.back();
    _operands.pop_back();

    checkStackSize("getting second operand");
    _op1 = _operands.back();
    _operands.pop_back();
}

void VirtualMachine::deleteOperands() {
    delete _op1;
    delete _op2;
}

void VirtualMachine::dump() {
    std::vector<IOperand const *>::reverse_iterator it;
    for (it = _operands.rbegin(); it != _operands.rend(); it++)
        std::cout << (*it)->toString() << std::endl;
}

void VirtualMachine::sub() {
    setOperands();
    _operands.push_back(*_op1 - *_op2);
    deleteOperands();
}

void VirtualMachine::mul() {
    setOperands();
    _operands.push_back(*_op1 * *_op2);
    deleteOperands();
}


void VirtualMachine::div() {
    setOperands();
    _operands.push_back(*_op1 / *_op2);
    deleteOperands();
}

void VirtualMachine::mod() {
    setOperands();
    _operands.push_back(*_op1 % *_op2);
    deleteOperands();
}

void VirtualMachine::max() {
    setOperands();
    _operands.push_back(*_op1 > *_op2);
    deleteOperands();
}

void VirtualMachine::min() {
    setOperands();
    _operands.push_back(*_op1 < *_op2);
    deleteOperands();
}

void VirtualMachine::checkStackSize(std::string const &msg) {
    if (_operands.empty()) {
        throw VirtualMachineException("Stack is empty on " + msg, line);
    }
}

VirtualMachine::VirtualMachineException::VirtualMachineException() {}

const char *VirtualMachine::VirtualMachineException::what() const throw() {
    return _msg.c_str();
}

VirtualMachine::VirtualMachineException::VirtualMachineException(std::string const &msg, int line) : _msg(
        "VM line " + std::to_string(line) + ": " + msg) {}

VirtualMachine::VirtualMachineException::VirtualMachineException(VirtualMachineException const &src) {
    *this = src;
}

VirtualMachine::VirtualMachineException &
VirtualMachine::VirtualMachineException::operator=(VirtualMachineException const &rhs) {
    this->_msg = rhs._msg;
    return *this;
}

VirtualMachine::VirtualMachineException::~VirtualMachineException() throw() {}
