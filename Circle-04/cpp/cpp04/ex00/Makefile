NAME		=	a.out

INCLUDE 	=	-I./include

CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 $(INCLUDE)

SRC			=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp


SRC_DIR 	=	./src/
SRCS		=	$(addprefix $(SRC_DIR),$(SRC))
OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.cpp,%.o,$(SRC)))
SHELL		=	/bin/bash

all		:	$(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@



bonus	: all

clean	:
	@rm -rf $(OBJ_DIR)

fclean	:	clean
	@rm -f $(NAME)

norm	:
	norminette src/*
	norminette include/*

re		:	fclean	all

.PHONY	:	all clean fclean re bonus norm
