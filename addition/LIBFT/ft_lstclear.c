/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:22:07 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/12 13:39:41 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*rm;

	if (!lst)
		return ;
	while (*lst)
	{
		rm = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = rm;
	}
}
