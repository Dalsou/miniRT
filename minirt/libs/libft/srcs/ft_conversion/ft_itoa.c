/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:17:27 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/24 15:21:41 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(size_t nbr, size_t size)
{
	while (nbr >= 10)
	{
		nbr /= 10;
		++size;
	}
	return (size + 1);
}

static char		*get_str(char *str, size_t nbr, size_t size)
{
	size_t i;

	i = size - 1;
	while (nbr >= 10)
	{
		str[i] = (char)(nbr % 10 + '0');
		nbr /= 10;
		i--;
	}
	str[i] = (char)(nbr % 10 + '0');
	str[size] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	nbr;
	size_t	size;

	size = 0;
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		size++;
	}
	size = get_size(nbr, size);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str = get_str(str, nbr, size);
	if (n < 0)
		str[0] = '-';
	return (str);
}
