/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/16 17:35:20 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

data	*swap(data *stack_list, char stack)
{
	int_list	*to_first;
	int_list	*current;

	if (stack == A || stack == S)
	{
		current = stack_list -> stack_a;
		to_first = current -> next;
		if (to_first -> next)
			current -> next = to_first -> next;
		else
			current -> next = NULL;
		to_first -> next = current;
		stack_list -> stack_a = to_first;
	}
	if (stack == B || stack == S)
	{
		current = stack_list -> stack_b;
		to_first = current -> next;
		if (to_first -> next)
			current -> next = to_first -> next;
		else
			current -> next = NULL;
		to_first -> next = current;
		stack_list -> stack_b = to_first;
	}
	ft_printf("s%c\n", stack);
	return (stack_list);
}

data	*push(data *stack_list, char stack)
{
	int_list	*pushed;

	if (stack == B)
	{
		pushed = stack_list -> stack_a;
		stack_list -> stack_a = pushed -> next;
		if (!stack_list -> stack_b)
		{
			pushed -> next = NULL;
			stack_list -> stack_b = pushed;
		}
		else
		{
			pushed -> next = stack_list -> stack_b;
			stack_list -> stack_b = pushed;
		}
	}
	else if (stack == A)	
	{
		pushed = stack_list -> stack_b;
		stack_list -> stack_b = pushed -> next;
		pushed -> next = stack_list -> stack_a;
		stack_list -> stack_a = pushed;
	}
	ft_printf("p%c\n", stack);
	return (stack_list);
}
