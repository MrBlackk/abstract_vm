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
    std::string pushStr = "push";
    std::string popStr = "pop";
    std::string dumpStr = "dump";
    std::string assertStr = "assert";
    std::string addStr = "add";
    std::string subStr = "sub";
    std::string mulStr = "mul";
    std::string divStr = "div";
    std::string modStr = "mod";
    std::string printStr = "print";
    std::string exitStr = "exit";
    std::string value;

    std::vector<std::string>::iterator it;
    for (it = file.begin(); it != file.end(); it++) {
        std::cout << *it << std::endl;
        if (!(*it).compare(0, pushStr.size(), pushStr)) {
            value = (*it).substr(pushStr.size() + 1);
            vm.push(getType(value), getNumber(value));
        } else if (!(*it).compare(0, popStr.size(), popStr)) {
            vm.pop();
        } else if (!(*it).compare(0, dumpStr.size(), dumpStr)) {
            vm.dump();
        } else if (!(*it).compare(0, assertStr.size(), assertStr)) {
            value = (*it).substr(assertStr.size() + 1);
            vm.assert(getType(value), getNumber(value));
        } else if (!(*it).compare(0, addStr.size(), addStr)) {
            vm.add();
        } else if (!(*it).compare(0, subStr.size(), subStr)) {
            vm.sub();
        } else if (!(*it).compare(0, mulStr.size(), mulStr)) {
            vm.mul();
        } else if (!(*it).compare(0, divStr.size(), divStr)) {
            vm.div();
        } else if (!(*it).compare(0, modStr.size(), modStr)) {
            vm.mod();
        } else if (!(*it).compare(0, printStr.size(), printStr)) {
            vm.print();
        } else if (!(*it).compare(0, exitStr.size(), exitStr)) {
            break;
        }
    }
}

eOperandType Parser::getType(std::string &value) {
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

std::string Parser::getNumber(std::string &value) {
    unsigned long first = value.find('(') + 1;
    unsigned long last = value.find(')');

    return value.substr(first, last - first);
}
