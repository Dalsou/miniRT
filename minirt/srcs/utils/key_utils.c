/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:49:35 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 18:20:55 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		*lst_find2(t_minirt *my_rt)
{
	int			i;
	t_object	*lst;
	t_object	*res;

	i = 0;
	lst = my_rt->scene.objects;
	res = lst;
	while (lst && i < my_rt->selected_index)
	{
		lst = lst->next;
		res = lst;
		i++;
	}
	if (lst == NULL)
	{
		my_rt->selected_index = 0;
		res = my_rt->scene.objects;
	}
	return (res);
}

void		*lst_find(t_minirt *my_rt, t_list *lst)
{
	int			i;
	t_list		*curr;
	t_list		*res;

	i = 0;
	curr = lst;
	res = lst;
	while (curr && i < my_rt->selected_index)
	{
		curr = curr->next;
		res = curr;
		i++;
	}
	if (curr == NULL)
	{
		my_rt->selected_index = 0;
		res = lst;
	}
	return (res);
}