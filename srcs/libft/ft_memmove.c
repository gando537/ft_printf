/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:54:07 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 15:49:58 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*s;
	char		*d;
	size_t		i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (0);
	if (d > s)
		while (size-- > 0)
			d[size] = s[size];
	else
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	return (dest);
}
