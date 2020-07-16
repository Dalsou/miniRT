/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:56:54 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 12:07:18 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		intersect_obj(t_ray ray, t_object *obj, double *t)
{
	if (obj->type == SP)
		return (intersect_sphere(ray, *(t_sphere *)obj->content, t));
	if (obj->type == PL)
		return (intersect_plane(ray, *(t_plane *)obj->content, t));
	if (obj->type == TR)
		return (intersect_triangle(ray, *(t_triangle *)obj->content, t));
	if (obj->type == SQ)
		return (intersect_square(ray, *(t_square *)obj->content, t));
	if (obj->type == CY)
		return (intersect_cylinder(ray, *(t_cylinder *)obj->content, t));
	return (0);
}

t_object	*intersect_with_all(t_scene scene, t_ray ray, double *t_min)
{
	t_object	*objects;
	t_object	*closest;
	double		t;

	closest = NULL;
	objects = scene.objects;
	*t_min = INFINITY;
	while (objects != NULL)
	{
		if (intersect_obj(ray, objects, &t))
		{
			if (t < *t_min)
			{
				*t_min = t;
				closest = objects;
			}
		}
		objects = objects->next;
	}
	return (closest);
}