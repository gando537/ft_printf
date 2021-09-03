/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:52:07 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/20 13:04:38 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size;
	char const		*p_s;
	char			*new_str;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if (!(new_str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	p_s = s;
	index = 0;
	while (*p_s)
	{
		new_str[index] = f(index, *p_s);
		index++;
		p_s++;
	}
	new_str[index] = '\0';
	return (new_str);
}
