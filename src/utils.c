/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:27:23 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/06 14:27:23 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

long long	ft_atoll_extended(int i, char *s, int sign);

long long	ft_atoll(const char *nptr)
{
	int		i;
	char	*s;
	int		sign;

	i = 0;
	s = (char *)nptr;
	while (s[i] == ' ' || s[i] == '\t'
		|| s[i] == '\n' || s[i] == '\r' || s[i] == '\f' || s[i] == '\v')
		i++;
	sign = 1;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	return (ft_atoll_extended(i, s, sign));
}

long long	ft_atoll_extended(int i, char *s, int sign)
{
	long long	r;

	r = 0;
	if (ft_isdigit(s[i]))
	{
		r = (s[i] - '0') * sign;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		r = 10 * r + (s[i] - '0') * sign;
		i++;
	}
	return (r);
}

void	print_stack_list(t_data *stack_list)
{
	if (stack_list -> stack_a)
	{
		ft_printf("  ---STACK A---\n");
		print_stack(stack_list -> stack_a);
	}
	if (stack_list -> stack_b)
	{
		ft_printf("  ---STACK B---\n");
		print_stack(stack_list -> stack_b);
	}
	return ;
}

void	print_stack(t_int_list *stack)
{
	while (stack -> next)
	{
		ft_printf("number: %i, ", stack -> number);
		ft_printf("index: %i\n", stack -> index);
		stack = stack -> next;
	}
	ft_printf("number: %i, ", stack -> number);
	ft_printf("index: %i\n", stack -> index);
	return ;
}
