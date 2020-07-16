/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:15:23 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/17 17:58:57 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_atof(const char *str)
{
	float	atof;
	int		atoi;
	int		i;
	int		fac;

	fac = 1;
	atof = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	str[i] == '-' ? fac = -1 : 0;
	atoi = ft_atoi(str);
	i = ft_intlen(atoi);
	fac == -1 ? i++ : 0;
	if (str[i] != '.')
		return (atoi);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		fac *= 10;
		atof = atof * 10 + str[i] - 48;
		i++;
	}
	atof = atof / fac;
	return (atoi + atof);
}
