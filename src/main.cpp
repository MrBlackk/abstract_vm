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
#include <vector>
#include "Parser.hpp"
#include "Lexer.hpp"

std::vector<std::string> readInstructions(std::istream &ifs, bool isStdIn) {
    std::vector<std::string> file;
    std::string line;

    while (getline(ifs, line)) {
		if (isStdIn && line == ";;") {
			return file;
		}
        file.push_back(line);
    }
    return file;
}

int main(int argc, char **argv) {
    std::vector<std::string> instructions;
    if (argc > 1) {
        std::ifstream ifs(argv[1]);
        if (ifs) {
            instructions = readInstructions(ifs, false);
        } else {
            std::cout << "Read error" << std::endl;
        }
    } else {
        instructions = readInstructions(std::cin, true);
    }

    try {
        Lexer lexer;
        lexer.check(instructions);

        Parser parser;
        parser.parse(instructions);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl << "Stopping virtual machine." << std::endl;
        return -1;
    }
}
