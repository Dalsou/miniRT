/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:38:16 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/29 14:50:29 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_dest_nbr(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (((i == 0) || (s[i - 1] == c && i > 0)) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int		get_len(char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static char		**free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char		**get_tab(char const *s, char c, char **tab, int dest_nbr)
{
	int len;
	int i;
	int j;
	int x;

	len = 0;
	i = 0;
	x = 0;
	while (s[i] && dest_nbr-- > 0)
	{
		while (s[i] && s[i] == c)
			i++;
		len = get_len(s, c, i);
		tab[x] = malloc(sizeof(char) * (len + 1));
		if (tab[x] == NULL)
			return (free_tab(tab, x));
		j = 0;
		while (s[i] && j < len)
			tab[x][j++] = s[i++];
		tab[x][j] = '\0';
		x++;
	}
	tab[x] = NULL;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		dest_nbr;

	if (!s)
		return (NULL);
	dest_nbr = get_dest_nbr(s, c);
	tab = malloc(sizeof(char *) * (dest_nbr + 1));
	if (tab == NULL)
		return (NULL);
	tab = get_tab(s, c, tab, dest_nbr);
	return (tab);
}
