/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:22:14 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 12:45:11 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_list;
	t_list		*p_new_list;
	t_list		*p_lst;

	if (!lst || !f || !(new_list = ft_lstnew((*f)(lst->content))))
		return (NULL);
	p_new_list = new_list;
	p_lst = lst->next;
	while (p_lst)
	{
		if (!(p_new_list = ft_lstnew((*f)(p_lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, p_new_list);
		p_lst = p_lst->next;
	}
	return (new_list);
}
