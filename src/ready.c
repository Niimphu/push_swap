/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:37 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/15 15:44:27 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

data	*init_stacks_struct(void)
{
	data	*stacks;

	stacks = malloc(sizeof(data));
	if (!stacks)
		return (NULL);
	stacks -> stack_a = NULL;
	stacks -> stack_b = NULL;
	return (stacks);
}

int_list	*init_stack_a(int argc, char *argv[])
{
	int_list	*stack_a;
	char		**input;

	if (argc <= 1)
	{
		ft_printf("Not enough arguments\n");
		return (NULL);
	}
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = argv + 1;
	if (validate(input) == 0)
		stack_a = create_list(input);
	else
		stack_a = NULL;
	if (argc ==  2)
		free_ppointer(input);
	return (stack_a);
}

int_list	*create_list(char **input)
{
	int		i;
	int_list	*stack_a;

	i = 0;
	stack_a = int_list_new(input[i++]);
	if (!stack_a)
		return (NULL);
	while (input[i])
		int_list_append(stack_a, int_list_new(input[i++]));
	index_stack(stack_a);
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
		if (!next)
			continue ;
		next -> index = n++;
	}
	return ;
}