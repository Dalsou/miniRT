/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:37:29 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 16:50:17 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		get_norm(t_vec3 p, t_object *object)
{
	if (object->type == SP)
		return (sphere_normal(p, *(t_sphere *)object->content));
	if (object->type == PL)
		return (plane_normal(*(t_plane *)object->content));
	if (object->type == SQ)
		return (square_normal(*(t_square *)object->content));
	if (object->type == TR)
		return (triangle_normal(*(t_triangle *)object->content));
	else
		return (cylinder_normal(p, *(t_cylinder *)object->content));
}