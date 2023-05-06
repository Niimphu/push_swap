# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 01:55:51 by yiwong            #+#    #+#              #
#    Updated: 2023/05/06 14:27:12 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/push_swap.c \
	src/ready.c \
	src/ft_lstremastered.c \
	src/error.c \
	src/utils.c

OBJ = $(SRC:.c=.o)

LIBS = -Llib/libft -lft -Llib/ft_printf -lftprintf

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/libft
	@make -C lib/ft_printf
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make fclean -C lib/libft
	@make fclean -C lib/ft_printf
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
