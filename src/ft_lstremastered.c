/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremastered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:12:34 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/02 02:12:34 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_stack	*new_stack_node(char *number_string)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->number = ft_atoi(number_string);
	new->i = 0;
	new->dist[UP] = -1;
	new->dist[DOWN] = -1;
	new->cost[0] = -1;
	new->cost[1] = -1;
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	stack_append(t_stack *lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (!lst)
	{
		lst = new;
		return ;
	}
	last = stack_last(lst);
	last->next = new;
	return ;
}

void	stack_node_delete(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
	lst = NULL;
	return ;
}

void	stack_clear(t_stack *stack)
{
	t_stack	*next;

	while (stack->next)
	{
		next = stack->next;
		stack_node_delete(stack);
		stack = next;
	}
	stack_node_delete(stack);
	return ;
}
