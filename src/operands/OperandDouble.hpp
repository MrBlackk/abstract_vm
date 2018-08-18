/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandDouble.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:43:37 by vchornyi          #+#    #+#             */
/*   Updated: 2018/08/18 16:43:39 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_DOUBLE_HPP
#define OPERAND_DOUBLE_HPP

#include "../eOperandType.hpp"
#include "Operand.hpp"

class OperandDouble : public Operand {

public:
    OperandDouble(std::string const &value);

    OperandDouble(OperandDouble const &src);

    virtual ~OperandDouble();

    OperandDouble &operator=(OperandDouble const &rhs);

    int getPrecision(void) const;

    eOperandType getType(void) const;

private:
    OperandDouble();

};

#endif
