/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:45:15 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/08 15:50:17 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*loop;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		loop = node->next;
		del(node->content);
		free(node);
		node = loop;
	}
	*lst = NULL;
}
