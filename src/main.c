/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:42:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/08 16:49:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	main(int argc, char *argv[])
{
	data	*stacks;

	stacks = init_stacks_struct();
	if (!stacks)
		return (1);
	stacks -> stack_a = init_stack_a(argc, argv);
	if (!stacks -> stack_a)
		return (1);
	push_swap(stacks);
	return (0);
}

