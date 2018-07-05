/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:20:11 by vchornyi          #+#    #+#             */
/*   Updated: 2018/07/04 13:20:12 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "OperandFactory.hpp"

std::string readData(std::istream &ifs) {
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    return buffer.str();
}

int main(int argc, char **argv) {

    std::string fileStr;
    if (argc > 1) {
        std::ifstream ifs(argv[1]);
        if (ifs) {
            fileStr = readData(ifs);
        } else {
            std::cout << "Read error" << std::endl;
        }
    } else {
        fileStr = readData(std::cin);
    }

    std::cout << fileStr << std::endl;

    OperandFactory *factory = new OperandFactory();

    IOperand const *op1 = factory->createOperand(Int8, "42");
    std::cout << op1->toString() << std::endl;

    IOperand const *op2 = factory->createOperand(Int8, "43");
    std::cout << op2->toString() << std::endl;

    IOperand const *op3 = *op1 + *op2;
    std::cout << op3->toString() << std::endl;

}
