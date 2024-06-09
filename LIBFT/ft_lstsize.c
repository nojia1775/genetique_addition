/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:16:50 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/10 15:53:51 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*cur;

	cur = lst;
	len = 0;
	while (cur != NULL)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}
