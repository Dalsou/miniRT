/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:12:47 by afoulqui          #+#    #+#             */
/*   Updated: 2020/06/29 14:03:21 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		vec3_new(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double		vec3_len(t_vec3 vec)
{
	double	res;

	res = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (res);
}

t_vec3		vec3_div(t_vec3 v1, double d)
{
	t_vec3		vec;

	vec.x = v1.x / d;
	vec.y = v1.y / d;
	vec.z = v1.z / d;
	return (vec);
}

t_vec3		vec3_norm(t_vec3 vec)
{
	double 	len;
	t_vec3	res;

	len = vec3_len(vec);
	res = vec3_div(vec, len);
	return (res);
}

t_vec3		vec3_invert(t_vec3 vec)
{
	t_vec3	res;

	res.x = -1 * vec.x;
	res.y = -1 * vec.y;
	res.z = -1 * vec.z;
	return (res);
}