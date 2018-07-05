/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:25:20 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/05 17:25:21 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include "eOperandType.hpp"

class Parser {
public:
    void parse(std::vector<std::string> &file);

private:
    eOperandType getType(std::string &value);

    std::string getNumber(std::string &value);
};

#endif