/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:28:22 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/10 17:48:17 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		send_rays(t_minirt *my_rt)
{
	int			x;
	int			y;
	int			*img;
	t_camera	camera;

	img = (int *)my_rt->image.addr;
	y = 0;
	while (y < my_rt->scene.height)
	{
		x = 0;
		while (x < my_rt->scene.width)
		{
			camera = *((t_camera *)my_rt->scene.selected_cam);
			img[y * my_rt->scene.width + x] = get_color(my_rt,
				get_ray(x, y, my_rt->scene, camera));
			x++;
		}
		y++;
	}
}

void		init_minirt(t_minirt *my_rt)
{
	t_image		image;

	ft_bzero(&image, sizeof(t_image));
	my_rt->image = image;
	if (!(my_rt->mlx_ptr = mlx_init()))
		freexit(my_rt, 1, "init error");
	if (!my_rt->save)
	{
		my_rt->win_ptr = mlx_new_window(my_rt->mlx_ptr,
			my_rt->scene.width, my_rt->scene.height, "minirt");
		mlx_key_hook(my_rt->win_ptr, &key_hook, my_rt);
		mlx_hook(my_rt->win_ptr, 17, 1L << 17, &close_rt, my_rt);
	}
	if (!(my_rt->image.img_ptr = mlx_new_image(my_rt->mlx_ptr,
								my_rt->scene.width, my_rt->scene.height)))
		freexit(my_rt, 1, "image new error");
	if (!(my_rt->image.addr = mlx_get_data_addr(my_rt->image.img_ptr, &(my_rt->image.bits_per_pixel),
			&(my_rt->image.line_length), &(my_rt->image.endian))))
		freexit(my_rt, 1, "image data error");
}

void		start_minirt(t_minirt *my_rt)
{	
	init_minirt(my_rt);
	if (!(my_rt->scene.cam_lst->content))
		freexit(my_rt, 1, "no camera");
	my_rt->scene.selected_cam = my_rt->scene.cam_lst->content;
	my_rt->selected = my_rt->scene.cam_lst;
	send_rays(my_rt);
	if (my_rt->save == 1)
		save_bmp(my_rt);
	else
	{
		mlx_put_image_to_window(my_rt->mlx_ptr, my_rt->win_ptr,
									my_rt->image.img_ptr, 0, 0);
		mlx_loop(my_rt->mlx_ptr);
	}
}