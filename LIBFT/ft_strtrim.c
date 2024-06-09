/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:51:58 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 18:08:38 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_coor	to_cor;

typedef struct s_coor
{
	int	d;
	int	f;
}		to_cor;

static void	ft_size(const char *str, const char *set, to_cor *coor);
static int	ft_isset(char c, const char *set);
static char	*ft_fill(char *str, const char *s1, to_cor *coor, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	to_cor	coor;
	char	*str;

	coor.d = 0;
	coor.f = 0;
	ft_size(s1, set, &coor);
	if (coor.d > coor.f)
	{
		str = malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (coor.f - coor.d + 2));
	if (!str)
		return (NULL);
	ft_fill(str, s1, &coor, set);
	return (str);
}

static void	ft_size(char const *str, const char *set, to_cor *coor)
{
	size_t	i;

	i = 0;
	while (ft_isset(str[i], set))
		i++;
	coor->d = i;
	i = ft_strlen(str) - 1;
	while (ft_isset(str[i], set))
		i--;
	coor->f = i;
}

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_fill(char *str, const char *s1, to_cor *coor, const char *set)
{
	int	i;

	i = 0;
	if (coor->d == coor->f)
		coor->f += 1;
	if (!ft_isset(s1[coor->f], set))
	{
		while (coor->d <= coor->f)
		{
			str[i] = s1[coor->d];
			i++;
			coor->d += 1;
		}
	}
	else
	{
		while (coor->d < coor->f)
		{
			str[i] = s1[coor->d];
			i++;
			coor->d += 1;
		}
	}
	str[i] = '\0';
	return (str);
}
