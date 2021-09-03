/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:11:58 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 10:37:49 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *str, const char *substr, size_t size)
{
	size_t		len2;

	if (*substr == '\0')
		return ((char *)str);
	len2 = ft_strlen(substr);
	while (*str != '\0' && size-- >= len2)
	{
		if (*str == *substr && ft_strncmp(str, substr, len2) == 0)
			return ((char *)str);
		str++;
	}
	return (0);
}
