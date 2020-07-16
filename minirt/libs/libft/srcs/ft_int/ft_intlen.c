/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:19:32 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/10 12:28:04 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(intmax_t nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
		len++;
	if (!nb)
		len++;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}