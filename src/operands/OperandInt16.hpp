/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt16.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:44:00 by vchornyi          #+#    #+#             */
/*   Updated: 2018/08/18 16:44:01 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_INT16_HPP
#define OPERAND_INT16_HPP

#include "../eOperandType.hpp"
#include "Operand.hpp"

class OperandInt16 : public Operand {

public:
    OperandInt16(std::string const &value);

    OperandInt16(OperandInt16 const &src);

    virtual ~OperandInt16();

    OperandInt16 &operator=(OperandInt16 const &rhs);

    int getPrecision(void) const;

    eOperandType getType(void) const;

private:
    OperandInt16();
};

#endif