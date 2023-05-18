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
	
	// print_set(set);
	if (is_sorted(set -> stack_a))
		return (0);
	count = list_size(set -> stack_a);
	if (count == 2)
		(set = swap(set, A));
	else if (count == 3)
		set = sort_three(set);
	else
		set = sort_list(set, count);
	// print_set(set);
	int_list_clear(set -> stack_a);
	free(set);
	return (0);
}

t_data	*sort_three(t_data *set)
{
	t_int_list	*stack;

	stack = set -> stack_a;
	if (stack -> number > (stack -> next)-> index &&
		stack -> number > ((stack -> next)-> next)-> index)
		set = rotate(set, A);
	else if (stack -> number < (stack -> next)-> index &&
		(stack -> next)-> number > ((stack -> next)-> next)-> index)
		set = reverse_rotate(set, A);
	if (!is_sorted(set -> stack_a))
		set = swap(set, A);
	return (set);
}

t_data	*sort_list(t_data *set, int count)
{
	push_halves(set, count);
	set = sort_three(set);
	return (set);
}
