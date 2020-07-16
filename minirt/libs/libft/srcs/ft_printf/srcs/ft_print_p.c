/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:52:50 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_p(va_list *args, t_flags *flags)
{
	long	nb;
	long	len;
	long	space;

	nb = va_arg(*args, long);
	len = ft_find_lenbase(nb, 16) + 2;
	space = 0;
	if (flags->precision == 1 && flags->nb_precision == 0 && nb == 0)
		len = 2;
	if (flags->nb_width > len)
		space = flags->nb_width - len;
	if (flags->left == 0)
		ft_putnchar(' ', space);
	ft_putstr("0x");
	if (len > 2)
		ft_putnbr_base(nb, "0123456789abcdef");
	if (flags->left == 1)
		ft_putnchar(' ', space);
	return ((int)(len + space));
}
