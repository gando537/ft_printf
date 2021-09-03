/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:00:22 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 13:00:30 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		ft_parsed_hexa(char *hexa, t_flags flag)
{
	int			cmpt;

	cmpt = 0;
	if (flag.point >= 0)
		cmpt += ft_check_taille(flag.point - 1, ft_strlen(hexa) - 1, 1);
	cmpt += ft_putstrprec(hexa, ft_strlen(hexa));
	return (cmpt);
}

static int		ft_parse_hexa(char *hexa, t_flags flag)
{
	int			cmpt;

	cmpt = 0;
	if (flag.tiret == 1)
		cmpt += ft_parsed_hexa(hexa, flag);
	if (flag.point >= 0 && (size_t)flag.point < ft_strlen(hexa))
		flag.point = ft_strlen(hexa);
	if (flag.point >= 0)
	{
		flag.taille -= flag.point;
		cmpt += ft_check_taille(flag.taille, 0, 0);
	}
	else
		cmpt += ft_check_taille(flag.taille,
		ft_strlen(hexa), flag.zero);
	if (flag.tiret == 0)
		cmpt += ft_parsed_hexa(hexa, flag);
	return (cmpt);
}

int				ft_conversion_hexa(unsigned int value, int nb, t_flags flag)
{
	char		*hexa;
	int			cmpt;

	cmpt = 0;
	value = (unsigned int)(4294967295 + 1 + value);
	if (flag.point == 0 && value == 0)
	{
		cmpt += ft_check_taille(flag.taille, 0, 0);
		return (cmpt);
	}
	hexa = ft_ull_base((unsigned long long)value, 16);
	if (nb == 1)
		hexa = ft_str_tolower(hexa);
	cmpt += ft_parse_hexa(hexa, flag);
	free(hexa);
	return (cmpt);
}
