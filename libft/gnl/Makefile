SRC = get_next_line_utils.c get_next_line.c

CFLAGS = -Werror -Wall -Wextra

OBJ = $(SRC:.c=.o)

NAME = gnl.a

$(NAME) : $(OBJ)
	ar -rsc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re