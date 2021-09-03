/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:45:25 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/20 13:25:50 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *mem_block, int search_char, size_t size)
{
	char		*p_memory_block;
	size_t		index;

	index = 0;
	p_memory_block = (char*)mem_block;
	while (index < size)
	{
		if (*p_memory_block == search_char)
			return (p_memory_block);
		p_memory_block++;
		index++;
	}
	return (NULL);
}
