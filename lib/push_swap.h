/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:56 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/20 20:06:01 by yiwong           ###   ########.fr       */
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
	int					distance_up;
	int					distance_down;
	int					cost[2];
	struct s_int_list	*next;
}						t_stack;

typedef struct s_data
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_data;

t_data		*init_stacks_struct(void);
t_stack		*init_stack_a(int argc, char *argv[]);
int			validate(char *input[]);
t_stack		*create_list(char **input);
void		index_stack(t_stack *stack);

int			is_too_large(char *str);
int			ft_isnum(char *str);
int			is_stack_indexed(t_stack *stack);
t_stack		*lowest_unindexed_node(t_stack *stack);
int			is_not_duplicate(char *argv[], int n);

t_stack		*new_stack_node(char *number_string);
t_stack		*stack_last(t_stack *lst);
void		stack_append(t_stack *lst, t_stack *new);
void		stack_node_delete(t_stack *lst);
void		stack_clear(t_stack *stack);

int			push_swap(t_data *set);
t_data		*sort_three(t_data *set);
t_data		*sort_list(t_data *set, int count);
t_data		*pull_cheapest(t_data *set);

t_data		*push_in_chunks(t_data *set, int count);
t_data		*push_next_in_chunk(t_data *set, const int target_i);
t_stack		*find_distances(t_stack *stack);

t_data		*swap(t_data *set, char stack_id);
t_stack		*swapper(t_stack *stack);
t_data		*push(t_data *set, char stack_id);
t_stack		*pusher(t_stack *stack_1, t_stack *stack_2);

t_data		*rotate(t_data *set, char stack_id);
t_stack		*rotater(t_stack *stack);
t_data		*reverse_rotate(t_data *set, char stack_id);
t_stack		*reverse_rotater(t_stack *stack);

long long	ft_atoll(const char *nptr);
int			is_sorted(t_stack *stack);
int			is_ordered(t_stack *stack);
int			list_size(t_stack *stack);

void		print_set(t_data *set);
void		print_stack(t_stack *stack);

#endif