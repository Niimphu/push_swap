/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:37 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/09 17:35:21 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	create_list(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;

	stack_a = ft_lstnew(argv[1]);
	validate(stack_a);
	if (!stack_a)
		exit(0);
	while (i <= argc)
	{
		ft_lstadd_back(stack_a, ft_lstnew(argv[i++]));
		error_check(stack_a);
	}
	ft_lstmap(stack_a, ft_atoi, ft_lstdelone);
	return (0);
}

int	init(int argc, char *argv[])
{
	if (argc <= 1)
		exit(0);
	create_list(argc - 1, &argv[1]);
	return (0);
}
