/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:27:23 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/06 14:27:23 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	print_stacks(data *stacks)
{
	if (stacks -> stack_a)
		print_stack(stacks -> stack_a);
	if (stacks -> stack_b)
		print_stack(stacks -> stack_b);
	return ;
}

void	print_stack(int_list *stack)
{
	while (stack -> next)
	{
		ft_printf("number: %i, ", stack -> number);
		ft_printf("index: %i\n", stack -> index);
		stack = stack -> next;
	}
	ft_printf("number: %i, ", stack -> number);
	ft_printf("index: %i\n", stack -> index);
	return ;
}
