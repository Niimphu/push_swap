/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:37 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/01 20:06:40 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	init(int argc, char *argv[])
{
	if (argc <= 1 || validate(argv) == 1)
		exit(1);
	create_list(argc, argv);
	return (0);
}

int	create_list(int argc, char *argv[])
{
	int		i;
	t_list	**stack_a;

	i = 1;
	stack_a = malloc(sizeof(t_list));
	*stack_a = ft_lstnew(argv[i++]);
	if (!*stack_a)
		exit(0);
	while (i < argc)
		ft_lstadd_back(stack_a, ft_lstnew(argv[i++]));
	// ft_lstmap(stack_a, ft_atoi, ft_lstdelone);
	return (0);
}

int	validate(char * argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
		{
			ft_printf("Invalid argument: %s\n", argv[i]);
			return (1);
		}
		if (!is_not_duplicate(argv, i))
		{
			ft_printf("Duplicate argument: %s\n", argv[i]);
			return (1);
		}
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
