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

	current = set->stack_b;
	while (current)
	{
		stack_a = set->stack_a;
		target = find_target(stack_a, current->i);
		current = find_min_moves(target, current);
		current = current->next;
	}
	return (set);
}

//dir = direction. Would write it out in full but norm :/
t_stack	*find_min_moves(t_stack *targ, t_stack *current)
{
	int		dir;
	t_stack	*big;
	t_stack	*small;

	big = find_big_small(targ, current, UP);
	small = find_big_small(targ, current, DOWN);
	dir = find_min_direction(big);
	current->cost[0] = dir;
	current->cost[1] = big->dist[dir];
	if (big->dist[dir] > small->dist[dir])
		return (current);
	if (small->dist[dir] - big->dist[dir] < small->dist[abs(1 - dir)])
		current->cost[1] += small->dist[dir] - big->dist[dir];
	else
		current->cost[1] += small->dist[abs(1 - dir)];
	if (current->dist[UP] > 0 && targ->dist[UP] > 0 && \
		small->dist[dir] - big->dist[dir] > small->dist[abs(1 - dir)])
		current->cost[0] = BOTH;
	return (current);
}

t_stack	*find_big_small(t_stack *s1, t_stack *s2, int size)
{
	t_stack	*big;
	t_stack	*small;

	if (min(s1->dist[UP], s1->dist[DOWN]) > min(s2->dist[UP], s2->dist[DOWN]))
	{
		big = s1;
		small = s2;
	}
	else
	{
		big = s2;
		small = s1;
	}
	if (size == UP)
		return (big);
	else
		return (small);
}

int	find_min_direction(t_stack *stack)
{
	int	ret;

	if (stack->dist[UP] <= stack->dist[DOWN])
		ret = UP;
	else
		ret = DOWN;
	return (ret);
}
