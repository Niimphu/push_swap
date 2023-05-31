/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:46:22 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/22 16:46:22 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*set;

	set = init_stacks_struct();
	if (!set)
		return (1);
	set->stack_a = init_stack_a(argc, argv);
	if (!set->stack_a)
		return (1);
	set = check(set);
	stack_clear(set->stack_a);
	stack_clear(set->stack_b);
	free(set);
	return (0);
}

t_data	*check(t_data *set)
{
	char	*input;
	t_data	*new_set;

	input = "\0";
	while (input)
	{
		input = get_next_line(0);
		if (input)
			new_set = apply_command(set, input);
		free_pointer(input);
		if (new_set == NULL)
			return (set);
		else
			set = new_set;
	}
	if (is_sorted(set->stack_a) && !set->stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (set);
}

t_data	*apply_command(t_data *set, char *input)
{
	int	stack_id;

	stack_id = get_stack_id(input);
	if (stack_id == INVALID)
		stack_id = INVALID;
	else if (!ft_strncmp(input, "sa\n", 3) || !ft_strncmp(input, "sb\n", 3)
		|| !ft_strncmp(input, "ss\n", 3))
		set = bonus_swap(set, stack_id);
	else if (!ft_strncmp(input, "pa\n", 3) || !ft_strncmp(input, "pb\n", 3))
		set = bonus_push(set, stack_id);
	else if (!ft_strncmp(input, "ra\n", 3) || !ft_strncmp(input, "rb\n", 3)
		|| !ft_strncmp(input, "rr\n", 3))
		set = bonus_rotate(set, stack_id);
	else if (!ft_strncmp(input, "rra\n", 4)
		|| !ft_strncmp(input, "rrb\n", 4) || !ft_strncmp(input, "rrr\n", 4))
		set = bonus_reverse_rotate(set, stack_id);
	else
		stack_id = INVALID;
	if (stack_id == INVALID)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (set);
}

int	get_stack_id(char *input)
{
	if (!ft_strncmp(input, "\n", 1))
		return (INVALID);
	if (input[1] == 'a' && ft_strlen(input) == 3)
		return (A);
	if (input[1] == 'b' && ft_strlen(input) == 3)
		return (B);
	if (input[1] == 's' && ft_strlen(input) == 3)
		return (S);
	if (input[1] == 'r' && ft_strlen(input) == 3)
		return (R);
	if (input[2] == 'a' && ft_strlen(input) == 4)
		return (A);
	if (input[2] == 'b' && ft_strlen(input) == 4)
		return (B);
	if (input[2] == 'r' && ft_strlen(input) == 4)
		return (R);
	return (INVALID);
}
