NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
INCLUDE =	-I./include
SRC		=	main.c \
			core/push_swap.c core/sort.c core/under5.c \
			utils/library.c utils/utils.c utils/split.c \
			list/list1.c list/list2.c \
			func/func1.c func/func2.c func/func3.c \


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
