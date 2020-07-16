/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 15:41:13 by afoulqui          #+#    #+#             */
/*   Updated: 2020/06/29 14:10:11 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			intersect_plane(t_ray ray, t_plane plane, double *t)
{
	double	denom;
	t_vec3	p0l0;

	denom = vec3_dot(plane.direction, ray.direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = vec3_sub(plane.origin, ray.origin);
		*t = vec3_dot(p0l0, plane.direction) / denom;
		return (*t >= 0);
	}
	return (0);
}