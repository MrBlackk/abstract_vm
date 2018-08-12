/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualMachine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:32:20 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/05 14:32:21 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_HPP

#include <vector>
#include "operands/IOperand.hpp"
#include "OperandFactory.hpp"

class VirtualMachine {
public:
    VirtualMachine();

    void push(eOperandType type, std::string const &value);

    void assert(eOperandType type, std::string const &value);

    void pop();

    void print();

    void add();

    void dump();

    void sub();

    void mul();

    void div();

    void mod();

private:
    void setOperands();

    std::vector<IOperand const *> _operands;
    OperandFactory _factory;
    IOperand const *_op1;
    IOperand const *_op2;
};

#endif