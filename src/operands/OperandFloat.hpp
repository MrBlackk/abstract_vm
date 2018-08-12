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
#include "Operand.hpp"

class OperandFloat : public Operand {

public:
    OperandFloat(std::string const &value);

    OperandFloat(OperandFloat const &src);

    virtual ~OperandFloat();

    OperandFloat &operator=(OperandFloat const &rhs);

    int getPrecision(void) const;

    eOperandType getType(void) const;

private:
    OperandFloat();

};

#endif