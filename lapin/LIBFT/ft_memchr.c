/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:55:48 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/10 15:53:08 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc;

	uc = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (uc[i] == (unsigned char)c)
			return ((void *)uc + i);
		i++;
	}
	return (0);
}
