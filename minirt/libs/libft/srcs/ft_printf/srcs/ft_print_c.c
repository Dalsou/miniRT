/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:52:39 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnchar(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

int		ft_print_c(va_list *args, t_flags *flags)
{
	int c;
	int len;

	c = va_arg(*args, int);
	len = 0;
	if (flags->width == 1 && flags->nb_width > 0)
	{
		len = flags->nb_width;
		if (flags->left == 1)
		{
			ft_putchar(c);
			ft_putnchar(' ', flags->nb_width - 1);
		}
		else
		{
			ft_putnchar(' ', flags->nb_width - 1);
			ft_putchar(c);
		}
	}
	else
	{
		len = 1;
		ft_putchar(c);
	}
	return (len);
}
