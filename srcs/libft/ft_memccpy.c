/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:43:10 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 16:03:34 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *s1, const void *s2, int c, size_t size)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	size_t			index;

	index = 0;
	p_s1 = (unsigned char*)s1;
	p_s2 = (unsigned char*)s2;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (index < size)
	{
		*p_s1++ = *p_s2;
		if (*p_s2++ == (unsigned char)c)
			return (p_s1);
		++index;
	}
	return (NULL);
}
