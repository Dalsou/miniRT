/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:53:41 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/24 17:01:44 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;
	size_t		i;

	ptr_dest = (char*)dst;
	ptr_src = (const char*)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		if (ptr_dest[i] == (char)c)
			return ((void*)(dst + 1 + i));
		i++;
	}
	return (NULL);
}
