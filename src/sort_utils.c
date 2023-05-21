/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:43:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/21 05:19:35 by yiwong           ###   ########.fr       */
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
	else
		chunks = 10;
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

t_data	*push_next_in_chunk(t_data *set, const int target_i)
{	
	while ((set -> stack_a)-> index <= target_i)
		set = rotate(set, A);
	set = push(set, B);
	return (set);
}

t_stack	*find_distances(t_stack *stack)
{
	t_stack	*temp;
	int		to_top;
	int		count;

	temp = stack;
	count = list_size(temp);
	to_top = 0;
	while (temp)
	{
		temp -> distance[UP] = to_top;
		temp -> distance[DOWN] = count - to_top;
		temp = temp -> next;
		to_top++;		
	}
	return (stack);
}

t_data	*find_costs(t_data *set)
{
	t_stack	*current;
	t_stack	*target;
	// int		min_moves[2];

	current = set -> stack_b;
	while (current)
	{
		target = set -> stack_a;
		while (target -> index < current -> index && target -> next)
			target = target -> next;
		current = find_min_moves(target, current);
		current = current -> next;
		// min_moves[1] = max(min(target -> distance[UP], target -> distance[DOWN]),
		// 	min(stack_b -> distance[UP], stack_b -> distance[DOWN]));
		// if (min_moves[1] == stack_b -> distance[UP])
		// 	min_moves[0] = UP;
		// else
		// 	min_moves[0] = DOWN;
		// if (min_moves[1] == stack_b -> distance[DOWN])
		// 	min_moves[0] = BOTH;
		
	}
	return (set);
}

//TODO: better efficiency with end conditions
t_stack	*find_min_moves(t_stack *target, t_stack *current)
{
	int		min_moves[2];
	t_stack	*more;
	t_stack *fewer;

	if (min(target -> distance[UP], target -> distance[DOWN]) >\
		min(current -> distance[UP], current -> distance[DOWN]))
	{
		more = target;
		fewer = current;
	}
	else
	{
		more = current;
		fewer = target;
	}
	min_moves[0] = find_min_direction(min_moves, more);
	current -> cost[0] = min_moves[0];
	if (min_moves[1] >= fewer -> distance[min_moves[0]])
		current -> cost[1] = min_moves[1];
	else
		current -> cost[1] = min_moves[1] + target -> distance[min_moves[0]];
	if (current -> cost[1] < 0)
		current -> cost[1] *= -1;
	return(current);
}

int	find_min_direction(int min_moves[], t_stack *stack)
{
	int	ret;

	if (min_moves[1] == stack -> distance[DOWN] && min_moves[1] == stack -> distance[UP])
		ret = BOTH;
	else if (min_moves[1] == stack -> distance[UP])
		ret = UP;
	else if (min_moves[1] == stack -> distance[UP])
		ret = DOWN;
	return (ret);
}
