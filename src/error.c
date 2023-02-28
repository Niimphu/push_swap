/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:54:05 by yiwong            #+#    #+#             */
/*   Updated: 2023/02/28 17:40:41 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate()

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
	repeat_check(stack_a);
	ft_lstiter(stack_a, validate);
}

int	error_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}
