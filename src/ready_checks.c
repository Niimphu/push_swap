/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:03:44 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/31 19:22:58 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	is_too_large(char *str)
{
	if (ft_atoll(str) > INT_MAX || ft_atoll(str) < INT_MIN)
		return (0);
	return (1);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
			i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			break ;
	}
	if (str[i])
		return (0);
	else
		return (1);
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

int	is_stack_indexed(t_stack *stack)
{
	while (stack)
	{
		if (stack->i == 0)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*lowest_unied_node(t_stack *stack)
{
	t_stack	*ret;

	while (stack->i > 0 && stack)
		stack = stack->next;
	if (!stack)
		return (NULL);
	ret = stack;
	while (stack)
	{
		if (stack->number < ret->number && !(stack->i))
			ret = stack;
		stack = stack->next;
	}
	return (ret);
}
