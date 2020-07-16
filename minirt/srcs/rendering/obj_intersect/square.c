/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:18:49 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 18:39:33 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			intersect_square(t_ray ray, t_square square, double *t)
{
	double	a;
	double	b;
	double	t1;
	double	t2;
	t_vec3	d;

	a = vec3_dot(vec3_sub(ray.origin, square.origin), square.direction);
	b = vec3_dot(ray.direction, square.direction);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t1 = -a / b;
	d = vec3_sub(vec3_add(vec3_mul(ray.direction,
					t1), ray.origin), square.origin);
	t2 = square.height / 2;
	if (fabs(d.x) > t2 || fabs(d.y) > t2 || fabs(d.z) > t2)
		return (0);
	if (t1 > 0)
		*t = t1;
	return (1);
}