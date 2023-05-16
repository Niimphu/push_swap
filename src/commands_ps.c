/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/17 00:13:05 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int_list	*push_extended(int_list *stack_1, int_list *stack_2);

data	*swap(data *stack_list, char stack)
{
	int_list	*to_first;
	int_list	*current;

	if (stack != X)
		ft_printf("s%c\n", stack);
	if (stack == B || stack == S)
		swap(stack_list, B_SWAP);
	if (stack == A || stack == S)
		current = stack_list -> stack_a;
	else if (stack == B_SWAP)
		current = stack_list -> stack_b;
	else
		return (stack_list);
	to_first = current -> next;
	if (to_first -> next)
		current -> next = to_first -> next;
	else
		current -> next = NULL;
	to_first -> next = current;
	if (stack == A || stack == S)
		stack_list -> stack_a = to_first;
	else
		stack_list -> stack_b = to_first;
	return (stack_list);
}

data	*push(data *stack_list, char stack)
{
	int_list	*temp;

	if (stack == B)
	{
		temp = (stack_list -> stack_a)-> next;
		stack_list -> stack_b = \
			push_extended(stack_list -> stack_a, stack_list -> stack_b);
		stack_list -> stack_a = temp;
	}
	else if (stack == A)
	{
		temp = (stack_list -> stack_b)-> next;
		stack_list -> stack_a = \
			push_extended(stack_list -> stack_b, stack_list -> stack_a);
		stack_list -> stack_b = temp;
	}
	ft_printf("p%c\n", stack);
	return (stack_list);
}

int_list	*push_extended(int_list *stack_1, int_list *stack_2)
{
	int_list	*pushed;

	pushed = stack_1;
	stack_1 = pushed -> next;
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
// TODO:
// data	*rotate(data *stack_list, char stack)
// {
// 	if ()
// }