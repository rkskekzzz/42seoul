NAME	=	philo

CC		=	gcc
INCLUDE =	-I./include
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE) -g
SRC		=	main.c debug.c \
			library/atoi.c \
			library/library.c \
			core/philo.c


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
