# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 22:24:46 by nshelly           #+#    #+#              #
#    Updated: 2019/08/13 15:07:06 by nshelly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/

SRC = src/main.c src/figures.c src/solution_map.c src/solve.c src/reader.c
OBJ = obj/main.o obj/figures.o obj/solution_map.o obj/solve.o obj/reader.o 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft

./obj/%.o: ./src/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -I includes/ -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
