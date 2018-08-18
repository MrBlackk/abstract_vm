# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 13:18:06 by vchornyi          #+#    #+#              #
#    Updated: 2018/07/04 13:18:08 by vchornyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm
FLAGS = -Wall -Wextra -Werror
INC = -I./src/operands/IOperand.hpp -I./src/eOperandType.hpp -I./src/OperandFactory.hpp \
-I./src/operands/Operand.hpp -I./src/operands/OperandInt8.hpp -I./src/operands/OperandInt16.hpp \
-I./src/operands/OperandInt32.hpp -I./src/operands/OperandFloat.hpp -I./src/operands/OperandDouble.hpp \
-I./src/VirtualMachine.hpp  -I./src/Parser.hpp  -I./src/Lexer.hpp

SRC_NAME = main.cpp OperandFactory.cpp operands/Operand.cpp operands/OperandInt8.cpp operands/OperandInt16.cpp \
operands/OperandInt32.cpp operands/OperandFloat.cpp operands/OperandDouble.cpp VirtualMachine.cpp Parser.cpp Lexer.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

SRC_DIR = src/
OBJ_DIR = objs/

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ -o $(NAME) $(OBJ) -lncurses
	@echo "##### avm compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/operands
	@echo "##### Creating" [ $@ ] " #####"
	@clang++ $(FLAGS) -o $@ -c $< $(INC)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "##### Removed object files #####"

fclean: clean
	@rm -f $(NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re
