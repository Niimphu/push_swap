/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/18 19:47:29 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*swap(t_data *set, char stack_id)
{
	if (stack_id == A || stack_id == S)
		set -> stack_a = swapper(set -> stack_a);
	if (stack_id == B || stack_id == S)
		set -> stack_b = swapper(set -> stack_b);
	ft_printf("s%c\n", stack_id);
	return (set);
}

t_int_list	*swapper(t_int_list *stack)
{
	t_int_list	*to_first;

	to_first = stack -> next;
	stack -> next = to_first -> next;
	to_first -> next = stack;
	stack = to_first;
	return (stack);
}

t_data	*push(t_data *set, char stack_id)
{
	t_int_list	*temp;

	if (stack_id == B)
	{
		temp = (set -> stack_a)-> next;
		set -> stack_b = \
			pusher(set -> stack_a, set -> stack_b);
		set -> stack_a = temp;
	}
	else if (stack_id == A)
	{
		temp = (set -> stack_b)-> next;
		set -> stack_a = \
			pusher(set -> stack_b, set -> stack_a);
		set -> stack_b = temp;
	}
	ft_printf("p%c\n", stack_id);
	return (set);
}

t_int_list	*pusher(t_int_list *stack_1, t_int_list *stack_2)
{
	t_int_list	*pushed;

	pushed = stack_1;
	if (!stack_2)
	{
		pushed -> next = NULL;
		stack_2 = pushed;
	}
	else
	{
		pushed -> next = stack_2;
		stack_2 = pushed;
	}
	return (stack_2);
}
