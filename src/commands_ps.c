/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/17 17:18:49 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*swap(t_data *stack_list, char stack_id)
{
	if (stack_id == A || stack_id == S)
		stack_list -> stack_a = swapper(stack_list -> stack_a);
	if (stack_id == B || stack_id == S)
		stack_list -> stack_b = swapper(stack_list -> stack_b);
	ft_printf("s%c\n", stack_id);
	return (stack_list);
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

t_data	*push(t_data *stack_list, char stack_id)
{
	t_int_list	*temp;

	if (stack_id == B)
	{
		temp = (stack_list -> stack_a)-> next;
		stack_list -> stack_b = \
			pusher(stack_list -> stack_a, stack_list -> stack_b);
		stack_list -> stack_a = temp;
	}
	else if (stack_id == A)
	{
		temp = (stack_list -> stack_b)-> next;
		stack_list -> stack_a = \
			pusher(stack_list -> stack_b, stack_list -> stack_a);
		stack_list -> stack_b = temp;
	}
	ft_printf("p%c\n", stack_id);
	return (stack_list);
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
