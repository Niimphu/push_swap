# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 16:03:29 by yiwong            #+#    #+#              #
#    Updated: 2023/03/08 18:19:15 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

DEPS = push_swap.h ft_printf.h

LIBFT = /lib/libft/libft.a

LIBFTDIR = /lib/libft/

PRINTF = /lib/ft_printf/ft_printf.a

PRINTFDIR = /lib/ft_printf/

SRC = /src/*.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS)  $(PRINTF) $(LIBFT) $(OBJ) -o $(NAME)
		$(AR) $(NAME) $(OBJ)

$(OBJ)	:
		$(CC) $(CFLAGS) $(OBJ) -c $(SRC)

$(LIBFT) :
		$(MAKE) -C $(LIBFTDIR)

$(PRINTF) :
		$(MAKE) -C $(PRINTFDIR)

clean :
		 rm -f $(OBJ)

fclean : clean
		 rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
