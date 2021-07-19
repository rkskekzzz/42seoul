NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE =	-I./includes
SRC		=	main.c debug.c\
			library/atoi.c

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
