/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:56 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/18 20:01:46 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Violet Midnight

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
# define R 'r'

typedef struct s_int_list
{
	int					number;
	int					index;
	struct s_int_list	*next;
}						t_int_list;

typedef struct s_data
{
	t_int_list	*stack_a;
	t_int_list	*stack_b;
}				t_data;

typedef enum
{
	LOWER,
	UPPER
}	e_status;

t_data		*init_stacks_struct(void);
t_int_list	*init_stack_a(int argc, char *argv[]);
int			validate(char *input[]);
t_int_list	*create_list(char **input);
void		index_stack(t_int_list *stack);

int			is_too_large(char *str);
int			ft_isnum(char *str);
int			is_stack_indexed(t_int_list *stack);
t_int_list	*lowest_unindexed_node(t_int_list *stack);
int			is_not_duplicate(char *argv[], int n);

t_int_list	*int_list_new(char *number_string);
t_int_list	*int_list_last(t_int_list *lst);
void		int_list_append(t_int_list *lst, t_int_list *new);
void		int_list_delete(t_int_list *lst);
void		int_list_clear(t_int_list *stack);

int			push_swap(t_data *set);
t_data		*sort_three(t_data *set);
t_data		*sort_list(t_data *set, int count);

t_data		*push_halves(t_data *set, int count);
e_status	push_bulk(t_data *set, const int half_i, e_status status);

t_data		*swap(t_data *set, char stack_id);
t_int_list	*swapper(t_int_list *stack);
t_data		*push(t_data *set, char stack_id);
t_int_list	*pusher(t_int_list *stack_1, t_int_list *stack_2);

t_data		*rotate(t_data *set, char stack_id);
t_int_list	*rotater(t_int_list *stack);
t_data		*reverse_rotate(t_data *set, char stack_id);
t_int_list	*reverse_rotater(t_int_list *stack);

long long	ft_atoll(const char *nptr);
int			is_sorted(t_int_list *stack);
int			list_size(t_int_list *stack);

void		print_set(t_data *set);
void		print_stack(t_int_list *stack);

#endif