# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 16:03:29 by yiwong            #+#    #+#              #
#    Updated: 2023/03/07 17:37:57 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

DEPS = push_swap.h ft_printf.h

LIBFT = /lib/libft/libft.a

LIBFTDIR = /lib/libft/

PRINTF = /lib/ft_printf.a



SRC =

OBJ = $(SRC:.c=.o)

BONUS_SRC = 

BONUS_OBJ = 

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
		$(CC) $(CFLAGS) -c $(SRC)
		$(AR) $(NAME) $(OBJ)

bonus : $(OBJ) $(BONUS_OBJ)
		$(CC) $(CFLAGS) -c $(SRC) $(BONUS_SRC)
		$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

clean :
		 rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
		 rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
