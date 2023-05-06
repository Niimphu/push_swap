/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:37 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/06 15:04:03 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	init(int argc, char *argv[])
{
	if (argc <= 1 || validate(argv + 1) == 1)
		exit(1);
	if (create_list(argc, argv))
		exit(1);
	return (0);
}

int	create_list(int argc, char *argv[])
{
	int			i;
	int_list	*stack_a;

	i = 1;
	stack_a = int_list_new(argv[i++]);
	if (!stack_a)
		return (ft_printf("%s: stack allocation failed\n", argv[0]));
	while (i < argc)
		int_list_append(stack_a, int_list_new(argv[i++]));
	// print_stack(stack_a);
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
