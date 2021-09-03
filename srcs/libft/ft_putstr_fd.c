/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:49:45 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/20 11:46:35 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char const *p_s;

	if (s == NULL)
		return ;
	p_s = s;
	while (*p_s)
	{
		ft_putchar_fd(*p_s, fd);
		p_s++;
	}
}
