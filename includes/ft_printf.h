/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:50:40 by mdiallo           #+#    #+#             */
/*   Updated: 2021/02/23 14:18:17 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../srcs/libft/libft.h"
# include <stdarg.h>

typedef struct		s_flags
{
	int				tiret;
	int				zero;
	int				point;
	int				etoile;
	int				taille;
	int				type;
	int				other;
}					t_flags;

int					ft_printf(const char *str, ...);
int					ft_is_conver(int c);
int					ft_is_flags(int c);
int					ft_check_format(int c, t_flags flag, va_list arg_list);
int					ft_check_taille(int val_taille,
					int val_tiret, int val_zero);
int					ft_putstrprec(char *str, int prec);
int					ft_conversion_char(char c, t_flags flag);
int					ft_conversion_str(char *str, t_flags flag);
int					ft_conversion_int(int value, t_flags flag);
int					ft_percent(t_flags flag);
int					ft_conversion_hexa(unsigned int value,
					int nb, t_flags flag);
int					ft_conversion_unsi(unsigned int nbr, t_flags flag);
int					ft_flag_point(const char *save, int start,
					t_flags *flag, va_list arg_list);
int					ft_putchar(int c);
int					ft_conversion_pointer(unsigned long long ptr, t_flags flag);

char				*ft_ull_base(unsigned long long ull, int base);
char				*ft_u_itoa(unsigned int n);
char				*ft_str_tolower(char *str);

t_flags				ft_flag_tiret(t_flags flag);
t_flags				ft_flag_taille(va_list arg_list, t_flags flag);
t_flags				ft_flag_digit(char c, t_flags flag);

#endif
