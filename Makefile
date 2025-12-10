# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 15:10:38 by aheitz            #+#    #+#              #
#    Updated: 2025/12/10 02:56:59 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = hotrace
MAKEFLAGS += --no-print-directory -s

SRC = main.c   \
	db.c       \
	hash.c     \
	input.c    \
	research.c \
	store.c    \
	utils.c    \

# **************************************************************************** #

CC       = cc
CFLAGS   = -Wall -Wextra -Werror -O3 -march=native -funroll-loops

OBJ_DIR  = obj
OBJ     := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# **************************************************************************** #

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

# **************************************************************************** #

.PHONY: all clean fclean re

# **************************************************************************** #