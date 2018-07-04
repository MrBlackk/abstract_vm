cmake_minimum_required(VERSION 3.9)
project(abstract_vm)

set(CMAKE_CXX_STANDARD 11)

add_executable(avm
        src/main.cpp
        src/IOperand.hpp
        src/eOperandType.hpp
        src/OperandFactory.hpp)
