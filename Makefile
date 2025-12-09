# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 15:10:38 by aheitz            #+#    #+#              #
#    Updated: 2025/12/09 13:34:07 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = hotrace
MAKEFLAGS += --no-print-directory -s

INCLUDE = include

SRC = src/main.c   \
	src/store.c    \
	src/hash.c     \
	src/input.c    \
	src/research.c \
	src/db.c       \
	src/utils.c    \

# **************************************************************************** #

CC       = cc
CPPFLAGS = -I $(INCLUDE) -I .
CFLAGS   = -Wall -Wextra -Werror

OBJ_DIR  = obj
OBJ     := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# **************************************************************************** #

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)

re : fclean all

# **************************************************************************** #

.PHONY: all clean fclean re

# **************************************************************************** #