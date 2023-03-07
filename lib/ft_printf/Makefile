# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 19:28:14 by yiwong            #+#    #+#              #
#    Updated: 2023/01/27 19:28:14 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

DEPS = ft_print.h

LIBFT = ../libft/libft.a

LIBFTDIR = ../libft/

SRC = $(wildcard *.c $(LIBFTDIR)/*.c)

OBJ = ${SRC:.c=.o}

NAME = ft_printf.a

all : $(NAME)

$(NAME) : $(OBJ)
		$(AR) $(LIBFT) $(OBJ)
		$(MAKE) -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean :
		rm -f $(OBJ)
		${MAKE} clean -C $(LIBFTDIR)

fclean : clean
		rm -f $(NAME)
		${MAKE} fclean -C $(LIBFTDIR)

re : fclean all

.PHONY : all clean fclean re