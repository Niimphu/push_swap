/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:42:43 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/06 14:42:43 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	push_swap(t_data *set)
{
	int	count;

	if (is_sorted(set->stack_a))
		return (0);
	count = list_size(set->stack_a);
	if (count == 2)
		(set = swap(set, A));
	else if (count == 3)
		set = sort_three(set);
	else
		set = sort_list(set, count);
	stack_clear(set->stack_a);
	free(set);
	return (0);
}

t_data	*sort_three(t_data *set)
{
	t_stack	*stack;

	stack = set->stack_a;
	if (stack->i > (stack->next)-> i && \
		stack->i > ((stack->next)-> next)-> i)
		set = rotate(set, A);
	else if (stack->i < (stack->next)-> i && \
		(stack->next)-> i > ((stack->next)-> next)-> i)
		set = reverse_rotate(set, A);
	if (!is_ordered(set->stack_a))
		set = swap(set, A);
	return (set);
}

t_data	*sort_list(t_data *set, int count)
{
	t_stack	*first;

	push_in_chunks(set, count);
	set = sort_three(set);
	while (set->stack_b)
		set = push_back_cheapest(set);
	first = find_smallest(set->stack_a);
	set->stack_a = find_dists(set->stack_a);
	while (set->stack_a != first)
	{
		if (first->dist[UP] < first->dist[DOWN])
			set = rotate(set, A);
		else
			set = reverse_rotate(set, A);
	}
	return (set);
}

//TODO:
t_data	*push_back_cheapest(t_data *set)
{
	t_stack	*cheapest;

	set->stack_a = find_dists(set->stack_a);
	set->stack_b = find_dists(set->stack_b);
	set = find_costs(set);
	cheapest = find_cheapest(set->stack_b);
	set = push_back(set, cheapest);
	return (set);
}
