/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFloat.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:09:41 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/06 13:09:43 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_FLOAT_HPP
#define OPERAND_FLOAT_HPP

#include "IOperand.hpp"
#include "../eOperandType.hpp"

class OperandFloat : public IOperand {

public:
    OperandFloat(std::string const &value);

    OperandFloat(OperandFloat const &src);

    virtual ~OperandFloat();

    OperandFloat &operator=(OperandFloat const &rhs);

    int getPrecision(void) const;

    eOperandType getType(void) const;

    IOperand const *operator+(IOperand const &rhs) const;

    IOperand const *operator-(IOperand const &rhs) const;

    IOperand const *operator*(IOperand const &rhs) const;

    IOperand const *operator/(IOperand const &rhs) const;

    IOperand const *operator%(IOperand const &rhs) const;

    std::string const &toString(void) const;

private:
    OperandFloat();

    float _value;
    std::string _str;

};

#endif