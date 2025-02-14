/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:01:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/06/29 14:06:29 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		swap_doubles(double *a, double *b)
{
	double 	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

t_vec3		new_qparams(double a, double b, double c)
{
	t_vec3 	params;

	params.x = a;
	params.y = b;
	params.z = c;
	return (params);
}

int		solve_quadratic(t_vec3 params, double *x0, double *x1)
{
	double 	discr;
	double 	q;

	discr = pow(params.y, 2) - 4 * params.x * params.z;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * params.y / params.x;
		*x1 = -0.5 * params.y / params.x;
	}
	else
	{
		if (params.y > 0)
			q = -1 * (params.y + sqrt(discr)) / 2;
		else
			q = -1 * (params.y - sqrt(discr)) / 2;
		*x0 = q / params.x;
		*x1 = params.z / q;
	}
	if (*x0 > *x1)
		swap_doubles(x0, x1);
	return (1);
}