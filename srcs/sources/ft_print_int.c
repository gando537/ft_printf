/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:01:13 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 13:01:26 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		ft_parsed_int(char *d_value, int save_value, t_flags flag)
{
	int			cmpt;

	cmpt = 0;
	if (save_value < 0 && flag.point >= 0)
		ft_putchar('-');
	if (flag.point >= 0)
		cmpt += ft_check_taille(flag.point - 1, ft_strlen(d_value) - 1, 1);
	cmpt += ft_putstrprec(d_value, ft_strlen(d_value));
	return (cmpt);
}

static int		ft_parse_int(char *d_value, int save_value, t_flags flag)
{
	int			cmpt;

	cmpt = 0;
	if (flag.tiret == 1)
		cmpt += ft_parsed_int(d_value, save_value, flag);
	if (flag.point >= 0 && (size_t)flag.point < ft_strlen(d_value))
		flag.point = ft_strlen(d_value);
	if (flag.point >= 0)
	{
		flag.taille -= flag.point;
		cmpt += ft_check_taille(flag.taille, 0, 0);
	}
	else
		cmpt += ft_check_taille(flag.taille, ft_strlen(d_value), flag.zero);
	if (flag.tiret == 0)
		cmpt += ft_parsed_int(d_value, save_value, flag);
	return (cmpt);
}

static void		ft_treat_int_min(char *d_v, int *s_v)
{
	size_t		size;

	size = ft_strlen(d_v);
	if (*s_v == -2147483648)
		d_v[size - 1] = '8';
}

int				ft_conversion_int(int value, t_flags flag)
{
	char		*d_value;
	int			save_value;
	int			cmpt;

	save_value = value;
	cmpt = 0;
	if (flag.point == 0 && value == 0)
		return (ft_check_taille(flag.taille, 0, 0));
	if (value < 0 && (flag.point >= 0 || flag.zero == 1))
	{
		if (flag.zero == 1 && flag.point == -1)
			ft_putstrprec("-", 1);
		value = (value == -2147483648) ? 2147483647 : value * (-1);
		flag.zero = 1;
		flag.taille--;
		cmpt++;
	}
	d_value = ft_itoa(value);
	ft_treat_int_min(d_value, &save_value);
	cmpt += ft_parse_int(d_value, save_value, flag);
	free(d_value);
	return (cmpt);
}
