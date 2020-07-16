/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:51:31 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 15:39:47 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_printf(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup_printf(const char *s1)
{
	char		*new;
	int			i;
	int			size;

	if (!s1)
		return (NULL);
	size = ft_strlen((char *)s1);
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strndup(const char *s1, int n)
{
	char		*new;
	int			i;
	int			size;

	if (!s1)
		return (NULL);
	size = ft_strlen((char *)s1);
	if (n < size)
		size = n;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < size)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
