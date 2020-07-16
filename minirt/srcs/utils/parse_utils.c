/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:09:44 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 15:34:22 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_nb_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int			check_split(char **split)
{
	int i;
	int j;

	i = 1;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]) && split[i][j] != ',' &&
			split[i][j] != '.' && split[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_color		parse_color(t_minirt *my_rt, char *str_color)
{
	t_color		*color;
	char		**tab_color;

	if (!(color = calloc(1, sizeof(t_color))))
		freexit(my_rt, 1, "fail to malloc new color when parsing.");
	tab_color = ft_split(str_color, ',');
	if (check_nb_split(tab_color) != 3)
		freexit(my_rt, 1, "invalid RGB parsing.");
	color->red = ft_atof(tab_color[0]) / 256;
	color->green = ft_atof(tab_color[1]) / 256;
	color->blue = ft_atof(tab_color[2]) / 256;
	if (color->red < 0 || color->red > 1 || color->green < 0 ||
		color->green > 1 || color->blue < 0 || color->blue > 1)
		freexit(my_rt, 1, "invalid RGB parsing.");
	return (*color);
}

t_vec3		parse_vector(t_minirt *my_rt, char *str, int orientation)
{	
	t_vec3		*vector;
	char		**point;

	if (!(vector = calloc(1, sizeof(t_vec3))))
		freexit(my_rt, 1, "fail to malloc new vector when parsing.");
	point = ft_split(str, ',');
	if (check_nb_split(point) != 3)
		freexit(my_rt, 1, "invalid vector parsing");
	vector->x = ft_atof(point[0]);
	vector->y = ft_atof(point[1]);
	vector->z = ft_atof(point[2]);
	if (orientation == 1  && (vector->x > 1 || vector->y > 1 || vector->z > 1 || vector->x < -1 ||
		vector->y < -1 || vector->z < -1))
		freexit(my_rt, 1, "invalid orientation");
	return (*vector);
}