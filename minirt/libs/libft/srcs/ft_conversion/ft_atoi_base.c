/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:36:32 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/23 17:50:37 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi_base(char *str, char *base)
{
	int			i;
	long int	res;
	int			neg;
	int			base_len;

	i = 0;
	res = 0;
	neg = 0;
	base_len = ft_strlen(base);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (ft_isinstr(base, str[i]) >= 0)
	{
		res = res * base_len + str[i];
		i++;
	}
	return (neg ? -res : res);
}