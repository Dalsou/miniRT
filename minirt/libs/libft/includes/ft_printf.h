/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 15:40:11 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

# define TYPE_FIELD "cspdiuxX%"

typedef struct	s_flags
{
	int precision;
	int left;
	int zero;
	int width;
	int	nb_width;
	int nb_precision;
}				t_flags;

int				ft_printf(const char *src, ...);
int				ft_strlen_printf(const char *s);
char			*ft_strdup_printf(const char *s1);
char			*ft_strndup(const char *s1, int len);
void			ft_reset_flags(t_flags *flags);
int				ft_flag_zero(char *str);
void			ft_flag_width(char *str, t_flags *flags, va_list *list);
void			ft_init_flags(char *str, t_flags *flags, va_list *list);
void			ft_init_functions(int (*functions[]) (va_list *, t_flags *));
int				ft_parse(char *str, va_list *list, int *i);
int				ft_find_index(char *str, char element);
int				ft_find_end(char *s1, char *s2);
int				ft_find_nb(char *str, va_list *list);
int				ft_print_i(va_list *args, t_flags *flags);
int				ft_print_d(va_list *args, t_flags *flags);
void			ft_putchar(char c);
void			ft_putnchar(char c, int n);
void			ft_putstr(char *str);
void			ft_putnstr(char *str, int n);
void			ft_putnbr(long nbr);
int				ft_print_c(va_list *args, t_flags *flags);
int				ft_print_s(va_list *args, t_flags *flags);
int				ft_find_strlen(char *str, t_flags *flags);
int				ft_get_zero(t_flags *flags, int *len, long nb);
int				ft_get_space(t_flags *flags, int len);
int				ft_print_d(va_list *args, t_flags *flags);
int				ft_find_intlen(long nb);
int				ft_print_p(va_list *args, t_flags *flags);
int				ft_find_lenbase(long nb, int base);
void			ft_putnbr_base(unsigned long int nb, char *base);
int				ft_get_zero_u(t_flags *flags, int *len, unsigned long int nb);
int				ft_convert_hex(unsigned long int nb, char *base,
				t_flags *flags);
int				ft_print_u(va_list *args, t_flags *flags);
int				ft_print_x(va_list *args, t_flags *flags);
int				ft_print_x2(va_list *args, t_flags *flags);
void			ft_putnbr_u(unsigned long int nbr);
int				ft_find_ulen(unsigned long int nb);
int				ft_print_prct(va_list *args, t_flags *flags);

#endif