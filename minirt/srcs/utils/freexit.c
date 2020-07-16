/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freexit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 13:56:27 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 18:55:23 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clear_objects(t_object **lst)
{
	t_object	*current;
	t_object	*tmp;

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
	current = NULL;
}

void		free_everything(t_minirt *my_rt)
{
	if (my_rt->split)
		ft_freesplit(my_rt->split);
	if (my_rt->scene.cam_lst)
		lstclear_rt(&my_rt->scene.cam_lst);
	if (my_rt->scene.light_lst)
		lstclear_rt(&my_rt->scene.light_lst);
	if (my_rt->scene.objects)
		clear_objects(&my_rt->scene.objects);
}

int			close_rt(t_minirt *my_rt)
{
	mlx_destroy_image(my_rt->mlx_ptr, my_rt->image.img_ptr);
	mlx_clear_window(my_rt->mlx_ptr, my_rt->win_ptr);
	mlx_destroy_window(my_rt->mlx_ptr, my_rt->win_ptr);
	free_everything(my_rt);
	exit(EXIT_SUCCESS);
	return (1);
}

void		close_rt2(t_minirt *my_rt)
{
	mlx_destroy_image(my_rt->mlx_ptr, my_rt->image.img_ptr);
	free_everything(my_rt);
	exit(EXIT_SUCCESS);
}

void		freexit(t_minirt *my_rt, int error, char *error_msg)
{
	error ? ft_putstr("\nError : ") : 0;
	ft_putstr(error_msg);
	ft_putstr("\n");
	free_everything(my_rt);
	exit(EXIT_FAILURE);
}