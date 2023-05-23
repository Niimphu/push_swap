/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:47:22 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/22 16:47:22 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"
# include "get_next_line/get_next_line.h"

# define INVALID -1

t_data	*apply_command(t_data *set, char *input);
t_data	*check(t_data *set);
int		get_stack_id(char *input);

#endif