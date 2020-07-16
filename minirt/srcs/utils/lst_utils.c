/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:22:38 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 18:52:44 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		lstadd_back_obj(t_object **alst, t_object *new)
{
	t_object	*last;

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

t_object	*lstnew_obj(void *content, int type, t_color color)
{
	t_object	*element;

	element = (t_object *)malloc(sizeof(*element));
	if (element)
	{
		element->type = type;
		element->color = color;
		element->content = content;
		element->next = NULL;
	}
	return (element);
}

void	lstclear_rt(t_list **lst)
{
	t_list		*current;
	t_list		*tmp;

	current = *lst;
	tmp = NULL;
	while (current && lst)
	{
		if (current->next)
			tmp = current->next;
		else
			tmp = NULL;
		free(current->content);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}