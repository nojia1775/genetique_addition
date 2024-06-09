/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:11:48 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/23 18:08:40 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clean(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*buffer == '\0')
		return ;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	while (buffer[j])
		buffer[j++] = '\0';
}

int	ft_verif(int r, char *buf, char *buffer)
{
	int	i;

	i = 0;
	if (r <= 0 && buffer[0] == '\0')
	{
		free(buf);
		while (buffer[i])
			buffer[i++] = '\0';
		return (1);
	}
	return (0);
}
