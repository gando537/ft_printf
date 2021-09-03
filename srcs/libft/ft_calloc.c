/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:38:44 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/20 10:28:18 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t element_count, size_t element_size)
{
	void	*alloc;
	size_t	size;

	size = element_count * element_size;
	if (!(alloc = malloc(size)))
		return (NULL);
	ft_memset(alloc, 0, size);
	return (alloc);
}
