# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 16:04:15 by opavliuk          #+#    #+#              #
#    Updated: 2019/02/05 19:07:05 by opavliuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_OFF=\033[0m#			# Text Reset
BLACK	=\033[0;30m#		# Black
RED		=\033[0;31m#		# Red
GREEN	=\033[0;32m#		# Green
YELLOW	=\033[0;33m#		# Yellow
BLUE	=\033[0;34m#		# Blue
PURPLE	=\033[0;35m#		# Purple
CYAN	=\033[0;36m#		# Cyan
WHITE	=\033[0;37m#		# White

CC=gcc 
CFLAGS=-Wall -Werror -Wextra
SRC=./src/argvs.c \
	./src/dispatcher_cmd.c \
	./src/loop_ssl.c \
	./src/formula_sha256.c \
	./src/check_flags.c \
	./src/main.c \
	./src/md5_algorithm.c \
	./src/read_stdin.c \
	./src/parsing.c \
	./src/swipe_size.c \
	./src/sha256_algorithm.c \
	./src/usages.c \
	./src/formula_md5.c \
	./src/output.c \
	./src/updates.c
OBJ=$(SRC:.c=.o)
NAME=ft_ssl
INCLUDE=include
INCLUDE_LIB=libft/include_lib/
LIB_DIR=libft
LIB=libft/libft.a
SRC_DIR=src
HEADER=include/ssl.h

all: lib $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) -I $(INCLUDE) -I $(INCLUDE_LIB)
	@ printf "|---------------------------------|\n ✅ | $(WHITE)[$(GREEN)done$(WHITE)]$(COLOR_OFF) - $(NAME)\n|---------------------------------|\n"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@ $(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDE)
	@ printf "$(WHITE)[$(GREEN)created$(WHITE)]$(COLOR_OFF) - $@\n"

lib:
	@ make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@rm -f $(OBJ) 
	@ printf "|---------------------------------|\n 🗑  | $(WHITE)[$(RED)remove$(WHITE)]$(COLOR_OFF) - objects of $(NAME)\n|---------------------------------|\n"

fclean: clean
	@rm -f $(LIB)
	@rm -f $(NAME)
	@ printf "|---------------------------------|\n 🗑  | $(WHITE)[$(RED)remove$(WHITE)]$(COLOR_OFF) - $(LIB)\n|---------------------------------|\n"
	@ printf "|---------------------------------|\n 🗑  | $(WHITE)[$(RED)remove$(WHITE)]$(COLOR_OFF) - $(NAME)\n|---------------------------------|\n"

re: fclean all

.PHONY: all, clean, fclean, re
