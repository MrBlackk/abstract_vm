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

void Lexer::check(std::vector<std::string> &file) {
    std::regex instr("(pop|dump|add|sub|mul|div|mod|print|exit)(;.*)?");
    std::regex instrInt("(push|assert) ((int8|int16|int32)\\(\\d+\\)|(float|double)\\(\\d+.\\d+\\))(;.*)?)");
    std::regex comment(";.*");
    std::regex emptyLine("");

    std::vector<std::string>::iterator it;
    int i = 1;
    for (it = file.begin(); it != file.end(); it++, i++) {
        if (!std::regex_match(*it, instr)
            && !std::regex_match(*it, instrInt)
            && !std::regex_match(*it, comment)
            && !std::regex_match(*it, emptyLine)) {
            std::cout << "Line " << i << ":'" << *it << "' - " << "lexical ERROR" << std::endl;
        }
    }

    std::regex exit("exit");
    if (!std::regex_match(file.back(), exit)) {
        std::cout << "Error: No exit command at end" << std::endl;
    }
}