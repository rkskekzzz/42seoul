# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: su <su@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 18:43:46 by su                #+#    #+#              #
#    Updated: 2021/08/25 18:55:50 by su               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CH_NAME	=	checker

CC		=	gcc
INCLUDE =	-I./include
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE)

CH_SRC	=	./src/checker.c
PS_SRC	=	./src/ps.c

SRC		=	core/push_swap.c core/sort.c core/under5.c \
			utils/library.c utils/utils.c utils/split.c \
			list/list1.c list/list2.c \
			func/func1.c func/func2.c func/func3.c \


SRC_DIR =	./src/
SRCS	=	$(addprefix $(SRC_DIR),$(SRC))
SHELL	=	/bin/bash


PS_OBJ	=	$(patsubst %.c,%.o,$(SRCS)) \
			$(patsubst %.c,%.o,$(PS_SRC))
CH_OBJ	=	$(patsubst %.c,%.o,$(SRCS)) \
			$(patsubst %.c,%.o,$(CH_SRC))

all		:	$(NAME)

%.o		:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(PS_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "PUSHSWAP \e[0;32mis Ready 💚\e[0m\n"

checker	:	$(CH_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

bonus	:	all

clean	:
	@rm -f $(PS_OBJ)

fclean	:	clean
	@rm -f $(NAME) $(CH_NAME)

norm	:
	norminette src/*
	norminette include/*

re		:	fclean	all

.PHONY	:	all clean fclean re bonus norm checker
