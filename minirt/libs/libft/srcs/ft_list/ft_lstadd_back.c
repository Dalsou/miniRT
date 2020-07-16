/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:15:11 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/29 15:06:04 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst && new)
	{
		last = *alst;
		new->next = NULL;
		if (*alst == NULL)
			*alst = new;
		else
		{
			while (last->next && alst && new)
				last = last->next;
			last->next = new;
		}
	}
}
