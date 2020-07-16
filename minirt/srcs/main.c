/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:03:11 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 18:03:53 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_arg(int argc, char **argv, int *save)
{
	int			i;

	if (argc < 2 || argc > 3)
		return (1);
	i = 0;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (!argv[1][i] || i < 3 || ft_strncmp(&argv[1][i], ".rt", 3) != 0)
		return (1);
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "-save", ft_strlen(argv[2])) == 0)
			*save = 1;
		else 
			return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int			save;
	t_minirt	my_rt;
	t_scene		scene;

	save = 0;

	ft_bzero(&my_rt, sizeof(t_minirt));
	ft_bzero(&scene, sizeof(t_scene));
	my_rt.scene = scene;
	if (check_arg(argc, argv, &save) == 1)
		freexit(&my_rt, 1, "wrong argument");
	if (save == 1)
		my_rt.save = 1;
	parse_file(argv[1], &my_rt);
	start_minirt(&my_rt);
	return (0);
}