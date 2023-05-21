/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:39:17 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/21 18:39:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*ret;

	ret = stack;
	while (stack)
	{
		if (stack->cost[1] < ret->cost[1])
			ret = stack;
		stack = stack->next;
	}
	return (ret);
}

t_data	*push_back(t_data *set, t_stack *cheapest)
{
	t_stack	*target;

	target = find_target(set->stack_a, cheapest->i);
	if (cheapest->cost[0] == UP)
		set = rotate_to(set, cheapest, target);
	else if (cheapest->cost[0] == DOWN)
		set = rev_rotate_to(set, cheapest, target);
	else if (cheapest->cost[0] == BOTH)
		set = rotate_split(set, cheapest, target);
	set = push(set, A);
	return (set);
}

t_data	*rotate_to(t_data *set, t_stack *cheap, t_stack *target)
{
	while (set->stack_a != target && set->stack_b != cheap)
		set = rotate(set, R);
	while (set->stack_a != target)
		set = rotate(set, A);
	while (set->stack_b != cheap)
		set = rotate(set, B);
	return (set);
}

t_data	*rev_rotate_to(t_data *set, t_stack *cheap, t_stack *target)
{
	while (set->stack_a != target && set->stack_b != cheap)
		set = reverse_rotate(set, R);
	while (set->stack_a != target)
		set = reverse_rotate(set, A);
	while (set->stack_b != cheap)
		set = reverse_rotate(set, B);
	return (set);
}

t_data	*rotate_split(t_data *set, t_stack *cheap, t_stack *target)
{
	while (set->stack_a != target)
	{
		if (target->dist[UP] < target->dist[DOWN])
			set = rotate(set, A);
		else
			set = reverse_rotate(set, A);
	}
	while (set->stack_b != cheap)
	{
		if (cheap->dist[UP] < cheap->dist[DOWN])
			set = rotate(set, B);
		else
			set = reverse_rotate(set, B);
	}
	return (set);
}
