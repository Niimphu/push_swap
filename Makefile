# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 01:55:51 by yiwong            #+#    #+#              #
#    Updated: 2023/05/17 17:11:08 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
	src/push_swap.c \
	src/ready.c \
	src/ready_checks.c \
	src/ft_lstremastered.c \
	src/commands_ps.c \
	src/commands_r.c \
	src/error.c \
	src/utils.c

OBJ = $(SRC:.c=.o)

LIBS = -Llib/libft -lft -Llib/ft_printf -lftprintf -Llib/lib_me42 -lme42

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC lib/libft
	@make -sC lib/ft_printf
	@make -sC lib/lib_me42
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make fclean -sC lib/libft
	@make fclean -sC lib/ft_printf
	@make fclean -sC lib/lib_me42
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
