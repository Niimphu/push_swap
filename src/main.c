/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:42:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/16 16:03:36 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	main(int argc, char *argv[])
{
	data	*stack_list;

	stack_list = init_stacks_struct();
	if (!stack_list)
		return (1);
	stack_list -> stack_a = init_stack_a(argc, argv);
	if (!stack_list -> stack_a)
		return (1);
	push_swap(stack_list);
	return (0);
}

