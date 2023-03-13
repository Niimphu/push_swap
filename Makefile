# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 16:03:29 by yiwong            #+#    #+#              #
#    Updated: 2023/03/13 19:21:58 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

DEPS = push_swap.h ft_printf.h

LIBFT = libft.a

LIBFTDIR = lib/libft/

PRINTF = ft_printf.a

PRINTFDIR = lib/ft_printf/

SRC = $(wildcard src/*.c)

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
		 rm -f $(OBJ)
		$(MAKE) clean -C $(LIBFTDIR)
		$(MAKE) clean -C $(PRINTFDIR)

fclean : clean
		 rm -f $(NAME) $(LIBFT) $(PRINTF)

re : fclean all

.PHONY : all clean fclean re bonus
