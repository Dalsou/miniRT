/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:46:37 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/24 17:02:38 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dsize)
		i++;
	while (src[j] && (i + j + 1) < dsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dsize)
		dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}
