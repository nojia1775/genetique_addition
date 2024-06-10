/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:00:19 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/12 11:27:20 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_good(const char *big, const char *little, size_t *len,
					size_t *i);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && len)
	{
		j = ft_good(big, little, &len, &i);
		if (j)
			return ((char *)big + i - j);
	}
	return (NULL);
}

static size_t	ft_good(const char *big, const char *little, size_t *len,
	size_t *i)
{
	size_t	j;

	j = 0;
	while (little[j] == big[*i] && big[*i] && little[j] && *(int *)len != 0)
	{
		*i += 1;
		j++;
		*len -= 1;
	}
	if (little[j] == '\0')
		return (j);
	if (j == 0)
	{
		*len -= 1;
		*i += 1;
	}
	else if (j > 1)
	{
		*len += 1;
		*i -= 1;
	}
	return (0);
}
