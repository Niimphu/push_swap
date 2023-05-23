/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_cmds_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:02:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/23 02:51:45 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap_bonus.h"

t_data	*bonus_rotate(t_data *set, char stack_id)
{
	if (stack_id == A || stack_id == R)
		set->stack_a = bonus_rotater(set->stack_a);
	if (stack_id == B || stack_id == R)
		set->stack_b = bonus_rotater(set->stack_b);
	return (set);
}

t_stack	*bonus_rotater(t_stack *stack)
{
	t_stack	*to_first;
	t_stack	*last;

	last = stack_last(stack);
	to_first = stack->next;
	stack->next = NULL;
	last->next = stack;
	return (to_first);
}

t_data	*bonus_reverse_rotate(t_data *set, char stack_id)
{
	if (stack_id == A || stack_id == R)
		set->stack_a = bonus_reverse_rotater(set->stack_a);
	if (stack_id == B || stack_id == R)
		set->stack_b = bonus_reverse_rotater(set->stack_b);
	return (set);
}

t_stack	*bonus_reverse_rotater(t_stack *stack)
{
	t_stack	*to_first;

	to_first = (stack_last(stack));
	to_first->next = stack;
	while (stack->next != to_first)
		stack = stack->next;
	stack->next = NULL;
	return (to_first);
}
