/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:02:58 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 13:03:43 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_parse_pointer(char *pointer, t_flags flag)
{
	int		cmpt;

	cmpt = 0;
	cmpt += ft_putstrprec("0x", 2);
	if (flag.point >= 0)
	{
		cmpt += ft_check_taille(flag.point, ft_strlen(pointer), 1);
		cmpt += ft_putstrprec(pointer, flag.point);
	}
	else
		cmpt += ft_putstrprec(pointer, ft_strlen(pointer));
	return (cmpt);
}

int			ft_conversion_pointer(unsigned long long ptr, t_flags flag)
{
	char	*pointer;
	int		cmpt;

	cmpt = 0;
	if (ptr == 0 && flag.point == 0)
	{
		cmpt += ft_putstrprec("0x", 2);
		return (cmpt += ft_check_taille(flag.taille, 0, 1));
	}
	pointer = ft_ull_base(ptr, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flag.point < ft_strlen(pointer))
		flag.point = ft_strlen(pointer);
	if (flag.tiret == 1)
		cmpt += ft_parse_pointer(pointer, flag);
	cmpt += ft_check_taille(flag.taille, ft_strlen(pointer) + 2, 0);
	if (flag.tiret == 0)
		cmpt += ft_parse_pointer(pointer, flag);
	free(pointer);
	return (cmpt);
}
