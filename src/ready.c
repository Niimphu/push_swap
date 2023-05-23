/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:37 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/22 16:58:30 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_data	*init_stacks_struct(void)
{
	t_data	*set;

	set = malloc(sizeof(t_data));
	if (!set)
		return (NULL);
	set->stack_a = NULL;
	set->stack_b = NULL;
	return (set);
}

t_stack	*init_stack_a(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	**input;

	if (argc <= 1)
		return (NULL);
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = argv + 1;
	if (validate(input) == 0)
		stack_a = create_list(input);
	else
		stack_a = NULL;
	if (argc == 2)
		free_ppointer(input);
	return (stack_a);
}

int	validate(char *input[])
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isnum(input[i]) || !is_not_duplicate(input, i) || \
			!is_too_large(input[i]))
			return (write(2, "Error\n", 6));
		i++;
	}
	return (0);
}

t_stack	*create_list(char **input)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	stack_a = new_stack_node(input[i++]);
	if (!stack_a)
		return (NULL);
	while (input[i])
		stack_append(stack_a, new_stack_node(input[i++]));
	index_stack(stack_a);
	return (stack_a);
}

void	index_stack(t_stack *stack)
{
	int		n;
	t_stack	*next;

	n = 1;
	while (!is_stack_indexed(stack))
	{
		next = lowest_unied_node(stack);
		if (!next)
			continue ;
		next->i = n++;
	}
	return ;
}
