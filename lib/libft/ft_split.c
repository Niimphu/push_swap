/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:32:04 by yiwong            #+#    #+#             */
/*   Updated: 2023/02/11 17:46:37 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This functions allocates and returns an array of strings obtained by
	splitting string 's' into substrings, using the character 'c' as a delimiter.
	The array must end with a NULL pointer.*/

#include "libft.h"

int	ft_splen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

int	ft_split_count(char *s, char c)
{
	int	i;
	int	scount;

	i = 0;
	scount = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i ++;
		}
		else
		{
			while (s[i] != c && s[i])
				i ++;
			scount ++;
		}
	}
	return (scount);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	char	*str;
	int		scount;
	int		count;

	str = (char *)s;
	scount = ft_split_count(str, c);
	r = (char **)malloc(sizeof(char *) * (scount + 1));
	if (!r)
		return (NULL);
	count = 0;
	while (count < scount)
	{
		if (str[0] != c)
		{
			r[count] = ft_substr(str, 0, ft_splen(str, c));
			if (!(r[count]))
				return (NULL);
			str += ft_splen(str, c);
			count++;
		}
		str++;
	}
	r[scount] = NULL;
	return (r);
}
