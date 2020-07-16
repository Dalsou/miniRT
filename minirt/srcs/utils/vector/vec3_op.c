/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:03:23 by afoulqui          #+#    #+#             */
/*   Updated: 2020/06/29 14:03:49 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		vec3_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3		vec;

	vec.x = v1.x + v2.x;
	vec.y = v1.y + v2.y;
	vec.z = v1.z + v2.z;
	return (vec);
}

t_vec3		vec3_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3		vec;

	vec.x = v1.x - v2.x;
	vec.y = v1.y - v2.y;
	vec.z = v1.z - v2.z;
	return (vec);
}

t_vec3		vec3_mul(t_vec3 v1, double m)
{
	t_vec3		vec;

	vec.x = v1.x * m;
	vec.y = v1.y * m;
	vec.z = v1.z * m;
	return (vec);
}

t_vec3		vec3_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3		vec;

	vec.x = v1.y * v2.z - v1.z * v2.y;
	vec.y = v1.z * v2.x - v1.x * v2.z;
	vec.z = v1.x * v2.y - v1.y * v2.x;
	return (vec);
}

double		vec3_dot(t_vec3 v1, t_vec3 v2)
{
	double		res;

	res = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return (res);
}