/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:27:22 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 16:52:50 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		plane_normal(t_plane plane)
{
	t_vec3	res;

	res = plane.direction;
	return (res);
}

t_vec3		sphere_normal(t_vec3 p, t_sphere sphere)
{
	t_vec3	res;

	res = vec3_sub(p, sphere.origin);
	res = vec3_norm(res);
	return (res);
}

t_vec3		cylinder_normal(t_vec3 point, t_cylinder cylinder)
{
	t_vec3	ctp;
	t_vec3	res;

	ctp = vec3_sub(point, cylinder.origin);
	res = vec3_sub(ctp, vec3_mul(cylinder.direction,
				vec3_dot(cylinder.direction, ctp)));
	res = vec3_norm(res);
	return (res);
}

t_vec3		square_normal(t_square square)
{
	t_vec3	res;

	res = square.direction;
	return (res);
}

t_vec3		triangle_normal(t_triangle triangle)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	res;

	a = vec3_sub(triangle.p2, triangle.p1);
	b = vec3_sub(triangle.p3, triangle.p1);
	res = vec3_cross(a, b);
	res = vec3_norm(res);
	return (res);
}