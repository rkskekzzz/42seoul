NAME	=	phonebook

CC		=	g++
INCLUDE =	-I./include
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE) -g
SRC		=	main.cpp \
			util.cpp


SRC_DIR =	./src/
SRCS	=	$(addprefix $(SRC_DIR),$(SRC))
OBJ		=	$(patsubst %.cpp,%.o,$(SRCS))
SHELL	=	/bin/bash

all		:	$(NAME)

%.o		:	%.cpp
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