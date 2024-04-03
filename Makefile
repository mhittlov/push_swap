# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 16:00:50 by mhittlov          #+#    #+#              #
#    Updated: 2024/02/05 18:32:22 by mhittlov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./push.c \
      ./push_swap.c \
      ./rotate.c \
      ./swap.c \
      ./sorts.c \
      ./free.c \
      ./ft_calloc.c \
      ./ft_putstr_fd.c \
      ./ft_split.c \
      ./ft_substr.c \
      ./reverse_rotate.c \
      ./min.c \
      ./main.c \

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

$(NAME): $(OBJ)
	@echo "Linking objects to create executable..."
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Executable $(NAME) created!"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@echo "Cleaning objects..."
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Fully cleaning..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re