/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 10:54:08 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 16:09:51 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			to_int(t_color color)
{
	double		red;
	double		green;
	double		blue;

	red = color.red * 256;
	green = color.green * 256;
	blue = color.blue * 256;
	return (((int)red * 256 * 256) + ((int)green * 256) + (int)blue);
}

int			get_color(t_minirt *my_rt, t_ray ray)
{
	t_object	*closest;
	double		t;
	t_color		res;
	t_color		amb;

	ft_bzero(&res, sizeof(t_color));
	t = 0;
	closest = intersect_with_all(my_rt->scene, ray, &t);
	if (closest)
	{
		amb = color_coeff(my_rt->scene.ambient_color,
								my_rt->scene.ambient_intensity);
		res = color_add(color_mult(closest->color, amb),
								shade(my_rt->scene, ray, closest, t));
	}
	return (to_int(res));
}