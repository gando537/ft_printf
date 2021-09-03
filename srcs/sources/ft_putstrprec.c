/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:13:04 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 13:13:13 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_putstrprec(char *str, int prec)
{
	int cmpt;

	cmpt = 0;
	while (str[cmpt] && cmpt < prec)
		ft_putchar(str[cmpt++]);
	return (cmpt);
}
