# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 01:55:51 by yiwong            #+#    #+#              #
#    Updated: 2023/05/23 02:55:47 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = src/main.c \
	src/ready.c \
	src/ready_checks.c \
	src/push_swap.c \
	src/sort_utils.c \
	src/cost.c \
	src/push_back.c \
	src/ft_lstremastered.c \
	src/commands_ps.c \
	src/commands_r.c \
	src/utils.c \
	src/extras.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = src/ready.c \
			src/ready_checks.c \
			src/push_swap.c \
			src/sort_utils.c \
			src/ft_lstremastered.c \
			src/cost.c \
			src/push_back.c \
			src/commands_ps.c \
			src/commands_r.c \
			src/utils.c \
			src/extras.c \
			bonus/checker.c \
			bonus/checker_cmds_r.c \
			bonus/checker_cmds_ps.c \
			lib/get_next_line/get_next_line.c \
			lib/get_next_line/get_next_line_utils.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBS = -Llib/libft -lft -Llib/ft_printf -lftprintf -Llib/lib_me42 -lme42

NAME = push_swap

BONUS_NAME = checker

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
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_OBJ)
	@make -sC lib/libft
	@make -sC lib/ft_printf
	@make -sC lib/lib_me42
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBS) -o $(BONUS_NAME)

rebonus: fclean bonus

.PHONY: all clean fclean re bonus
