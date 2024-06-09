/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:51:51 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/10 16:12:58 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	size_src;
	size_t	i;
	size_t	size_dest;

	i = 0;
	if (!src || !dest)
		return (0);
	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);
	if (n == 0)
		return (size_src);
	while (i < n - 1 && i < size_dest)
		i++;
	while (i < n - 1 && *src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	if (n > size_dest)
		dest[i] = '\0';
	if (n < size_dest)
		return (n + size_src);
	return (size_dest + size_src);
}
