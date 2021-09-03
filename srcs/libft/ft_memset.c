/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:26:58 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/20 11:42:57 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *pointer, int value, size_t size)
{
	size_t		index;
	char		*p_pointer;

	index = 0;
	p_pointer = (char*)pointer;
	while (index < size)
		p_pointer[index++] = (char)value;
	return (p_pointer);
}
