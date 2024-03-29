/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/21 18:01:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*swap(t_data *set, char stack_id)
{
	if (stack_id == A || stack_id == S)
		set->stack_a = swapper(set->stack_a);
	if (stack_id == B || stack_id == S)
		set->stack_b = swapper(set->stack_b);
	ft_printf("s%c\n", stack_id);
	return (set);
}

t_stack	*swapper(t_stack *stack)
{
	t_stack	*to_first;

	to_first = stack->next;
	stack->next = to_first->next;
	to_first->next = stack;
	stack = to_first;
	return (stack);
}

t_data	*push(t_data *set, char stack_id)
{
	t_stack	*temp;

	if (stack_id == B)
	{
		temp = (set->stack_a)-> next;
		set->stack_b = \
			pusher(set->stack_a, set->stack_b);
		set->stack_a = temp;
	}
	else if (stack_id == A)
	{
		temp = (set->stack_b)-> next;
		set->stack_a = \
			pusher(set->stack_b, set->stack_a);
		set->stack_b = temp;
	}
	ft_printf("p%c\n", stack_id);
	return (set);
}

t_stack	*pusher(t_stack *stack_1, t_stack *stack_2)
{
	t_stack	*pushed;

	pushed = stack_1;
	if (!stack_2)
	{
		pushed->next = NULL;
		stack_2 = pushed;
	}
	else
	{
		pushed->next = stack_2;
		stack_2 = pushed;
	}
	return (stack_2);
}
