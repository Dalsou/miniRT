/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:34:41 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 18:18:36 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		type(t_minirt *my_rt)
{
	if (my_rt->selected_type < 2)
		my_rt->selected_type++;
	else if (my_rt->selected_type > 1)
		my_rt->selected_type = 0;
	my_rt->selected_type == 0 ? ft_printf("Cameras") : 0;
	my_rt->selected_type == 1 ? ft_printf("Shapes") : 0;
	my_rt->selected_type == 2 ? ft_printf("Lights") : 0;
	my_rt->selected_index = 0;
	if (my_rt->selected_type == 0)
		my_rt->selected = lst_find(my_rt, my_rt->scene.cam_lst);
	else if (my_rt->selected_type == 1)
		my_rt->selected = lst_find2(my_rt);
	else if (my_rt->selected_type == 2)
		my_rt->selected = lst_find(my_rt, my_rt->scene.light_lst);
}

void		next_obj(t_minirt *my_rt)
{
	my_rt->selected_index++;
	if (my_rt->selected_type == 0)
		my_rt->selected = lst_find(my_rt, my_rt->scene.cam_lst);
	if (my_rt->selected_type == 1)
		my_rt->selected = lst_find2(my_rt);
	if (my_rt->selected_type == 2)
		my_rt->selected = lst_find(my_rt, my_rt->scene.light_lst);
}

void		next_cam(t_minirt *my_rt)
{
	int			i;
	t_list		*lst;
	t_list		*res;

	i = 0;
	my_rt->scene.cam_index += 1;
	lst = my_rt->scene.cam_lst;
	res = lst;
	while (lst && i < my_rt->scene.cam_index)
	{
		lst = lst->next;
		res = lst;
		i++;
	}
	if (lst == NULL)
	{
		my_rt->scene.cam_index = 0;
		res = my_rt->scene.cam_lst;
	}
	my_rt->scene.selected_cam = res->content;
	send_rays(my_rt);
	mlx_put_image_to_window(my_rt->mlx_ptr, my_rt->win_ptr,
								my_rt->image.img_ptr, 0, 0);
}

int			key_hook(int k, t_minirt *my_rt)
{
	if (k == KEY_ESC)
		close_rt(my_rt);
	if (k == KEY_T)
		type(my_rt);
	if (k == KEY_N)
		next_obj(my_rt);
	if (k == KEY_LEFT || k == KEY_UP || k == KEY_DOWN
			|| k == KEY_RIGHT || k == KEY_P || k == KEY_M)
		translation(my_rt, k);
	if (k == KEY_Q || k == KEY_Z || k == KEY_S ||
			k == KEY_D || k == KEY_A || k == KEY_E)
		rotation(my_rt, k);
	if (k == KEY_C)
		next_cam(my_rt);
	return (1);
}