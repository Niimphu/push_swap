/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:43:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/19 06:06:44 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*push_bulk(t_data *set, int count)
{
	const int	third_i = count / 3;
	const int	two_thirds_i = third_i * 2;

	while (count > two_thirds_i && count > 3)
	{
		set = push_third(set, two_thirds_i);
		count--;
	}
	while (count > third_i && count > 3)
	{
		set = push_third(set, third_i);
		count--;
	}
	while (count > 3)
	{
		set = push(set, B);
		count--;
	}
	return (set);
}

t_data	*push_third(t_data *set, const int target_i)
{	
	while ((set -> stack_a)-> index <= target_i)
		set = rotate(set, A);
	set = push(set, B);
	return (set);
}
