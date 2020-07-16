/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:20:47 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/24 16:53:06 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dest;
	char	*ptr_src;
	size_t	i;

	ptr_dest = (char*)dst;
	ptr_src = (char*)src;
	i = 0;
	if (ptr_src < ptr_dest)
	{
		while (len)
		{
			len--;
			*(ptr_dest + len) = *(ptr_src + len);
		}
	}
	else
	{
		while (i < len)
		{
			*(ptr_dest + i) = *(ptr_src + i);
			i++;
		}
	}
	return (dst);
}
