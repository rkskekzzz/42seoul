# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: su <su@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 18:43:46 by su                #+#    #+#              #
#    Updated: 2021/08/12 02:20:54 by suhshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc
INCLUDE =	-I./include
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE)
SRC		=	main.c \
			core/push_swap.c core/sort.c core/under5.c \
			utils/library.c utils/utils.c utils/split.c \
			list/list1.c list/list2.c \
			func/func1.c func/func2.c func/func3.c \


SRC_DIR =	./src/
SRCS	=	$(addprefix $(SRC_DIR),$(SRC))
OBJ		=	$(patsubst %.c,%.o,$(SRCS))
SHELL	=	/bin/bash

all		:	$(NAME)

%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@printf "PUSHSWAP \e[0;32mis Ready 💚\e[0m\n"



bonus	: all

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@rm -f $(NAME)

norm	:
	norminette src/*
	norminette include/*

re		:	fclean	all

.PHONY	:	all clean fclean re bonus norm
