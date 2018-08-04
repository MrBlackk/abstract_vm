/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt8.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:48:25 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/04 15:48:27 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_INT8_HPP
#define OPERAND_INT8_HPP

#include "IOperand.hpp"
#include "../eOperandType.hpp"
#include "Operand.hpp"

class OperandInt8 : public Operand {

public:
    OperandInt8(std::string const &value);

    OperandInt8(OperandInt8 const &src);

    virtual ~OperandInt8();

    OperandInt8 &operator=(OperandInt8 const &rhs);

    int getPrecision(void) const;

    eOperandType getType(void) const;

//    IOperand const *operator+(IOperand const &rhs) const;

    IOperand const *operator-(IOperand const &rhs) const;

    IOperand const *operator*(IOperand const &rhs) const;

    IOperand const *operator/(IOperand const &rhs) const;

    IOperand const *operator%(IOperand const &rhs) const;

    std::string const &toString(void) const;

private:
    OperandInt8();

    char _value;
    std::string _str;

};

#endif