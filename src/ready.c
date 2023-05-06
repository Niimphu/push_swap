/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:37 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/06 19:08:33 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	init(int argc, char *argv[])
{
	int_list	*stack_a;

	if (argc <= 1 || validate(argv + 1))
		exit(1);
	stack_a = create_list(argc, argv);
	if (!stack_a)
		exit(1);
	push_swap(stack_a);
	return (0);
}

int_list	*create_list(int argc, char *argv[])
{
	int			i;
	int_list	*stack_a;

	i = 1;
	stack_a = int_list_new(argv[i++]);
	if (!stack_a)
		return (NULL);
	while (i < argc)
		int_list_append(stack_a, int_list_new(argv[i++]));
	return (stack_a);
}

void	index_stack(int_list *stack)
{
	unsigned long	n;
	int_list		*next;

	n = 1;
	while (!is_stack_indexed(stack))
	{
		next = lowest_unindexed_node(stack);
		next -> index = n++;
	}
	return ;
}