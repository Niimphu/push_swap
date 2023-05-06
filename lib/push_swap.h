/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:56 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/06 14:29:09 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct intlst
{
	int				number;
	struct intlst	*next;
}					int_list;

int	init(int argc, char *argv[]);
int	create_list(int argc, char *argv[]);
int	validate(char *argv[]);
int	ft_isnum(char *str);
int	is_not_duplicate(char *argv[], int n);

int_list	*int_list_new(char *number_string);
int_list	*int_list_last(int_list *lst);
void		int_list_append(int_list *lst, int_list *new);

void	print_stack(int_list	*stack);

#endif