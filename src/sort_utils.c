/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:43:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/18 20:16:51 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*push_halves(t_data *set, int count)
{
	const int	half_index = count / 2;
	e_status	status;

	set = push(set, B);
	if (count-- == 3)
		return (set);
	else
		set = push(set, B);
	count--;
	if ((set -> stack_b)-> number < \
		((set -> stack_b)-> next)-> number)
		status = LOWER;
	else
		status = UPPER;
	while (count > 3)
	{
		status = push_bulk(set, half_index, status);
		count--;
	}
	return (set);
}

e_status	push_bulk(t_data *set, const int half_i, e_status status)
{
	t_int_list		*stack_a;
	t_int_list		*stack_b;

	stack_a = set -> stack_a;
	stack_b = set -> stack_b;
	if (stack_a -> number < half_i && status == LOWER)
	{
		status = UPPER;
		set = reverse_rotate(set, B);
	}
	else if (stack_a -> number > half_i && status == UPPER)
	{
		status = LOWER;
		set = rotate(set, B);
	}
	set = push(set, B);
	return (status);
}
