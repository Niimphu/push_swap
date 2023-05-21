/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:02:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/21 18:01:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*rotate(t_data *set, char stack_id)
{
	if (stack_id == A || stack_id == R)
		set->stack_a = rotater(set->stack_a);
	if (stack_id == B || stack_id == R)
		set->stack_b = rotater(set->stack_b);
	ft_printf("r%c\n", stack_id);
	return (set);
}

t_stack	*rotater(t_stack *stack)
{
	t_stack	*to_first;
	t_stack	*last;

	last = stack_last(stack);
	to_first = stack->next;
	stack->next = NULL;
	last->next = stack;
	return (to_first);
}

t_data	*reverse_rotate(t_data *set, char stack_id)
{
	if (stack_id == A || stack_id == R)
		set->stack_a = reverse_rotater(set->stack_a);
	if (stack_id == B || stack_id == R)
		set->stack_b = reverse_rotater(set->stack_b);
	ft_printf("rr%c\n", stack_id);
	return (set);
}

t_stack	*reverse_rotater(t_stack *stack)
{
	t_stack	*to_first;

	to_first = (stack_last(stack));
	to_first->next = stack;
	while (stack->next != to_first)
		stack = stack->next;
	stack->next = NULL;
	return (to_first);
}
