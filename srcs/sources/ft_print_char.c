/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:58:58 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 12:59:06 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_conversion_char(char c, t_flags flag)
{
	int		cmpt;

	cmpt = 0;
	if (flag.tiret == 1)
		ft_putchar(c);
	cmpt = ft_check_taille(flag.taille, 1, 0);
	if (flag.tiret == 0)
		ft_putchar(c);
	return (cmpt + 1);
}
