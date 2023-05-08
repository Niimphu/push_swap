# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 12:24:43 by yiwong            #+#    #+#              #
#    Updated: 2023/05/08 13:03:28 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

SRC = free_pointers.c

OBJ = ${SRC:.c=.o}

NAME = libme42.a

all : $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(CFLAGS) -c $(SRC)
		@$(AR) $(NAME) $(OBJ)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@
clean :
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
