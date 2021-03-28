# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:07:00 by suhshin           #+#    #+#              #
#    Updated: 2021/03/26 15:52:35 by suhshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

SRCS	=	\
			minirt.c

#
#
#

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-L./minilibx -lmlx -framework OpenGL -framework Appkit

#
# Rules
#

all		: $(NAME)

$.o: $.c
  $(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
  $(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
