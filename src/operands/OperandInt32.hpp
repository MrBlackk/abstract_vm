/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt32.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:44:14 by vchornyi          #+#    #+#             */
/*   Updated: 2018/08/18 16:44:15 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_INT32_HPP
#define OPERAND_INT32_HPP

#include "../eOperandType.hpp"
#include "Operand.hpp"

class OperandInt32 : public Operand {

public:
    OperandInt32(std::string const &value);

    OperandInt32(OperandInt32 const &src);

    virtual ~OperandInt32();

    OperandInt32 &operator=(OperandInt32 const &rhs);

    int getPrecision(void) const;

    eOperandType getType(void) const;

private:
    OperandInt32();
};

#endif
