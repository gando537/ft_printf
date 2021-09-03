/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:56:24 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 12:56:41 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_flags		ft_flag_tiret(t_flags flag)
{
	flag.tiret = 1;
	flag.zero = 0;
	return (flag);
}

t_flags		ft_flag_digit(char c, t_flags flag)
{
	if (flag.etoile == 1)
		flag.taille = 0;
	flag.taille = (flag.taille * 10) + (c - '0');
	return (flag);
}

t_flags		ft_flag_taille(va_list arg_list, t_flags flag)
{
	flag.etoile = 1;
	flag.taille = va_arg(arg_list, int);
	if (flag.taille < 0)
	{
		flag.tiret = 1;
		flag.taille *= -1;
	}
	return (flag);
}

int			ft_flag_point(const char *save, int start,
			t_flags *flag, va_list arg_list)
{
	int index;

	index = start;
	index++;
	if (save[index] == '*')
	{
		flag->point = va_arg(arg_list, int);
		index++;
	}
	else
	{
		flag->point = 0;
		while (ft_isdigit(save[index]))
			flag->point = (flag->point * 10) + (save[index++] - '0');
	}
	return (index);
}
