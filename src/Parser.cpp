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

void Parser::parse(std::vector<std::string> &file) const {
    VirtualMachine vm;
    std::string pushStr = "push";
    std::string assertStr = "assert";
    std::string value;

    std::vector<std::string>::iterator it;
    for (it = file.begin(); it != file.end(); it++) {
        vm.line++;
        if (isCmd(it, pushStr)) {
            value = (*it).substr(pushStr.size() + 1);
            vm.push(getType(value), getNumber(value));
        } else if (isCmd(it, "pop")) {
            vm.pop();
        } else if (isCmd(it, "dump")) {
            vm.dump();
        } else if (isCmd(it, assertStr)) {
            value = (*it).substr(assertStr.size() + 1);
            vm.assert(getType(value), getNumber(value));
        } else if (isCmd(it, "add")) {
            vm.add();
        } else if (isCmd(it, "sub")) {
            vm.sub();
        } else if (isCmd(it, "mul")) {
            vm.mul();
        } else if (isCmd(it, "div")) {
            vm.div();
        } else if (isCmd(it, "mod")) {
            vm.mod();
        } else if (isCmd(it, "print")) {
            vm.print();
        } else if (isCmd(it, "exit")) {
            break;
        }
    }
}

eOperandType Parser::getType(std::string &value) const {
    std::string int8 = "int8";
    std::string int16 = "int16";
    std::string int32 = "int32";
    std::string floatType = "float";

    if (!value.compare(0, int8.size(), int8))
        return Int8;
    else if (!value.compare(0, int16.size(), int16))
        return Int16;
    else if (!value.compare(0, int32.size(), int32))
        return Int32;
    else if (!value.compare(0, floatType.size(), floatType))
        return Float;
    else
        return Double;
}

std::string Parser::getNumber(std::string &value) const {
    unsigned long first = value.find('(') + 1;
    unsigned long last = value.find(')');

    return value.substr(first, last - first);
}

bool Parser::isCmd(std::vector<std::string>::iterator it, std::string const &cmd) const {
    return !(*it).compare(0, cmd.size(), cmd);
}
