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

t_int_list	*int_list_new(char *number_string)
{
	t_int_list	*new;

	new = malloc(sizeof(t_int_list));
	new -> number = ft_atoi(number_string);
	new -> index = 0;
	new -> next = NULL;
	return (new);
}

t_int_list	*int_list_last(t_int_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	int_list_append(t_int_list *lst, t_int_list *new)
{
	t_int_list	*last;

	if (!lst || !new)
		return ;
	if (!lst)
	{
		lst = new;
		return ;
	}
	last = int_list_last(lst);
	last -> next = new;
	return ;
}

void	int_list_delete(t_int_list *lst)
{
	if (!lst)
		return ;
	free(lst);
	lst = NULL;
	return ;
}

void	int_list_clear(t_int_list *stack)
{
	t_int_list	*next;

	while (stack -> next)
	{
		next = stack -> next;
		int_list_delete(stack);
		stack = next;
	}
	int_list_delete(stack);
}
