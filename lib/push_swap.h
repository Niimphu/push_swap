/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:56 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/15 15:43:38 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "lib_me42/lib_me42.h"
# include <stdlib.h>

typedef struct	int_lst
{
	int				number;
	unsigned long	index;
	struct int_lst	*next;
}					int_list;

typedef struct	data_struct
{
	int_list	*stack_a;
	int_list	*stack_b;
}				data;

data		*init_stacks_struct(void);

int_list	*init_stack_a(int argc, char *argv[]);
int_list	*create_list(char **input);
void		index_stack(int_list *stack);
int			is_stack_indexed(int_list *stack);
int_list	*lowest_unindexed_node(int_list *stack);

int			validate(char *argv[]);
int			ft_isnum(char *str);
int			is_not_duplicate(char *argv[], int n);

int_list	*int_list_new(char *number_string);
int_list	*int_list_last(int_list *lst);
void		int_list_append(int_list *lst, int_list *new);

int			push_swap(data *stacks);

void		print_stacks(data *stacks);
void		print_stack(int_list *stack);

#endif