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

class Operand : public IOperand {
public:
    Operand();

    Operand(Operand const &src);

    virtual ~Operand();

    Operand &operator=(Operand const &rhs);

    Operand(std::string const &value);

    IOperand const *operator+(IOperand const &rhs) const;

    IOperand const *operator-(IOperand const &rhs) const;

    IOperand const *operator*(IOperand const &rhs) const;

    IOperand const *operator/(IOperand const &rhs) const;

    IOperand const *operator%(IOperand const &rhs) const;

    IOperand const *operator>(IOperand const &rhs) const;

    IOperand const *operator<(IOperand const &rhs) const;

    std::string const &toString(void) const;

    class OperandException : public std::exception {

    public:
        OperandException();

        virtual const char *what() const throw();

        OperandException(std::string const &message);

        OperandException(OperandException const &src);

        OperandException &operator=(OperandException const &rhs);

        virtual ~OperandException() throw();

    private:
        std::string _message;
    };

    class WrongOperationException : public OperandException {

    public:
        virtual const char *what() const throw();

        WrongOperationException(std::string const &message);

        WrongOperationException(WrongOperationException const &src);

        WrongOperationException &operator=(WrongOperationException const &rhs);

        virtual ~WrongOperationException() throw();

    private:
        WrongOperationException();

        std::string _message;
    };

    class OverUnderflowException : public OperandException {

    public:
        virtual const char *what() const throw();

        OverUnderflowException(std::string const &type, std::string const &value, bool isOverflow);

        OverUnderflowException(OverUnderflowException const &src);

        OverUnderflowException &operator=(OverUnderflowException const &rhs);

        virtual ~OverUnderflowException() throw();

    private:
        OverUnderflowException();

        std::string _message;
    };

protected:
    std::string _str;

    template<typename T>
    void checkNumberOverflow(std::string const &type, std::string const &value) {
        long double num = std::stold(value);
        if (num > std::numeric_limits<T>::max()) {
            throw OverUnderflowException(type, value, true);
        } else if (num < std::numeric_limits<T>::lowest()) {
            throw OverUnderflowException(type, value, false);
        }
    }

private:
    std::string getStringWithoutTrailingZeros(long double value) const;

    void prepareOperands(IOperand const &rhs) const;

    mutable long double _first;
    mutable long double _second;
    mutable eOperandType _type;

};

#endif //OPERAND_HPP
