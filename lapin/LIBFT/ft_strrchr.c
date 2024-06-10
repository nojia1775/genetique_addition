/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:35:20 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/11 14:48:57 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*oc;
	int		i;

	i = 0;
	oc = NULL;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
			oc = (char *)s + i;
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (oc);
}
