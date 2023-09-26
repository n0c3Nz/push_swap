CC = gcc
CFLAGS = -fsanitize=address -g3
INCLUDE_DIR = ./include
SRC_FILES = push.c $(INCLUDE_DIR)/utils.c $(INCLUDE_DIR)/utils_2.c $(INCLUDE_DIR)/moves.c
EXECUTABLE = push

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

fclean: clean

re: fclean all
