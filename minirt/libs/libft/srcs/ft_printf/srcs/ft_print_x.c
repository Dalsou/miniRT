/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:53:14 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_lenbase(long nb, int base)
{
	int					len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

void	ft_putnbr_base(unsigned long int nb, char *base)
{
	unsigned long int	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		ft_putnbr_base(nb / base_len, base);
		ft_putnbr_base(nb % base_len, base);
	}
	if (nb < base_len)
		ft_putchar(base[nb]);
}

int		ft_convert_hex(unsigned long int nb, char *base, t_flags *flags)
{
	int					len;
	int					zero;
	int					space;
	char				c;

	len = 0;
	zero = 0;
	space = 0;
	c = ' ';
	if (flags->zero == 1)
		c = '0';
	len = ft_find_lenbase(nb, 16);
	zero = ft_get_zero_u(flags, &len, nb);
	space = ft_get_space(flags, len + zero);
	if (flags->left == 0)
		ft_putnchar(c, space);
	ft_putnchar('0', zero);
	if (len > 0)
		ft_putnbr_base(nb, base);
	if (flags->left == 1)
		ft_putnchar(c, space);
	return (len + zero + space);
}

int		ft_print_x(va_list *args, t_flags *flags)
{
	unsigned long int	nb;

	nb = va_arg(*args, unsigned int);
	return (ft_convert_hex(nb, "0123456789abcdef", flags));
}

int		ft_print_x2(va_list *args, t_flags *flags)
{
	unsigned long int	nb;

	nb = va_arg(*args, unsigned int);
	return (ft_convert_hex(nb, "0123456789ABCDEF", flags));
}
