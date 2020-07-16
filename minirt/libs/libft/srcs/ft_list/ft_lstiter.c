/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:01:01 by afoulqui          #+#    #+#             */
/*   Updated: 2019/10/25 17:23:58 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	t_list	*current;

	tmp = NULL;
	current = lst;
	while (current && lst && f)
	{
		if (current->next)
			tmp = current->next;
		else
			tmp = NULL;
		f(current->content);
		current = tmp;
	}
}
