/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:57:49 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 12:58:25 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_percent(t_flags flag)
{
	int cmpt;

	cmpt = 0;
	if (flag.tiret == 1)
		cmpt += ft_putstrprec("%", 1);
	cmpt += ft_check_taille(flag.taille, 1, flag.zero);
	if (flag.tiret == 0)
		cmpt += ft_putstrprec("%", 1);
	return (cmpt);
}
