/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:33:01 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:52:56 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_prct(va_list *args, t_flags *flags)
{
	int		len;
	int		width;
	char	c;

	args = NULL;
	c = ' ';
	len = 1;
	width = 0;
	if (flags->zero == 1)
		c = '0';
	if (flags->left == 1)
		ft_putchar('%');
	if (flags->width == 1 && flags->nb_width > len)
		width = flags->nb_width - 1;
	ft_putnchar(c, width);
	if (flags->left == 0)
		ft_putchar('%');
	return (width + len);
}
