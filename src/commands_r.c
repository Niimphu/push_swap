/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:02:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/17 17:22:34 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*rotate(t_data *stack_list, char stack_id)
{
	if (stack_id == A || stack_id == R)
		stack_list -> stack_a = rotater(stack_list -> stack_a);
	if (stack_id == B || stack_id == R)
		stack_list -> stack_b = rotater(stack_list -> stack_b);
	return (stack_list);
}

t_int_list	*rotater(t_int_list *stack)
{
	t_int_list	*to_first;
	t_int_list	*last;

	last = int_list_last(stack);
	to_first = stack -> next;
	stack -> next = NULL;
	last -> next = stack;
	return (to_first);
}

t_data	*reverse_rotate(t_data *stack_list, char stack_id)
{
	if (stack_id == A || stack_id == R)
		stack_list -> stack_a = reverse_rotater(stack_list -> stack_a);
	if (stack_id == B || stack_id == R)
		stack_list -> stack_b = reverse_rotater(stack_list -> stack_b);
	return (stack_list);
}

t_int_list	*reverse_rotater(t_int_list *stack)
{
	t_int_list	*to_first;

	to_first = (int_list_last(stack));
	to_first -> next = stack;
	while (stack -> next != to_first)
		stack = stack -> next;
	stack -> next = NULL;
	return (to_first);
}
