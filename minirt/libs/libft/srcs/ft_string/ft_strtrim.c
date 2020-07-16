/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:38:13 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/29 14:45:16 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_set(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1 && find_set(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end >= start && find_set(s1[end - 1], set) == 1)
		end--;
	if (!end && !start)
		return (ft_calloc(1, sizeof(s1)));
	str = ft_substr(s1, start, end - start);
	return (str);
}
