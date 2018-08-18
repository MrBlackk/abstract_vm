/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:37:34 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/06 16:37:36 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <regex>
#include "Lexer.hpp"

Lexer::Lexer() {
}

Lexer::Lexer(Lexer const &src) {
    *this = src;
}

Lexer::~Lexer() {}

Lexer &Lexer::operator=(Lexer const &rhs) {
    this->_isError = rhs._isError;
    return *this;
}

void Lexer::check(std::vector<std::string> &file) {
    std::regex instr("(pop|dump|add|sub|mul|div|mod|print)(;.*)?");
    std::regex instrParam("(push|assert) ((int8|int16|int32)\\(\\d+\\)|(float|double)\\(\\d+\\.\\d+\\))(;.*)?)");
    std::regex comment(";.*");
    std::regex emptyLine("");
    std::regex exit("exit");

    std::vector<std::string>::iterator it;
    int i = 1;
    for (it = file.begin(); it != file.end(); it++, i++) {
        if (std::regex_match(*it, exit)) {
            break;
        }
        if (!std::regex_match(*it, instr)
            && !std::regex_match(*it, instrParam)
            && !std::regex_match(*it, comment)
            && !std::regex_match(*it, emptyLine)) {
            errorMessage(i, *it);
        }
    }

    if (!std::regex_match(*it, exit)) {
        errorMessage(i, "No exit command at end");
    }

    if (_isError) {
        throw LexicalException();
    }
}

void Lexer::errorMessage(int line, std::string const &msg) {
    std::cout << "Lexical error on line " << line << ":'" << msg << "'"<< std::endl;
    _isError = true;
}

const char *Lexer::LexicalException::what() const throw() {
    return "Lexical error(s)";
}

Lexer::LexicalException::LexicalException() {}

Lexer::LexicalException::LexicalException(LexicalException const &src) { *this = src; }

Lexer::LexicalException &Lexer::LexicalException::operator=(LexicalException const &rhs) {
    (void) rhs;
    return *this;
}

Lexer::LexicalException::~LexicalException() throw() {}