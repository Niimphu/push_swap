/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/16 18:07:16 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int_list	*swap_extended(int_list *stack);
int_list	*push_extended(int_list *stack_1, int_list *stack_2);

data	*swap(data *stack_list, char stack)
{
	if (stack == A || stack == S)
		stack_list -> stack_a = swap_extended(stack_list -> stack_a);
	if (stack == B || stack == S)
		stack_list -> stack_b = swap_extended(stack_list -> stack_b);
	ft_printf("s%c\n", stack);
	return (stack_list);
}

int_list	*swap_extended(int_list *stack)
{	
	int_list	*to_first;
	int_list	*current;

	current = stack;
	to_first = current -> next;
	if (to_first -> next)
		current -> next = to_first -> next;
	else
		current -> next = NULL;
	to_first -> next = current;
	return (to_first);
}

data	*push(data *stack_list, char stack)
{
	int_list	*temp;

	if (stack == B)
	{
		temp = (stack_list -> stack_a) -> next;
		stack_list -> stack_b = \
			push_extended(stack_list -> stack_a, stack_list -> stack_b);
		stack_list -> stack_a = temp;
	}
	else if (stack == A)	
	{
		temp = (stack_list -> stack_b) -> next;
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