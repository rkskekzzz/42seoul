NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE =	-I./include
SRC		=	main.c \
			core/push_swap.c core/sort.c core/under3.c \
			utils/func.c utils/lib.c utils/list.c utils/split.c

SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR),$(SRC))

# OBJ = $(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $(SRCS) -o $(NAME)



bonus	: all

clean	:
			@rm -f $(OBJ)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean	all

.PHONY	:	all clean fclean re bonus
