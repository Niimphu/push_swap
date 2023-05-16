/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/16 16:26:23 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

data	*swap(data *stack_list, char stack)
{
	int_list	*to_first;
	int_list	*current;

	if (stack == 'a' || stack == 's')
	{
		current = stack_list -> stack_a;
		to_first = current -> next;
		current -> next = to_first -> next;
		to_first -> next = current;
		stack_list -> stack_a = to_first;
	}
	if (stack == 'b' || stack == 's')
	{
		current = stack_list -> stack_b;
		to_first = current -> next;
		current -> next = to_first -> next;
		to_first -> next = current;
		stack_list -> stack_b = to_first;
	}
	ft_printf("s%c\n", stack);
	return (stack_list);
}