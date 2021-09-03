/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:37:05 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 12:53:50 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' \
			|| c == '\f' || c == '\n' || c == '\r');
}

int					ft_atoi(const char *str)
{
	int				res;
	int				sign;
	const char		*p_str;

	res = 0;
	sign = 1;
	p_str = str;
	while (ft_is_whitespace(*p_str))
		p_str++;
	if (*p_str == '-' || *p_str == '+')
	{
		if (*p_str == '-')
			sign = -1;
		p_str++;
	}
	while (*p_str >= 48 && *p_str <= 57)
	{
		res = 10 * res + (*p_str - '0');
		p_str++;
	}
	return (res * sign);
}
