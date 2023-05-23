/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_cmds_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/23 02:50:42 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap_bonus.h"

t_data	*bonus_swap(t_data *set, char stack_id)
{
	if (stack_id == A || stack_id == S)
		set->stack_a = bonus_swapper(set->stack_a);
	if (stack_id == B || stack_id == S)
		set->stack_b = bonus_swapper(set->stack_b);
	return (set);
}

t_stack	*bonus_swapper(t_stack *stack)
{
	t_stack	*to_first;

	to_first = stack->next;
	stack->next = to_first->next;
	to_first->next = stack;
	stack = to_first;
	return (stack);
}

t_data	*bonus_push(t_data *set, char stack_id)
{
	t_stack	*temp;

	if (stack_id == B)
	{
		temp = (set->stack_a)-> next;
		set->stack_b = \
			bonus_pusher(set->stack_a, set->stack_b);
		set->stack_a = temp;
	}
	else if (stack_id == A)
	{
		temp = (set->stack_b)-> next;
		set->stack_a = \
			bonus_pusher(set->stack_b, set->stack_a);
		set->stack_b = temp;
	}
	return (set);
}

t_stack	*bonus_pusher(t_stack *stack_1, t_stack *stack_2)
{
	t_stack	*pushed;

	pushed = stack_1;
	if (!stack_2)
	{
		pushed->next = NULL;
		stack_2 =pushed;
	}
	else
	{
		pushed->next = stack_2;
		stack_2 =pushed;
	}
	return (stack_2);
}
