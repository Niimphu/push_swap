/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:03:44 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/08 16:53:33 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	validate(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (ft_printf("Invalid argument: %s\n", argv[i]));
		if (!is_not_duplicate(argv, i))
			return (ft_printf("Duplicate argument: %s\n", argv[i]));
		i++;
	}
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
			i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			break;
	}
	return (str[i] ? 0 : 1);
}

int	is_not_duplicate(char *argv[], int n)
{
	int	i;

	i = n + 1;
	while (argv[i])
	{
		if (!ft_strncmp(argv[i], argv[n], 20))
			return (0);
		i++;
	}
	return (1);
}

int	is_stack_indexed(int_list *stack)
{
	if (stack -> index == 0)
		return (0);
	while (stack != int_list_last(stack))
	{
		stack = stack -> next;
		if (stack -> index == 0)
			return (0);
	}
	return (1);
}

int_list	*lowest_unindexed_node(int_list *stack)
{
	int_list	*ret;

	while (stack -> index > 0 && stack -> next)
		stack = stack -> next;
	if (stack -> index == 0)
		ret = stack;
	else
		return (NULL);
	while (stack != int_list_last(stack))
	{
		stack = stack -> next;
		if (stack -> number < ret -> number && stack -> index == 0)
			ret = stack;
	}
	return (ret);
}
