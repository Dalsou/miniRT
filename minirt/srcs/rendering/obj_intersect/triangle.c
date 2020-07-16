/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:09:44 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 09:57:55 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_edges(t_triangle triangle, t_vec3 p, t_vec3 n)
{
	t_vec3	c;
	t_vec3	edge;
	t_vec3	vp;

	edge = vec3_sub(triangle.p2, triangle.p1);
	vp = vec3_sub(p, triangle.p1);
	c = vec3_cross(edge, vp);
	if (vec3_dot(n, c) < 0)
		return (0);
	edge = vec3_sub(triangle.p3, triangle.p2);
	vp = vec3_sub(p, triangle.p2);
	c = vec3_cross(edge, vp);
	if (vec3_dot(n, c) < 0)
		return (0);
	edge = vec3_sub(triangle.p1, triangle.p3);
	vp = vec3_sub(p, triangle.p3);
	c = vec3_cross(edge, vp);
	if (vec3_dot(n, c) < 0)
		return (0);
	return (1);
}

int			intersect_triangle(t_ray ray, t_triangle triangle, double *t)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	n;
	double	angle;
	t_vec3	p;

	a = vec3_sub(triangle.p2, triangle.p1);
	b = vec3_sub(triangle.p3, triangle.p1);
	n = vec3_cross(a, b);
	n = vec3_norm(n);
	angle = vec3_dot(n, ray.direction);
	if (fabs(angle) < 1e-6)
		return (0);
	*t = (vec3_dot(n, vec3_sub(triangle.p1, ray.origin)) / angle);
	if (*t < 0)
		return (0);
	p = vec3_add(ray.origin, vec3_mul(ray.direction, *t));
	return (check_edges(triangle, p, n));
}