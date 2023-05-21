/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:36:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/21 18:36:31 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_stack	*find_dists(t_stack *stack)
{
	t_stack	*temp;
	int		to_top;
	int		count;

	temp = stack;
	count = list_size(temp);
	to_top = 0;
	while (temp)
	{
		temp->dist[UP] = to_top;
		temp->dist[DOWN] = count - to_top;
		temp = temp->next;
		to_top++;		
	}
	return (stack);
}

t_data	*find_costs(t_data *set)
{
	t_stack	*current;
	t_stack	*target;
	t_stack	*stack_a;
	// int		min_moves[2];

	current = set->stack_b;
	stack_a = set->stack_a;
	while (current)
	{
		target = stack_a;
		while (target->i < current->i && stack_a->next)
		{
			if (stack_a->i > current->i && stack_a->i < target->i)
				target = stack_a;
			stack_a = stack_a->next;
		}
		current = find_min_moves(target, current);
		current = current->next;
	}
	return (set);
}

//TODO: better efficiency with end conditions
t_stack	*find_min_moves(t_stack *targ, t_stack *current)
{
	int		dir;
	t_stack	*big;
	t_stack *small;

	if (min(targ->dist[UP], targ->dist[DOWN]) >\
		min(current->dist[UP], current->dist[DOWN]))
	{
		big = targ;
		small = current;
	}
	else
	{
		big = current;
		small = targ;
	}
	dir = find_min_direction(big);
	current->cost[0] = dir;
	current->cost[1] = big->dist[dir];
	if (big->dist[dir] > small->dist[dir])
		return(current);
	if (small->dist[dir] - big->dist[dir] < small->dist[abs(1-dir)])
		current->cost[1] += small->dist[dir] - big->dist[dir];
	else
	{
		current->cost[0] = BOTH;
		current->cost[1] += small->dist[abs(1-dir)];
	}
	return(current);
}

int	find_min_direction(t_stack *stack)
{
	int	ret;

	if (stack->dist[UP] < stack->dist[DOWN])
		ret = UP;
	else
		ret = DOWN;
	return (ret);
}
