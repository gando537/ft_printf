/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:48:48 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/23 11:47:52 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t		index;
	char		*p_dest;
	char		*p_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	index = 0;
	p_dest = (char*)dest;
	p_src = (char*)src;
	while (index < size)
	{
		*p_dest++ = *p_src++;
		index++;
	}
	return (dest);
}
