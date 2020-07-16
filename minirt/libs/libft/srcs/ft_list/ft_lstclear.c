/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:09:08 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/25 17:23:23 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	current = *lst;
	tmp = NULL;
	while (current && lst && del)
	{
		if (current->next)
			tmp = current->next;
		else
			tmp = NULL;
		del(current->content);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
