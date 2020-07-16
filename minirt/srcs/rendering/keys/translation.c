/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:11:49 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 18:19:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		translation2(int k, t_vec3 *origin)
{
	k == KEY_LEFT ? origin->x -= 1.0 : 0;
	k == KEY_RIGHT ? origin->x += 1.0 : 0;
	k == KEY_P ? origin->z += 1.0 : 0;
	k == KEY_M ? origin->z -= 1.0 : 0;
	k == KEY_UP ? origin->y += 1.0 : 0;
	k == KEY_DOWN ? origin->y -= 1.0 : 0;
}

t_vec3		*object_origin(int k, t_minirt *my_rt)
{
	t_object 	*object;

	object = (t_object *)my_rt->selected;
	if (object->type == SP)
		return (&((t_sphere *)object->content)->origin);
	if (object->type == PL)
		return (&((t_plane *)object->content)->origin);
	if (object->type == SQ)
		return (&((t_square *)object->content)->origin);
	if (object->type == CY)
		return (&((t_cylinder *)object->content)->origin);
	if (object->type == TR)
	{
		translation2(k, &((t_triangle *)object->content)->p1);
		translation2(k, &((t_triangle *)object->content)->p2);
		return (&((t_triangle *)object->content)->p3);
	}
	return (0);
}

t_vec3		*get_origin(int k, t_minirt *my_rt)
{
	int			selected_type;
	t_list		*light;

	selected_type = my_rt->selected_type;
	if (selected_type == 0)
		return (&((t_camera *)(my_rt->scene.selected_cam))->origin);
	if (selected_type == 2)
	{
		light = (t_list *)my_rt->selected;
		return (&((t_light *)light->content)->origin);
	}
	if (selected_type == 1)
		return (object_origin(k, my_rt));
	return (0);
}

void		translation(t_minirt *my_rt, int k)
{
	if (my_rt->selected == NULL)
	{
		ft_printf("no object selected");
		return ;
	}
	translation2(k, get_origin(k, my_rt));
	start_minirt(my_rt);
	mlx_put_image_to_window(my_rt->mlx_ptr, my_rt->win_ptr, my_rt->image.img_ptr, 0, 0);
}