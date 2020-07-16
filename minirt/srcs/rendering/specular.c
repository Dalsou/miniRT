/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:55:39 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 16:40:22 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		spec_coeff(t_light light, t_vec3 hit_point,
						t_vec3 hit_norm, t_vec3 origin)
{
	t_vec3		light_ray;
	t_vec3		reflectance_vector;
	t_vec3		back_view_ray;
	double		result;

	light_ray = vec3_sub(light.origin, hit_point);
	light_ray = vec3_norm(light_ray);
	reflectance_vector = vec3_add(light_ray,
							vec3_mul(vec3_mul(hit_norm,
								vec3_dot(light_ray, hit_norm)), -2));
	back_view_ray = vec3_sub(hit_point, origin);
	back_view_ray = vec3_norm(back_view_ray);
	result = fmax(vec3_dot(reflectance_vector, back_view_ray), 0);
	result = pow(result, 10);
	return (result);
}

t_color		specular(t_light light, t_ray_res ray_res, t_vec3 origin)
{
	t_color		specular;
	t_color		highlight;
	t_color		res;
	double		metalness;
	double		coeff;

	metalness = 0.1;
	highlight.red = 1;
	highlight.green = 1;
	highlight.blue = 1;
	highlight = color_coeff(highlight, (1 - metalness));
	specular = color_add(
			color_coeff(ray_res.color, metalness),
			highlight);
	coeff = spec_coeff(light, ray_res.hit_point, ray_res.hit_normal, origin);
	res = color_coeff(specular, coeff);
	return (res);
}