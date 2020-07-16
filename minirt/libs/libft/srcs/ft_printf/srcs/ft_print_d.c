/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:52:45 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_intlen(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		len = 1;
	if (nb < 0)
	{
		nb *= -1;
		len += 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(long nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr <= 9)
		ft_putchar(nbr + '0');
}

int		ft_get_space(t_flags *flags, int len)
{
	int		space;

	space = 0;
	if (flags->nb_width >= len)
		space = flags->nb_width - len;
	return (space);
}

int		ft_get_zero(t_flags *flags, int *len, long nb)
{
	int		zero;

	zero = 0;
	if (nb < 0 && flags->precision == 1 && flags->nb_precision == *len
		&& zero == 0)
		return (1);
	if (flags->precision == 1 && flags->nb_precision == 0 && nb == 0)
	{
		*len = 0;
		return (0);
	}
	if (flags->nb_precision > *len)
		zero = flags->nb_precision - *len;
	if (nb < 0 && zero > 0)
		zero += 1;
	return (zero);
}

int		ft_print_d(va_list *args, t_flags *flags)
{
	long	nb;
	int		len;
	int		zero;
	int		space;

	nb = va_arg(*args, int);
	len = ft_find_intlen(nb);
	zero = ft_get_zero(flags, &len, nb);
	space = ft_get_space(flags, len + zero);
	if (flags->zero == 0 && flags->left == 0)
		ft_putnchar(' ', space);
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	ft_putnchar('0', (flags->zero) ? space : zero);
	if (len > 0)
		ft_putnbr(nb);
	if (flags->left == 1)
		ft_putnchar(' ', space);
	return (len + zero + space);
}
