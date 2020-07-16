/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:39:01 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:52:27 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_index(char *str, char element)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_find_end(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int		ft_find_nb(char *str, va_list *list)
{
	int		nb;
	int		i;
	int		neg;

	nb = 0;
	i = 0;
	neg = 1;
	if (str[i] == '*')
	{
		nb = va_arg(*list, int);
		return (nb);
	}
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (ft_find_index("0123456789", str[i]) != -1)
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * neg);
}
