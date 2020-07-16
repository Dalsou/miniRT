/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:06:13 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 15:17:45 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		color_coeff(t_color color , double coeff)
{
	t_color		res;

	res.red = fmin(color.red * coeff, 1);
	res.green = fmin(color.green * coeff, 1);
	res.blue = fmin(color.blue * coeff, 1);
	return (res);
}

t_color		color_add(t_color c1, t_color c2)
{
	t_color		res;

	res.red = fmin(c1.red + c2.red, 0.99);
	res.green = fmin(c1.green + c2.green, 0.99);
	res.blue = fmin(c1.blue + c2.blue, 0.99);
	return (res);
}

t_color		color_mult(t_color c1, t_color c2)
{
	t_color		res;

	res.red = fmin(c1.red * c2.red, 1);
	res.green = fmin(c1.green * c2.green, 1);
	res.blue = fmin(c1.blue * c2.blue, 1);
	return (res);
}