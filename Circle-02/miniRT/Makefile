# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:07:00 by suhshin           #+#    #+#              #
#    Updated: 2021/05/17 04:15:29 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS	=	\
			minirt.c \
			./srcs/rt_vector/vector1.c \
			./srcs/rt_vector/vector2.c \
			./srcs/rt_vector/vector3.c \
			./srcs/rt_vector/vector4.c \
			./srcs/rt_vector/vector5.c \
			./srcs/rt_vector/vector6.c \
			./srcs/rt_vector/vector7.c \
			./srcs/rt_event/event.c	\
			./srcs/rt_camera/camera.c \
			./srcs/rt_camera/render.c \
			./srcs/rt_object/world.c \
			./srcs/rt_object/sphere.c \
			./srcs/rt_object/plane.c \
			./srcs/rt_object/square.c \
			./srcs/rt_object/cylinder.c \
			./srcs/rt_object/triangle.c \
			./srcs/rt_library/lib1.c \
			./srcs/rt_library/lib2.c \
			./srcs/rt_library/lib3.c \
			./srcs/rt_library/lib4.c \
			./srcs/rt_library/lib5.c \
			./srcs/rt_material/lambertian.c \
			./srcs/rt_material/metal.c \
			./srcs/rt_material/dielectric.c \
			./srcs/rt_parsing/parse.c \
			./srcs/rt_parsing/parse1.c \
			./srcs/rt_parsing/parse2.c \
			./srcs/rt_parsing/util.c \
			./srcs/rt_light/light.c \
#
#
#

SRC_DIR	=	./srcs

INCLUDE =	-Iinclude -Isrcs/mlx -I./

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	#-Wall -Werror -Wextra
CLIB	=	-Lsrcs/mlx -lmlx -framework OpenGL -framework Appkit $(INCLUDE)

#
# Rules
#

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib srcs/mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
