/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:25:25 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/05 17:25:26 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Parser.hpp"
#include "VirtualMachine.hpp"

void Parser::parse(std::vector<std::string> &file) {
    VirtualMachine vm;
    std::string pushStr = "push ";
    std::string dumpStr = "dump";
    std::string addStr = "add";
    std::string value;

    std::vector<std::string>::iterator it;
    for (it = file.begin(); it != file.end(); it++) {
        std::cout << *it << std::endl;
        if (!(*it).compare(0, pushStr.size(), pushStr)) {
            value = (*it).substr(pushStr.size());
            vm.push(getType(value), getNumber(value));
        } else if (!(*it).compare(0, dumpStr.size(), dumpStr)) {
            vm.dump();
        } else if (!(*it).compare(0, addStr.size(), addStr)) {
            vm.add();
        }
    }
}

eOperandType Parser::getType(std::string &value) {
    std::string int8 = "int8";
    std::string floatType = "float";

    if (!value.compare(0, int8.size(), int8))
        return Int8;
    if (!value.compare(0, floatType.size(), floatType))
        return Float;
    return Int8;
}

std::string Parser::getNumber(std::string &value) {
    unsigned long first = value.find('(') + 1;
    unsigned long last = value.find(')');

    return value.substr(first, last - first);
}
