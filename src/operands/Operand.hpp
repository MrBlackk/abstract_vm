/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:46:12 by vchornyi          #+#    #+#             */
/*   Updated: 2018/08/04 17:46:13 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP


#include "IOperand.hpp"

class Operand: public IOperand {
public:
    Operand();

    Operand(std::string const &value);

    IOperand const *operator+(IOperand const &rhs) const;

    IOperand const *operator-(IOperand const &rhs) const;

    IOperand const *operator*(IOperand const &rhs) const;

    IOperand const *operator/(IOperand const &rhs) const;

    std::string const &toString(void) const;

protected:
    std::string _str;

private:
    std::string getStringWithoutTrailingZeros(long double value) const;
    void prepareOperands(IOperand const &rhs)const;

    mutable long double _first;
    mutable long double _second;
    mutable eOperandType _type;

};

#endif //OPERAND_HPP
