/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:50:54 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/08 11:54:44 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	car;
	unsigned char	*str;

	str = s;
	car = c;
	i = 0;
	while (i < n)
	{
		*str = car;
		str++;
		i++;
	}
	return (s);
}
