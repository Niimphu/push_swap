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
	
	print_set(set);
	if (is_sorted(set -> stack_a))
		return (0);
	count = list_size(set -> stack_a);
	if (count == 2)
		(set = swap(set, A));
	else if (count == 3)
		set = sort_three(set);
	else
		set = sort_list(set, count);
	print_set(set);
	stack_clear(set -> stack_a);
	free(set);
	return (0);
}

t_data	*sort_three(t_data *set)
{
	t_stack	*stack;

	stack = set -> stack_a;
	if (stack -> index > (stack -> next)-> index &&
		stack -> index > ((stack -> next)-> next)-> index)
		set = rotate(set, A);
	else if (stack -> index < (stack -> next)-> index &&
		(stack -> next)-> index > ((stack -> next)-> next)-> index)
		set = reverse_rotate(set, A);
	if (!is_ordered(set -> stack_a))
		set = swap(set, A);
	return (set);
}

//TODO:
t_data	*sort_list(t_data *set, int count)
{
	push_in_chunks(set, count);
	set = sort_three(set);
	set -> stack_a = find_distances(set -> stack_a);
	set -> stack_b = find_distances(set -> stack_b);
	// while(set -> stack_b)
	// 	set = pull_cheapest(set);
	return (set);
}

t_data	*pull_cheapest(t_data *set)
{
	set -> stack_b = find_distances(set -> stack_b);
	
	return (set);
}