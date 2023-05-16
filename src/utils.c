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

void	print_stack_list(data *stack_list)
{
	if (stack_list -> stack_a)
	{
		ft_printf("  ---STACK A---\n");
		print_stack(stack_list -> stack_a);
	}
	if (stack_list -> stack_b)
	{
		ft_printf("  ---STACK B---\n");
		print_stack(stack_list -> stack_b);
	}
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
