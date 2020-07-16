/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:29:46 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/24 16:57:35 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t len)
{
	size_t	total;
	void	*ptr;

	total = count * len;
	ptr = (void *)malloc(total);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, 0, total));
}
