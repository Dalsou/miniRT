/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 15:21:14 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 16:59:18 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		mix_colors(t_light light, double coeff, t_ray_res ray_res,
						t_vec3 origin)
{
	t_color		result;
	t_color		light_color;
	t_color		tmp;

	tmp = light.color;
	light_color = color_coeff(tmp, light.intensity);
	result = color_coeff(color_mult(light_color, ray_res.color), coeff);
	if (coeff)
		result = color_add(result, specular(light,
					ray_res, origin));
	return (result);
}

t_color		get_light(t_light light, t_scene scene, t_ray_res ray_res,
						t_vec3 origin)
{
	double		t;
	t_vec3		light_ray;
	t_ray		lray;
	double		coeff;

	coeff = 0;
	light_ray = vec3_sub(light.origin, ray_res.hit_point);
	light_ray = vec3_norm(light_ray);
	lray.origin = vec3_add(ray_res.hit_point, vec3_mul(ray_res.hit_normal, 0.1));
	lray.direction = light_ray;
	if (!intersect_with_all(scene, lray, &t)
			|| t > vec3_len(vec3_sub(light.origin, ray_res.hit_point)))
		coeff = fmax(0, vec3_dot(ray_res.hit_normal, light_ray));
	return (mix_colors(light, coeff, ray_res, origin));
}

t_color		shade(t_scene scene, t_ray ray, t_object *object, double t)
{
	t_ray_res	ray_res;
	t_color 	addition;
	t_color 	result;
	t_list 		*light;

	ft_bzero(&result, sizeof(t_color));
	ray_res.color = object->color;
	ray_res.hit_point = vec3_mul(ray.direction, t);
	ray_res.hit_point = vec3_add(ray.origin, ray_res.hit_point);
	ray_res.hit_normal = get_norm(ray_res.hit_point, object);
	if (vec3_dot(ray.direction, ray_res.hit_normal) > 0)
		ray_res.hit_normal = vec3_invert(ray_res.hit_normal);
	light = scene.light_lst;
	while (light)
	{
		addition = get_light(*(t_light *)(light->content),
				scene, ray_res, ray.origin);
		result = color_add(result, addition);
		light = light->next;
	}
	return (result);
}