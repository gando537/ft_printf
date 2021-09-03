/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:47:06 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 09:17:51 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *p1, const void *p2, size_t size)
{
	size_t				index;
	unsigned char		*p_pointer1;
	unsigned char		*p_pointer2;

	index = 0;
	p_pointer1 = (unsigned char*)p1;
	p_pointer2 = (unsigned char*)p2;
	while (index < size)
	{
		if (p_pointer1[index] != p_pointer2[index])
			return (p_pointer1[index] - p_pointer2[index]);
		index++;
	}
	return (0);
}
