/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:44:31 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:53:34 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_zero_u(t_flags *flags, int *len, unsigned long int nb)
{
	int					zero;

	zero = 0;
	if (flags->precision == 1 && flags->nb_precision == 0 && nb == 0)
	{
		*len = 0;
		return (0);
	}
	if (flags->nb_precision > *len)
		zero = flags->nb_precision - *len;
	return (zero);
}

int		ft_find_ulen(unsigned long int nb)
{
	int					len;

	len = 0;
	if (nb == 0)
		len += 1;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_u(unsigned long int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
}

int		ft_print_u(va_list *args, t_flags *flags)
{
	unsigned long int	nb;
	int					len;
	int					zero;
	int					space;
	char				c;

	c = ' ';
	if (flags->zero == 1)
		c = '0';
	nb = va_arg(*args, unsigned int);
	len = ft_find_ulen(nb);
	zero = ft_get_zero_u(flags, &len, nb);
	space = ft_get_space(flags, len + zero);
	if (flags->left == 0)
		ft_putnchar(c, space);
	ft_putnchar('0', zero);
	if (len > 0)
		ft_putnbr_u(nb);
	if (flags->left == 1)
		ft_putnchar(c, space);
	return (len + zero + space);
}
