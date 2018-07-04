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
INC = -I./src/IOperand.hpp -I./src/eOperandType.hpp -I./src/OperandFactory.hpp

SRC_NAME = main.cpp

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
