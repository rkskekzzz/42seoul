NAME	=	string

CC		=	g++
INCLUDE =	-I./
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 $(INCLUDE)
SRC		=	main.cpp 


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

re		:	fclean	all

.PHONY	:	all clean fclean re bonus norm