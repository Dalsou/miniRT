/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:22:11 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 15:31:54 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_plane(t_minirt *my_rt)
{
    t_plane		*plane;

	if (check_nb_split(my_rt->split) != 4 || !check_split(my_rt->split))
		freexit(my_rt, 1, "with plane parameters.");
	if (!(plane = calloc(1, sizeof(t_plane))))
		freexit(my_rt, 1, "when malloc new plane in parsing.");
	plane->origin = parse_vector(my_rt, my_rt->split[1], 0);
	plane->direction = parse_vector(my_rt, my_rt->split[2], 1);
	plane->color = parse_color(my_rt, my_rt->split[3]);
	plane->direction = vec3_norm(plane->direction);
	lstadd_back_obj(&my_rt->scene.objects, lstnew_obj(plane, PL,
						plane->color));
}

void		parse_sphere(t_minirt *my_rt)
{
	t_sphere	*sphere;

	if (check_nb_split(my_rt->split) != 4 || !check_split(my_rt->split))
		freexit(my_rt, 1, "with sphere parameters.");
	if (!(sphere = calloc(1, sizeof(t_sphere))))
		freexit(my_rt, 1, "when malloc new sphere in parsing.");
	sphere->origin = parse_vector(my_rt, my_rt->split[1], 0);
	sphere->radius = ft_atof(my_rt->split[2]) / 2;
	sphere->color = parse_color(my_rt, my_rt->split[3]);
	lstadd_back_obj(&my_rt->scene.objects, lstnew_obj(sphere, SP,
						sphere->color));
}

void		parse_cylinder(t_minirt *my_rt)
{
	t_cylinder	*cylinder;

	if (check_nb_split(my_rt->split) != 6 || !check_split(my_rt->split))
		freexit(my_rt, 1, "with cylinder parameters.");
	if (!(cylinder = calloc(1, sizeof(t_cylinder))))
		freexit(my_rt, 1, "when malloc new cylinder in parsing.");
	cylinder->origin = parse_vector(my_rt, my_rt->split[1], 0);
	cylinder->direction = parse_vector(my_rt, my_rt->split[2], 1);
	cylinder->diameter = ft_atof(my_rt->split[3]);
	cylinder->height = ft_atof(my_rt->split[4]);
	cylinder->color = parse_color(my_rt, my_rt->split[5]);
	cylinder->direction = vec3_norm(cylinder->direction);
	lstadd_back_obj(&my_rt->scene.objects, lstnew_obj(cylinder, CY,
						cylinder->color));
}

void		parse_square(t_minirt *my_rt)
{
	t_square	*square;

	if (check_nb_split(my_rt->split) != 5 || !check_split(my_rt->split))
		freexit(my_rt, 1, "with square parameters.");
	if (!(square = calloc(1, sizeof(t_square))))
		freexit(my_rt, 1, "when malloc new square in parsing.");
	square->origin = parse_vector(my_rt, my_rt->split[1], 0);
	square->direction = parse_vector(my_rt, my_rt->split[2], 1);
	square->height = ft_atof(my_rt->split[3]);
	square->color = parse_color(my_rt, my_rt->split[4]);
	square->direction = vec3_norm(square->direction);
	lstadd_back_obj(&my_rt->scene.objects, lstnew_obj(square, SQ,
						square->color));
}

void		parse_triangle(t_minirt *my_rt)
{
	t_triangle	*triangle;

	if (check_nb_split(my_rt->split) != 5 || !check_split(my_rt->split))
		freexit(my_rt, 1, "with triangle parameters.");
	if (!(triangle = calloc(1, sizeof(t_triangle))))
		freexit(my_rt, 1, "when malloc new triangle in parsing.");
	triangle->p1 = parse_vector(my_rt, my_rt->split[1], 0);
	triangle->p2 = parse_vector(my_rt, my_rt->split[2], 0);
	triangle->p3 = parse_vector(my_rt, my_rt->split[3], 0);
	triangle->color = parse_color(my_rt, my_rt->split[4]);
	lstadd_back_obj(&my_rt->scene.objects, lstnew_obj(triangle, TR,
						triangle->color));
}