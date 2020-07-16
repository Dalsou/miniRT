/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:44:31 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:53:02 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_find_strlen(char *str, t_flags *flags)
{
	int		len;

	len = ft_strlen(str);
	if (flags->precision == 1 && flags->nb_precision < len)
		len = flags->nb_precision;
	return (len);
}

int		ft_print_s(va_list *args, t_flags *flags)
{
	char	*str;
	int		width;
	int		len;

	str = va_arg(*args, char *);
	width = 0;
	len = 0;
	if (!str)
		str = "(null)";
	len = ft_find_strlen(str, flags);
	if (flags->left == 1)
		ft_putnstr(str, len);
	if (flags->width == 1 && flags->nb_width > len)
		width = flags->nb_width - len;
	ft_putnchar(' ', width);
	if (flags->left == 0)
		ft_putnstr(str, len);
	return (len + width);
}
