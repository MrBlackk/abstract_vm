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

    VirtualMachine(VirtualMachine const &src);

    virtual ~VirtualMachine();

    VirtualMachine &operator=(VirtualMachine const &rhs);

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

    void max();

    void min();

    class VirtualMachineException : public std::exception {

    public:
        virtual const char *what() const throw();

        VirtualMachineException(std::string const &msg, int line);

        VirtualMachineException(VirtualMachineException const &src);

        VirtualMachineException &operator=(VirtualMachineException const &rhs);

        virtual ~VirtualMachineException() throw();

    private:
        VirtualMachineException();

        std::string _msg;
    };

    int line;
private:
    void setOperands();

    void deleteOperands();

    void checkStackSize(std::string const &msg);

    std::vector<IOperand const *> _operands;
    OperandFactory _factory;
    IOperand const *_op1;
    IOperand const *_op2;
};

#endif