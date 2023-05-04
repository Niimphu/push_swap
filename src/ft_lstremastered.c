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

int_list	*int_list_new(char *number_string)
{
	int_list	*new;

	new = malloc(sizeof(int_list));
	new -> number = ft_atoi(number_string);
	new -> next = NULL;
	return (new);
}

int_list	*int_list_last(int_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	int_list_append(int_list *lst, int_list *new)
{
	int_list	*last;

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

void	int_list_delete(int_list *lst)
{
	if (!lst)
		return ;
	free(lst);
	lst = NULL;
	return ;
}

// int_list	*ft_intlstmap(int_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	int_list	*r;
// 	int_list	*current;

// 	if (!lst || !f || !del)
// 		return (NULL);
// 	current = ft_intlstnew((*f)(lst -> content));
// 	r = current;
// 	lst = lst -> next;
// 	while (lst)
// 	{
// 		current -> next = ft_intlstnew((*f)(lst -> content));
// 		if (!r -> next)
// 		{
// 			ft_intlstdelone(r, del);
// 			return (NULL);
// 		}
// 		current = current -> next;
// 		lst = lst -> next;
// 	}
// 	return (r);
// }
