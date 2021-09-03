/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:09:30 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 13:09:43 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		ft_parsed_uint(char *unsi_int, t_flags flag)
{
	int			cmpt;

	cmpt = 0;
	if (flag.point >= 0)
		cmpt += ft_check_taille(flag.point - 1, ft_strlen(unsi_int) - 1, 1);
	cmpt += ft_putstrprec(unsi_int, ft_strlen(unsi_int));
	return (cmpt);
}

static int		ft_parse_uint(char *unsi_int, t_flags flag)
{
	int			cmpt;

	cmpt = 0;
	if (flag.tiret == 1)
		cmpt += ft_parsed_uint(unsi_int, flag);
	if (flag.point >= 0 && (size_t)flag.point < ft_strlen(unsi_int))
		flag.point = ft_strlen(unsi_int);
	if (flag.point >= 0)
	{
		flag.taille -= flag.point;
		cmpt += ft_check_taille(flag.taille, 0, 0);
	}
	else
		cmpt += ft_check_taille(flag.taille,
		ft_strlen(unsi_int), flag.zero);
	if (flag.tiret == 0)
		cmpt += ft_parsed_uint(unsi_int, flag);
	return (cmpt);
}

int				ft_conversion_unsi(unsigned int nbr, t_flags flag)
{
	char		*unsi_int;
	int			cmpt;

	cmpt = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flag.point == 0 && nbr == 0)
	{
		cmpt += ft_check_taille(flag.taille, 0, 0);
		return (cmpt);
	}
	unsi_int = ft_u_itoa(nbr);
	cmpt += ft_parse_uint(unsi_int, flag);
	free(unsi_int);
	return (cmpt);
}
