# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 15:18:06 by suhshin           #+#    #+#              #
#    Updated: 2022/02/18 15:18:08 by suhshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc
INCLUDE =	-I./include
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE) -g
SRC		=	main.c \
			library/atoi.c \
			library/isnum.c \
			library/time.c \
			library/message.c \
			entities/data.c \
			core/init.c \
			core/destroy.c \
			core/monitor.c \
			core/run.c \
			core/run_command.c


SRC_DIR =	./src/
SRCS	=	$(addprefix $(SRC_DIR),$(SRC))
OBJ		=	$(patsubst %.c,%.o,$(SRCS))
SHELL	=	/bin/bash

all		:	$(NAME)

%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@



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
