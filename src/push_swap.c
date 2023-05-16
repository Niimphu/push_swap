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

int	push_swap(data *stack_list)
{
	print_stack_list(stack_list);
	push(stack_list, B);
	push(stack_list, B);
	push(stack_list, A);
	push(stack_list, B);
	swap(stack_list, S);
	print_stack_list(stack_list);
	int_list_clear(stack_list -> stack_a);
	free(stack_list);
	return (0);
}
