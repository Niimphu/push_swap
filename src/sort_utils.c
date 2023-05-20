/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:43:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/20 18:44:06 by yiwong           ###   ########.fr       */
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
	int		distance_up;
	int		count;

	temp = stack;
	count = list_size(temp);
	distance_up = 0;
	while (temp)
	{
		temp -> distance_up = distance_up;
		temp -> distance_down = count - distance_up;
		temp = temp -> next;
		distance_up++;		
	}
	return (stack);
}
