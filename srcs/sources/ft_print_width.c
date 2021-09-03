/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:10:54 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 13:11:02 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_check_taille(int val_taille, int val_tiret, int val_zero)
{
	int		cmpt;

	cmpt = 0;
	while (val_taille - val_tiret > 0)
	{
		if (val_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		val_taille--;
		cmpt++;
	}
	return (cmpt);
}
