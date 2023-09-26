NAME = push

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -fsanitize=address -g3

SRC = push.c ./include/utils.c ./include/utils_2.c ./include/moves.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
