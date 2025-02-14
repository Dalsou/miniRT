/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:55:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/10 11:58:38 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\t' || c == '\n' || c == '\r' ||
		c == '\v')
		return (1);
	return (0);
}
