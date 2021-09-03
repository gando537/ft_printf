/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:45 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 13:28:17 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *first, const char *second, size_t length)
{
	unsigned char	*p_first;
	unsigned char	*p_second;

	p_first = (unsigned char *)first;
	p_second = (unsigned char *)second;
	while ((*p_first || *p_second) && length > 0)
	{
		if (*p_first != *p_second)
			return (*p_first - *p_second);
		p_first++;
		p_second++;
		length--;
	}
	return (0);
}
