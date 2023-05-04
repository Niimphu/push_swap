# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 01:55:51 by yiwong            #+#    #+#              #
#    Updated: 2023/05/05 01:55:59 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

SRC = src/error.c \
	src/ft_lstremastered.c \
	src/push_swap.c \
	src/ready.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBS = -Llib/libft -lft -Llib/ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/libft
	@make -C lib/ft_printf
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C lib/libft
	@make clean -C lib/ft_printf
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/libft
	@make fclean -C lib/ft_printf
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
