/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:15:32 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/18 11:43:51 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size(int n);
void	ft_fill(char *result, int n, int *i);
char	*ft_min(int n);

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	size_t	size;

	i = 0;
	if (n == -2147483648)
	{
		result = ft_min(n);
		if (!result)
			return (NULL);
		return (result);
	}
	size = ft_size(n);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	ft_fill(result, n, &i);
	return (result);
}

size_t	ft_size(int n)
{
	size_t	size;
	int		i;

	size = 1;
	i = 10;
	if (n < 0)
	{
		size++;
		n *= -1;
		if (n >= 1000000000)
			return (11);
	}
	if (n >= 1000000000)
		return (10);
	while (n / i != 0)
	{
		size++;
		i *= 10;
	}
	return (size);
}

void	ft_fill(char *result, int n, int *i)
{
	if (n < 0)
	{
		result[*i] = '-';
		(*i)++;
		n *= -1;
	}
	if (n >= 10)
	{
		ft_fill(result, n / 10, i);
		ft_fill(result, n % 10, i);
	}
	else
	{
		result[*i] = '0' + n;
		(*i)++;
	}
}

char	*ft_min(int n)
{
	char	*result;
	int	i;

	i = 1;
	result = (char *)malloc(sizeof(char) * 12);
	if (!result)
		return (NULL);
	result[0] = '-';
	result[10] = '8';
	result[11] = '\0';
	n = -n / 10;
	ft_fill(result, n, &i);
	return (result);
}
