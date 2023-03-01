/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:54:05 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/01 19:30:08 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate(void)
{
	stack_a
}

int	repeat_check(t_list lst)
{
	t_list	last;

	last = ft_lstlast(lst);
	while (lst)
	{
		if (lst -> content == last -> content && lst -> next)
			return (1);
		lst = lst -> next;
	}
	return (0);
}

int	error_check(t_list stack_a)
{
	if (repeat_check(stack_a))
		error_exit(stack_a);
	ft_lstiter(stack_a, validate);
	return (0);
}

int	error_exit(t_list stack_a)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	ft_printf("Error\n");
	exit(0);
}
