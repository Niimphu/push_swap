/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:56 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/01 20:01:57 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

int	init(int argc, char *argv[]);
int	create_list(int argc, char *argv[]);
int	validate(char *argv[]);
int	ft_isnum(char *str);
int	is_not_duplicate(char *argv[], int n);
// int	repeat_check(t_list *lst);
// int	error_check(t_list *stack_a);
// int	error_exit(t_list *stack_a);

#endif