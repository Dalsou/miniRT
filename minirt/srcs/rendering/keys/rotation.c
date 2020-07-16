/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:51:44 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 18:18:50 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rot(double *sx, double *sy)
{
	double rad;
	double x;
	double y;

	rad = 90 * M_PI / 180;
	x = *sx * cos(rad) + *sy * sin(rad);
	y = -*sx * sin(rad) + *sy * cos(rad);
	*sx = x;
	*sy = y;
}

void		rot_sp(t_sphere *sphere, int k)
{
	if (k == KEY_Q)
		rot(&sphere->origin.y, &sphere->origin.x);
	else if (k == KEY_D)
		rot(&sphere->origin.x, &sphere->origin.y);
	else if (k == KEY_Z)
		rot(&sphere->origin.y, &sphere->origin.z);
	else if (k == KEY_S)
		rot(&sphere->origin.z, &sphere->origin.y);
	else if (k == KEY_A)
		rot(&sphere->origin.x, &sphere->origin.z);
	else if (k == KEY_E)
		rot(&sphere->origin.z, &sphere->origin.x);
}

void		rot_cy(t_vec3 *origin, int k)
{
	if (k == KEY_Q)
		rot(&origin->y, &origin->x);
	else if (k == KEY_D)
		rot(&origin->x, &origin->y);
	else if (k == KEY_Z)
		rot(&origin->y, &origin->z);
	else if (k == KEY_S)
		rot(&origin->z, &origin->y);
	else if (k == KEY_A)
		rot(&origin->x, &origin->z);
	else if (k == KEY_E)
		rot(&origin->z, &origin->x);
}

void		rotation(t_minirt *my_rt, int k)
{
	int				sel_type;
	t_object		*object;

	sel_type = my_rt->selected_type;
	if (sel_type == 0)
		rot_sp((t_sphere *)((t_camera *)my_rt->scene.selected_cam), k);
	if (sel_type == 1)
	{
		object = (t_object *)my_rt->selected;
		if (object->type == SP)
			rot_sp((t_sphere *)object->content, k);
		if (object->type == PL || object->type == CY)
		{
			rot_cy(&((t_cylinder *)object->content)->origin, k);
			rot_cy(&((t_cylinder *)object->content)->direction, k);
		}
		if (object->type == SQ)
			rot_cy(&((t_cylinder *)object->content)->origin, k);
	}
	send_rays(my_rt);
	mlx_put_image_to_window(my_rt->mlx_ptr, my_rt->win_ptr,
								my_rt->image.img_ptr, 0, 0);
}