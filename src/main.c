/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:42:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/21 18:01:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*set;

	set = init_stacks_struct();
	if (!set)
		return (1);
	set->stack_a = init_stack_a(argc, argv);
	if (!set->stack_a)
		return (1);
	push_swap(set);
	return (0);
}
