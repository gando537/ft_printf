/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:34:30 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/19 10:30:05 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	const char	*p_s1;
	const char	*p_s2;
	char		*new_str;
	char		*p_new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	p_s1 = s1;
	p_s2 = s2;
	p_new_str = new_str;
	while ((*p_new_str++ = *p_s1++))
		;
	p_new_str--;
	while ((*p_new_str++ = *p_s2++))
		;
	*p_new_str = '\0';
	return (new_str);
}
