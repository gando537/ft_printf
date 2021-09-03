/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:30:54 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/23 09:36:19 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*strn_cpy(char *dest, const char *src, size_t size)
{
	size_t		index;

	index = 0;
	while (index < size && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < size)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

char			*ft_strtrim(char const *s, char const *set)
{
	size_t		beg;
	size_t		end;
	char		*new;

	if (!s || !set)
		return (NULL);
	beg = 0;
	while (s[beg] && ft_strchr(set, s[beg]))
		beg++;
	end = ft_strlen(s + beg);
	if (end)
		while (s[end + beg - 1] != 0 && ft_strchr(set, s[end + beg - 1]) != 0)
			end--;
	if (!(new = malloc(sizeof(char) * end + 1)))
		return (NULL);
	strn_cpy(new, s + beg, end);
	new[end] = '\0';
	return (new);
}
