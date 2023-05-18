/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:42:43 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/06 14:42:43 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	push_swap(t_data *stack_list)
{
	int	count;
	
	if (is_sorted(stack_list -> stack_a))
		return (0);
	count = list_size(stack_list -> stack_a);
	if (count == 2)
		(stack_list = swap(stack_list, A));
	else if (count == 3)
		stack_list = sort_three(stack_list);
	// print_stack(stack_list -> stack_a);
	int_list_clear(stack_list -> stack_a);
	free(stack_list);
	return (0);
}

t_data	*sort_three(t_data *stack_list)
{
	t_int_list	*stack;

	stack = stack_list -> stack_a;
	if (stack -> number > (stack -> next)-> index &&
		stack -> number > ((stack -> next)-> next)-> index)
		stack_list = rotate(stack_list, A);
	else if (stack -> number < (stack -> next)-> index &&
		(stack -> next)-> number > ((stack -> next)-> next)-> index)
		stack_list = reverse_rotate(stack_list, A);
	if (!is_sorted(stack_list -> stack_a))
		stack_list = swap(stack_list, A);
	return (stack_list);
}
