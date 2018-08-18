/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:37:30 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/06 16:37:31 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>

class Lexer {
public:
    Lexer();
    Lexer(Lexer const & src);
    virtual ~Lexer();
    Lexer & operator=(Lexer const & rhs);

    void check(std::vector<std::string> &file);

    class LexicalException : public std::exception {

    public:
        virtual const char *what() const throw();
        LexicalException();
        LexicalException(LexicalException const &src);
        LexicalException &operator=(LexicalException const &rhs);
        virtual ~LexicalException() throw();
    };

private:
    void errorMessage(int line, std::string const &msg);

    bool _isOK;
};

#endif