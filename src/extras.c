/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:49:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/17 19:49:31 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	print_set(t_data *set)
{
	if (set -> stack_a)
	{
		ft_printf("  ---STACK A---\n");
		print_stack(set -> stack_a);
	}
	if (set -> stack_b)
	{
		ft_printf("  ---STACK B---\n");
		print_stack(set -> stack_b);
	}
	ft_printf("  -------------   \n");
	return ;
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("number: %i, ", stack -> number);
		ft_printf("index: %i ", stack -> index);
		ft_printf("\n");
		stack = stack -> next;
	}
	return ;
}
