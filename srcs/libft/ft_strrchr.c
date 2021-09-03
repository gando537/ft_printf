/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:18:17 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/21 09:18:31 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *str, int search_char)
{
	unsigned int	index;
	char			*p_s;

	p_s = NULL;
	index = 0;
	while (str[index])
	{
		if (str[index] == (char)search_char)
			p_s = (char *)&str[index];
		index++;
	}
	if ((char)search_char == str[index])
		return ((char *)&str[index]);
	return (p_s);
}
