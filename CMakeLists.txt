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
        src/operands/OperandInt16.hpp
        src/operands/OperandInt16.cpp
        src/operands/OperandInt32.hpp
        src/operands/OperandInt32.cpp
        src/operands/OperandFloat.hpp
        src/operands/OperandFloat.cpp
        src/operands/OperandDouble.hpp
        src/operands/OperandDouble.cpp
        src/VirtualMachine.hpp
        src/VirtualMachine.cpp
        src/Parser.hpp
        src/Parser.cpp
        src/Lexer.hpp
        src/Lexer.cpp
        src/operands/Operand.cpp
        src/operands/Operand.hpp)
