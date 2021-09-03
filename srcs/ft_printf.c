/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:52:47 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 12:53:04 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags				ft_init_flag(void)
{
	t_flags			flag;

	flag.zero = 0;
	flag.type = 0;
	flag.point = -1;
	flag.tiret = 0;
	flag.taille = 0;
	flag.etoile = 0;
	return (flag);
}

int					ft_parse(const char *format, int index,
					t_flags *flag, va_list arg_list)
{
	while (format[index])
	{
		if (!ft_isdigit(format[index]) && \
		!ft_is_conver(format[index]) && !ft_is_flags(format[index]))
			break ;
		if (format[index] == '0' && flag->taille == 0 && flag->tiret == 0)
			flag->zero = 1;
		if (format[index] == '.')
			index = ft_flag_point(format, index, flag, arg_list);
		if (format[index] == '-')
			*flag = ft_flag_tiret(*flag);
		if (format[index] == '*')
			*flag = ft_flag_taille(arg_list, *flag);
		if (ft_isdigit(format[index]))
			*flag = ft_flag_digit(format[index], *flag);
		if (ft_is_conver(format[index]))
		{
			flag->type = format[index];
			break ;
		}
		index++;
	}
	return (index);
}

int					ft_check_d_format(const char *d_format, va_list arg_list)
{
	int				index;
	t_flags			flag;
	int				cmpt;

	index = 0;
	cmpt = 0;
	while (1)
	{
		flag = ft_init_flag();
		if (!d_format[index])
			break ;
		else if (d_format[index] == '%' && d_format[index + 1])
		{
			index = ft_parse(d_format, ++index, &flag, arg_list);
			if (ft_is_conver(d_format[index]))
				cmpt += ft_check_format((char)flag.type, flag, arg_list);
			else if (d_format[index])
				cmpt += ft_putchar(d_format[index]);
		}
		else if (d_format[index] != '%')
			cmpt += ft_putchar(d_format[index]);
		index++;
	}
	return (cmpt);
}

int					ft_printf(const char *format, ...)
{
	const char		*d_format;
	va_list			arg_list;
	int				cmpt;

	d_format = ft_strdup(format);
	cmpt = 0;
	va_start(arg_list, format);
	cmpt += ft_check_d_format(d_format, arg_list);
	va_end(arg_list);
	free((char *)d_format);
	return (cmpt);
}
