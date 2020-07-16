/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:23:20 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/16 11:21:29 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_new(char *dst, char const *s2, unsigned int i, char *tmp)
{
	size_t			len;
	unsigned int	j;

	len = ft_strlen(tmp);
	j = 0;
	while (j < len)
	{
		dst[i] = tmp[j];
		i++;
		j++;
	}
	if (tmp == s2)
	{
		dst[i] = '\0';
		return (dst);
	}
	return (fill_new(dst, s2, i, (char *)s2));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	size_t			size;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	fill_new(new, s2, i, (char *)s1);
	return (new);
}
