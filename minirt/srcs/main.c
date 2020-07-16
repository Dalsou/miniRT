/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:03:11 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 14:43:09 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		check_arg(int argc, char **argv, t_minirt *my_rt)
{
	int			i;

	if (argc < 2 || argc > 3)
		freexit(my_rt, 1, "too much or too few arguments.");
	i = 0;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (!argv[1][i] || i < 3 || ft_strncmp(&argv[1][i], ".rt", 3) != 0)
		freexit(my_rt, 1, "in file arguments.");
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "-save", ft_strlen(argv[2])) == 0)
			my_rt->save = 1;
		else 
			freexit(my_rt, 1, "in saving argument.");
	}
}

int			main(int argc, char **argv)
{
	t_minirt	my_rt;
	t_scene		scene;

	ft_bzero(&my_rt, sizeof(t_minirt));
	ft_bzero(&scene, sizeof(t_scene));
	my_rt.scene = scene;
	check_arg(argc, argv, &my_rt);
	parse_file(argv[1], &my_rt);
	start_minirt(&my_rt);
	return (0);
}