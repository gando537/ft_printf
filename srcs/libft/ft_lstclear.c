/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:39:35 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 12:29:57 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p_lst;
	t_list	*p_init;

	if (!lst || !*lst)
		return ;
	p_init = *lst;
	while (p_init != NULL)
	{
		p_lst = p_init->next;
		ft_lstdelone(p_init, del);
		p_init = p_lst;
	}
	*lst = NULL;
}
