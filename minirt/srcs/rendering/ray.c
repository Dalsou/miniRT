/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:40:57 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 12:08:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	look_at(t_vec3 origin, t_vec3 direction, t_vec3 tmp)
{
	t_matrix	c2w;
	t_vec3		forward;
	t_vec3		right;
	t_vec3		up;

	forward = direction;
	tmp = vec3_norm(tmp);
	right = vec3_cross(tmp, forward);
	right = vec3_norm(right);
	up = vec3_cross(forward, right);
	up = vec3_norm(up);
	c2w.right = vec3_new(right.x, right.y, right.z);
	c2w.up = vec3_new(up.x, up.y, up.z);
	c2w.forward = vec3_new(forward.x, forward.y, forward.z);
	c2w.translation = vec3_new(origin.x, origin.y, origin.z);
	return (c2w);
}

t_vec3		multi_vec_matrix(t_vec3 vec, t_matrix matrix)
{
	t_vec3		res;

	res.x = vec.x * matrix.right.x + vec.y * matrix.up.x + vec.z *
		matrix.forward.x + matrix.translation.x;
	res.y = vec.x * matrix.right.y + vec.y * matrix.up.y + vec.z *
		matrix.forward.y + matrix.translation.y;
	res.z = vec.x * matrix.right.z + vec.y * matrix.up.z + vec.z *
		matrix.forward.z + matrix.translation.z;
	return (res);
}

void		check_direction(t_vec3 *direction, t_vec3 ray_direction)
{
	if (direction->x != 0 || direction->y != 0 || direction->z != 0)
		return ;
	direction->x = - ray_direction.x + 0.1;
	direction->y = - ray_direction.y + 0.1;
	direction->z = - ray_direction.z + 0.1;
	*direction = vec3_norm(*direction);
}

t_vec3		get_direction(int x, int y, t_scene scene, t_camera cam)
{
	t_vec3		direction;
	double 		fov_coeff;
	double 		aspr;
	double 		px;
	double 		py;

	fov_coeff = tan((double)cam.fov / 3 / 2 * M_PI / 180);
	aspr = (double)scene.width / (double)scene.height;
	px = (2 * (x + 0.5) / (double)scene.width - 1) * aspr * fov_coeff;
	py = (1 - 2 * (y + 0.5) / (double)scene.height) * fov_coeff;
	direction = vec3_new(px, py, 1);
	return (direction);
}

t_ray		get_ray(int x, int y, t_scene scene, t_camera cam)
{
	t_ray		ray;
	t_matrix	c2w;
	t_vec3		direction;
	t_vec3		tmp;

	direction = get_direction(x, y, scene, cam);
	tmp = vec3_new(0, 1, 0);
	tmp = (fabs(cam.direction.y) == 0) ? (t_vec3){0, 1, 0} : (t_vec3){0, 0, -1};
	check_direction(&cam.direction, cam.origin);
	c2w = look_at(cam.origin, cam.direction, tmp);
	direction = multi_vec_matrix(direction, c2w);
	direction = vec3_sub(direction, cam.origin);
	direction = vec3_norm(direction);
	ray.origin = cam.origin;
	ray.direction = direction;
	return (ray);
}