# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 13:20:28 by guortun-          #+#    #+#              #
#    Updated: 2023/11/27 08:24:56 by guortun-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colores
RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m

# Objetivos
OBJ_COLOR = $(BLUE)
CLEAN_COLOR = $(YELLOW)
FCLEAN_COLOR = $(RED)
RE_COLOR = $(GREEN)

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRC = push.c ./include/utils.c ./include/utils_2.c ./include/utils_3.c ./include/utils_4.c ./include/utils_5.c ./include/utils_6.c ./include/utils_7.c ./include/utils_8.c ./include/utils_9.c ./include/moves.c

OBJ = $(SRC:.c=.o)

MAKEFLAGS += --silent
# Reglas

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(OBJ_COLOR)Compilando $(NAME) ...$(RESET)"
	@if [ -z "$(OBJ)" ]; then \
		echo "$(RED)No hay nada que hacer$(RESET)"; \
	else \
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) || (echo "$(RED)Error de compilación$(RESET)" && exit 1); \
		echo "$(GREEN)¡Compilación exitosa!$(RESET)"; \
	fi

clean:
	@echo "$(CLEAN_COLOR)Limpiando archivos objeto...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(FCLEAN_COLOR)Limpiando $(NAME) ...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re