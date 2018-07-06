/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:11:23 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/04 14:11:24 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_OPERAND_HPP
#define I_OPERAND_HPP

#include <string>
#include "../eOperandType.hpp"

class IOperand {

public:
    virtual int getPrecision(void) const = 0;

    virtual eOperandType getType(void) const = 0;

    virtual IOperand const *operator+(IOperand const &rhs) const = 0;

    virtual IOperand const *operator-(IOperand const &rhs) const = 0;

    virtual IOperand const *operator*(IOperand const &rhs) const = 0;

    virtual IOperand const *operator/(IOperand const &rhs) const = 0;

    virtual IOperand const *operator%(IOperand const &rhs) const = 0;

    virtual std::string const &toString(void) const = 0;

    virtual ~IOperand(void) {}
};

#endif

