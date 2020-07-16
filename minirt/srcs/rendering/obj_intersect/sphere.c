/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 17:27:13 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 11:45:24 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			sphere_roots(double *t0, double *t1, t_ray ray, t_sphere sphere)
{
	t_vec3	l;
	double	a;
	double	b;
	double	c;

	l = vec3_sub(ray.origin, sphere.origin);
	a = vec3_dot(ray.direction, ray.direction);
	b = 2.0 * vec3_dot(ray.direction, l);
	c = vec3_dot(l, l) - (sphere.radius * sphere.radius);
	if (solve_quadratic(new_qparams(a, b, c), t0, t1) == 0)
		return (0);
	return (1);
}

int			intersect_sphere(t_ray ray, t_sphere sphere, double *t)
{
	double 	t0;
	double 	t1;

	if (sphere_roots(&t0, &t1, ray, sphere) == 0)
		return (0);
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (0);
	}
	*t = t0;
	return (1);
}