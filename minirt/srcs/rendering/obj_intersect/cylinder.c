/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:23:06 by afoulqui          #+#    #+#             */
/*   Updated: 2020/06/29 14:12:35 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		check_t(double *t, t_cylinder cylinder, t_ray ray)
{
	t_vec3 q;
	t_vec3 p2;

	p2 = vec3_add(cylinder.origin,
			vec3_mul(cylinder.direction, cylinder.height));
	q = vec3_add(ray.origin, vec3_mul(ray.direction, *t));
	if (vec3_dot(cylinder.direction, vec3_sub(q, cylinder.origin)) <= 0)
		*t = -1;
	if (vec3_dot(cylinder.direction, vec3_sub(q, p2)) >= 0)
		*t = -1;
}

int			cy_roots(double *t0, double *t1, t_cylinder cylinder, t_ray ray)
{
	t_vec3	a_sqrt;
	t_vec3	right;
	double	a;
	double	b;
	double	c;

	a_sqrt = vec3_sub(ray.direction,
				vec3_mul(cylinder.direction,
					vec3_dot(ray.direction, cylinder.direction)));
	a = vec3_dot(a_sqrt, a_sqrt);
	right = vec3_sub(vec3_sub(ray.origin, cylinder.origin),
				vec3_mul(cylinder.direction,
					vec3_dot(vec3_sub(ray.origin, cylinder.origin),
						cylinder.direction)));
	b = 2 * vec3_dot(a_sqrt, right);
	c = vec3_dot(right, right) - (cylinder.diameter * cylinder.diameter);
	if (!solve_quadratic(new_qparams(a, b, c), t0, t1))
		return (0);
	return (1);
}

int			intersect_cylinder(t_ray ray, t_cylinder cylinder, double *t)
{
	double t0;
	double t1;

	if (!cy_roots(&t0, &t1, cylinder, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, cylinder, ray);
	if (t1 > 0)
		check_t(&t1, cylinder, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
		if (t1 > 0)
			*t = t1;
		else
			*t = t0;
	else
	{
		if (t0 > 0)
			*t = t0;
		else
			*t = t1;
	}
	return (1);
}