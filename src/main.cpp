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

std::vector<std::string> readFile(std::istream &ifs) {
    std::vector<std::string> file;
    std::string line;

    while (getline(ifs, line)) {
        file.push_back(line);
    }
    return file;
}

int main(int argc, char **argv) {
    std::vector<std::string> file;
    if (argc > 1) {
        std::ifstream ifs(argv[1]);
        if (ifs) {
            file = readFile(ifs);
        } else {
            std::cout << "Read error" << std::endl;
        }
    } else {
        file = readFile(std::cin);
    }

    Parser parser;
    parser.parse(file);
}
