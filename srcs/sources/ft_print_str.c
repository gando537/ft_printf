/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:04:21 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 13:08:40 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		ft_parse_int(char *str, t_flags flag)
{
	int			cmpt;

	cmpt = 0;
	if (flag.point >= 0)
	{
		cmpt += ft_check_taille(flag.point, ft_strlen(str), 0);
		cmpt += ft_putstrprec(str, flag.point);
	}
	else
		cmpt += ft_putstrprec(str, ft_strlen(str));
	return (cmpt);
}

int				ft_conversion_str(char *str, t_flags flag)
{
	int			cmpt;

	cmpt = 0;
	if (!str)
		str = "(null)";
	if (flag.point >= 0 && (size_t)flag.point > ft_strlen(str))
		flag.point = ft_strlen(str);
	if (flag.tiret == 1)
		cmpt += ft_parse_int(str, flag);
	if (flag.point >= 0)
		cmpt += ft_check_taille(flag.taille, flag.point, 0);
	else
		cmpt += ft_check_taille(flag.taille, ft_strlen(str), 0);
	if (flag.tiret == 0)
		cmpt += ft_parse_int(str, flag);
	return (cmpt);
}
