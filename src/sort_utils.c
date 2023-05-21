/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:43:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/21 18:49:24 by yiwong           ###   ########.fr       */
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
	while ((set->stack_a)-> i <= target_i)
		set = rotate(set, A);
	set = push(set, B);
	return (set);
}
