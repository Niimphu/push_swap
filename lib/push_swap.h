/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:56 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/16 23:47:09 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "lib_me42/lib_me42.h"
# include <stdlib.h>
# include <limits.h>

# define A 'a'
# define B 'b'
# define S 's'
# define B_SWAP 'x'

typedef struct int_lst
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
int			validate(char *input[]);
int_list	*create_list(char **input);
void		index_stack(int_list *stack);

int			is_too_large(char *str);
int			ft_isnum(char *str);
int			is_stack_indexed(int_list *stack);
int_list	*lowest_unindexed_node(int_list *stack);
int			is_not_duplicate(char *argv[], int n);

int_list	*int_list_new(char *number_string);
int_list	*int_list_last(int_list *lst);
void		int_list_append(int_list *lst, int_list *new);
void		int_list_delete(int_list *lst);
void		int_list_clear(int_list *stack);

int			push_swap(data *stack_list);

data		*swap(data *stack_list, char stack);
data		*push(data *stack_list, char stack);

long long	ft_atoll(const char *nptr);
void		print_stack_list(data *stack_list);
void		print_stack(int_list *stack);

#endif