/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:43:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/22 01:19:06 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*push_in_chunks(t_data *set, int count)
{
	const int	start = count;
	int			chunks;
	int			numerator;

	if (start < 50)
		chunks = 3;
	else if (start < 101)
		chunks = 4;
	else
		chunks = 5;
	numerator = start * chunks;
	while (numerator >= start)
	{
		while (count > numerator / chunks && count > 3)
		{
			set = push_next_in_chunk(set, numerator / chunks);
			count--;
		}
		numerator -= start;
	}
	while (count > 3)
	{
		set = push(set, B);
		count--;
	}
	return (set);
}

t_data	*push_next_in_chunk(t_data *set, const int limit_i)
{	
	while ((set->stack_a)->i <= limit_i)
		set = rotate(set, A);
	set = push(set, B);
	return (set);
}

t_stack	*find_target(t_stack *stack_a, int current_i)
{
	t_stack	*target;
	t_stack	*temp;

	temp = stack_a;
	while (temp->next && temp->i < current_i)
			temp = temp->next;
	if (temp->i > current_i)
		target = temp;
	else
		return (find_smallest(stack_a));
	while (temp)
	{
		if (temp->i > current_i && temp->i < target->i)
			target = temp;
		temp = temp->next;
	}
	return (target);
}

t_stack	*find_smallest(t_stack *stack_a)
{
	t_stack	*smallest;

	smallest = stack_a;
	while (stack_a)
	{
		if (smallest->i > stack_a->i)
			smallest = stack_a;
		stack_a = stack_a->next;
	}
	return (smallest);
}
