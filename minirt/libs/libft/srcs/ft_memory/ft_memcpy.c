/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:05:42 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/29 10:49:15 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char*)dst;
	ptr_src = (unsigned const char*)src;
	while (n > 0)
	{
		*ptr_dest = *ptr_src;
		n--;
		ptr_dest++;
		ptr_src++;
	}
	return (dst);
}
