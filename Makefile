# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 16:03:29 by yiwong            #+#    #+#              #
#    Updated: 2023/05/05 00:24:12 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

DEPS = lib/push_swap.h

LIBFT = libft.a

LIBFTDIR = lib/libft/

PRINTF = ft_printf.a

PRINTFDIR = lib/ft_printf/

SRC = src/push_swap.c \
		src/ready.c \
		src/error.c \
		src/ft_lstremastered.c
		

OBJ = $(SRC:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(OBJ) -o $(NAME)

# $(OBJ)	:
# 		$(CC) $(CFLAGS) -c -o $(SRC) $(OBJ)

%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
		$(MAKE) -C $(LIBFTDIR)
		mv $(LIBFTDIR)$(LIBFT) .

$(PRINTF) :
		$(MAKE) -C $(PRINTFDIR)
		mv $(PRINTFDIR)$(PRINTF) .

clean :
		 rm -f $(OBJ) $(LIBFT) $(PRINTF)
		$(MAKE) clean -C $(LIBFTDIR)
		$(MAKE) clean -C $(PRINTFDIR)

fclean : clean
		 rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
