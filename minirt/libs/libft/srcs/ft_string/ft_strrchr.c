/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:46:14 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/25 11:02:28 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*str;

	len = ft_strlen((char *)s);
	str = (unsigned char *)s;
	if (!s)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)s + len);
	while (len--)
	{
		if (*(str + len) == c)
			return ((char *)(str + len));
	}
	return (NULL);
}
