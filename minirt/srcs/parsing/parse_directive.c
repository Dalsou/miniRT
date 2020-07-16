/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_directive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:59:35 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 12:31:49 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_resolution(t_minirt *my_rt)
{
	if (my_rt->scene.width != 0 || my_rt->scene.height != 0)
		freexit(my_rt, 1, "error with resolution");
	if (check_nb_split(my_rt->split) != 3  || !check_split(my_rt->split))
		freexit(my_rt, 1, "error with resolution args");
	my_rt->scene.width = ft_atoi(my_rt->split[1]);
	if (my_rt->scene.width > 2560)
		my_rt->scene.width = 2560;
	my_rt->scene.height = ft_atoi(my_rt->split[2]);
	if (my_rt->scene.height > 1440)
		my_rt->scene.height = 1440;
	if (my_rt->scene.width < 1 || my_rt->scene.height < 1)
		freexit(my_rt, 1, "error with resolution args");
}

void		parse_ambient(t_minirt *my_rt)
{
	if (check_nb_split(my_rt->split) != 3 || !check_split(my_rt->split))
		freexit(my_rt, 1, "error with ambient args");
	my_rt->scene.ambient_intensity = ft_atof(my_rt->split[1]);
	if (my_rt->scene.ambient_intensity > 1 || my_rt->scene.ambient_intensity < 0)
		freexit(my_rt, 1, "error with ambient args");
	my_rt->scene.ambient_color = parse_color(my_rt, my_rt->split[2]);
}

void		parse_camera(t_minirt *my_rt)
{	
	t_camera	*camera;

	if (check_nb_split(my_rt->split) != 4 || !check_split(my_rt->split))
		freexit(my_rt, 1, "error with camera args");
	if (!(camera = ft_calloc(1, sizeof(t_camera))))
		freexit(my_rt, 1, "error with camera args");
	camera->origin = parse_vector(my_rt, my_rt->split[1], 0);
	camera->direction = parse_vector(my_rt, my_rt->split[2], 1);
	camera->fov = ft_atoi(my_rt->split[3]);
	ft_lstadd_back(&my_rt->scene.cam_lst, ft_lstnew(camera));
}

void		parse_light(t_minirt *my_rt)
{
	t_light		*light;

	if (check_nb_split(my_rt->split) != 4 || !check_split(my_rt->split))
		freexit(my_rt, 1, "error with light args");
	if (!(light = ft_calloc(1, sizeof(t_light))))
		freexit(my_rt, 1, "error with light args");
	light->origin = parse_vector(my_rt, my_rt->split[1], 0);
	light->intensity = ft_atof(my_rt->split[2]);
	if (light->intensity > 1 || light->intensity < 0)
		freexit(my_rt, 1, "error with light args");
	light->color = parse_color(my_rt, my_rt->split[3]);
	ft_lstadd_back(&my_rt->scene.light_lst, ft_lstnew(light));
}