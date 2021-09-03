/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:37:07 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/20 13:45:52 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content)
{
	t_list		*new_maillon;

	if (!(new_maillon = malloc(sizeof(t_list))))
		return (NULL);
	new_maillon->content = content;
	new_maillon->next = NULL;
	return (new_maillon);
}
