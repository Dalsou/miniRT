/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:36:15 by afoulqui          #+#    #+#             */
/*   Updated: 2020/03/11 12:29:39 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		get_dest_nbr(char const *str, char *charset)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (((i == 0) || (find_charset(str[i - 1], charset) == 1 && i > 0)) &&
			find_charset(str[i], charset) == 0)
			count++;
		i++;
	}
	return (count);
}

static int		get_len(char const *str, char *charset, int i)
{
	int		j;

	j = 0;
	while (str[i] && find_charset(str[i], charset) == 0)
	{
		i++;
		j++;
	}
	return (j);
}

static char	**get_tab(char const *str, char *set, char **tab, int dest_nbr)
{
	int		len;
	int		i;
	int		j;
	int		x;

	len = 0;
	i = 0;
	x = 0;
	while (str[i] && dest_nbr-- > 0)
	{
		while (str[i] && find_charset(str[i], set) == 1)
			i++;
		len = get_len(str, set, i);
		tab[x] = malloc(sizeof(char) * (len + 1));
		if (tab[x] == NULL)
			return (NULL);
		j = 0;
		while (str[i] && j < len)
			tab[x][j++] = str[i++];
		tab[x][j] = '\0';
		x++;
	}
	tab[x] = NULL;
	return (tab);
}

char		**ft_split_charset(const char *str, char *charset)
{
	char	**tab;
	int		dest_nbr;
	char	**empty;

	tab = NULL;
	if (!(empty = malloc(sizeof(char*))))
		return (NULL);
	empty[0] = NULL;
	if (!str[0])
		return (empty);
	if (!(dest_nbr = get_dest_nbr(str, charset)))
		return (empty);
	if (!(tab = malloc(sizeof(char*) * (dest_nbr + 1))))
		return (NULL);
	tab = get_tab(str, charset, tab, dest_nbr);
	return (tab);
}