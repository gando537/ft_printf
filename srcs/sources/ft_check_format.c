/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:57:13 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 12:57:20 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_is_conver(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int			ft_is_flags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int			ft_check_format(int c, t_flags flag, va_list arg_list)
{
	int		count;

	count = 0;
	if (c == 'c')
		count = ft_conversion_char(va_arg(arg_list, int), flag);
	else if (c == 'd' || c == 'i')
		count = ft_conversion_int(va_arg(arg_list, int), flag);
	else if (c == 's')
		count = ft_conversion_str(va_arg(arg_list, char *), flag);
	else if (c == 'p')
		count = ft_conversion_pointer(va_arg(arg_list,
					unsigned long long), flag);
	else if (c == 'u')
		count += ft_conversion_unsi((unsigned int)va_arg(arg_list,
					unsigned int), flag);
	else if (c == 'x')
		count += ft_conversion_hexa(va_arg(arg_list, unsigned int), 1, flag);
	else if (c == 'X')
		count += ft_conversion_hexa(va_arg(arg_list, unsigned int), 0, flag);
	else if (c == '%')
		count += ft_percent(flag);
	return (count);
}
