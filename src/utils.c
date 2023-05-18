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

int	is_sorted(t_int_list *stack)
{
	int	i;

	i = 1;
	while (stack != int_list_last(stack))
	{
		if (stack -> number != i++)
			return (0);
		stack = stack -> next;
	}
	if (stack -> number != i++)
		return (0);
	return (1);
}

int	list_size(t_int_list *stack)
{
	int	n;

	if (!stack)
		return (0);
	n = 1;
	while (stack -> next)
	{
		stack = stack -> next;
		n++;
	}
	return (n);
}
