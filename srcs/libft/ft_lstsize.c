/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:51:14 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 12:48:08 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*p_lst;

	p_lst = lst;
	size = 0;
	while (p_lst)
	{
		++size;
		p_lst = p_lst->next;
	}
	return (size);
}
