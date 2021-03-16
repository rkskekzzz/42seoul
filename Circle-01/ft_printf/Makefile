# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 16:04:58 by suhshin           #+#    #+#              #
#    Updated: 2021/03/15 01:39:18 by suhshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wextra -Wall -Werror -I . -c
SRCS					= ft_printf.c \
						ft_utils/ft_print_utils.c \
						ft_handler/ft_print_handler.c \
						ft_handler/ft_print_handler_c.c \
						ft_handler/ft_print_handler_s.c \
						ft_handler/ft_print_handler_n.c \
						ft_utils/ft_print_utils_cal.c \
						ft_utils/ft_print_utils_isfunc.c \
						ft_utils/ft_print_utils_lib.c \
						ft_utils/ft_print_utils_string.c \
						ft_utils/ft_print_utils_xtox.c

BNS_SRCS					= ft_printf_bonus.c \
						ft_utils/ft_print_utils_bonus.c \
						ft_handler/ft_print_handler_bonus.c \
						ft_handler/ft_print_handler_c_bonus.c \
						ft_handler/ft_print_handler_s_bonus.c \
						ft_handler/ft_print_handler_n_bonus.c \
						ft_utils/ft_print_utils_cal_bonus.c \
						ft_utils/ft_print_utils_isfunc_bonus.c \
						ft_utils/ft_print_utils_lib_bonus.c \
						ft_utils/ft_print_utils_string_bonus.c \
						ft_utils/ft_print_utils_xtox_bonus.c



NAME=libftprintf.a

OBJS=$(SRCS:.c=.o)
BNS_OBJS=$(BNS_SRCS:.c=.o)

.PHONY: all
all	:	$(NAME)

%.o  : %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	ar -cr $(NAME) $(OBJS)

.PHONY: bonus
bonus : $(BNS_OBJS)
	ar -cr $(NAME) $(BNS_OBJS)

.PHONY: clean
clean :
	rm -rf $(OBJS) $(BNS_OBJS)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re   : fclean all
