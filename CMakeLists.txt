cmake_minimum_required(VERSION 3.9)
project(abstract_vm)

set(CMAKE_CXX_STANDARD 11)

add_executable(avm
        src/main.cpp
        src/operands/IOperand.hpp
        src/eOperandType.hpp
        src/OperandFactory.hpp
        src/OperandFactory.cpp
        src/operands/OperandInt8.hpp
        src/operands/OperandInt8.cpp
        src/operands/OperandFloat.hpp
        src/operands/OperandFloat.cpp
        src/VirtualMachine.hpp
        src/VirtualMachine.cpp
        src/Parser.hpp
        src/Parser.cpp)
