/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:29:27 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 14:53:19 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_line(t_minirt *my_rt)
{
	if (my_rt->split[0] != '\0')
	{
		if (ft_strncmp(my_rt->split[0], "R", 2) == 0)
			parse_resolution(my_rt);
		else if (ft_strncmp(my_rt->split[0], "A", 2) == 0)
			parse_ambient(my_rt);
		else if (ft_strncmp(my_rt->split[0], "c", 2) == 0)
			parse_camera(my_rt);
		else if (ft_strncmp(my_rt->split[0], "l", 2) == 0)
			parse_light(my_rt);
		else if (ft_strncmp(my_rt->split[0], "pl", 2) == 0)
			parse_plane(my_rt);
		else if (ft_strncmp(my_rt->split[0], "sp", 2) == 0)
			parse_sphere(my_rt);
		else if (ft_strncmp(my_rt->split[0], "cy", 2) == 0)
			parse_cylinder(my_rt);
		else if (ft_strncmp(my_rt->split[0], "tr", 2) == 0)
			parse_triangle(my_rt);
		else if (ft_strncmp(my_rt->split[0], "sq", 2) == 0)
			parse_square(my_rt);
		else
			freexit(my_rt, 1, "unknown element in file.");
	}
}

void		*parse_file(char *file, t_minirt *my_rt)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) <= 0)
		freexit(my_rt, 1, "when opening file.");
	while (get_next_line(fd, &my_rt->line) > 0)
	{
		my_rt->split = ft_split_charset(my_rt->line, " \t\v\n\r\f");
		if (my_rt->split == NULL)
			freexit(my_rt, 1, "with malloc when parsing");
		parse_line(my_rt);
		ft_freesplit(my_rt->split);
		my_rt->split = NULL;
		ft_strdel(&my_rt->line);
	}
	my_rt->split = ft_split_charset(my_rt->line, " \t\v\n\r\f");
	if (my_rt->split == NULL)
		freexit(my_rt, 1, "with malloc when parsing");
	parse_line(my_rt);
	ft_freesplit(my_rt->split);
	my_rt->split = NULL;
	ft_strdel(&my_rt->line);
	close(fd);
	return (0);
}