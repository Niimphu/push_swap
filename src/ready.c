/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:37 by yiwong            #+#    #+#             */
/*   Updated: 2023/02/24 15:12:04 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_list()
{
	int		i;
	t_list	stack_a;

	if (argc <= 1)
		exit(0);
	stack_a = ft_lstnew(argv[1]);
	if (!stack_a)
		exit(0);
	while (i <= argc)
	{
		
	}
}

int	init(int argc, char *argv[])
{
	create_list(argc - 1, &argv[1]);
}
