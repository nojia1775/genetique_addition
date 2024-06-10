/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:39:09 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/12 12:12:19 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(size_t len, const char *s, unsigned int start);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (start >= ft_strlen(s) || len == 0)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	size = ft_len(len, s, start);
	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	while (i < len && i < size)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	ft_len(size_t len, const char *s, unsigned int start)
{
	if (len <= ft_strlen(s) - start)
		return (len + 1);
	return (ft_strlen(s) - start + 1);
}
