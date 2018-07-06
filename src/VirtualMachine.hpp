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

    void add();

    void dump();

private:
    std::vector<IOperand const *> _operands;
    OperandFactory _factory;
};

#endif