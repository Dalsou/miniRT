/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:28:54 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 15:36:36 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		write_data(int fd, void *image, int width, int height)
{
	int				x;
	int				y;
	int				*new_image;

	y = 0;
	new_image = (int *)image;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			write(fd, new_image + (height - 1 - y) * width + x, 4);
			x++;
		}
		y++;
	}
}

void		set_f_info(unsigned char *info, int width, int height)
{
	info[0] = 40;
	info[1] = 0;
	info[2] = 0;
	info[3] = 0;
	info[4] = width;
	info[5] = width >> 8;
	info[6] = width >> 16;
	info[7] = width >> 24;
	info[8] = height;
	info[9] = height >> 8;
	info[10] = height >> 16;
	info[11] = height >> 24;
	info[12] = 0;
	info[13] = 0;
	info[14] = 32;
	info[15] = 0;
}

void		set_header(unsigned char *header, int width, int height)
{
	int				f_size;

	f_size = 54 + 4 * width * height;
	header[0] = 'B';
	header[1] = 'M';
	header[2] = f_size;
	header[3] = f_size >> 8;
	header[4] = f_size >> 16;
	header[5] = f_size >> 24;
	header[6] = 0;
	header[7] = 0;
	header[8] = 0;
	header[9] = 0;
	header[10] = 54;
	header[11] = 0;
	header[12] = 0;
	header[13] = 0;
}

void		save_bmp(t_minirt *my_rt)
{
	int				fd;
	unsigned char	header[14];
	unsigned char	f_info[40];

	if ((fd = open("miniRT_sreenshot.bmp", O_RDWR | O_CREAT, 0777)) == -1)
		return ;
	ft_bzero(&header, (sizeof(header)));
	ft_bzero(&f_info, (sizeof(f_info)));
	set_header(header, my_rt->scene.width, my_rt->scene.height);
	set_f_info(f_info, my_rt->scene.width, my_rt->scene.height);
	write(fd, header, 14);
	write(fd, f_info, 40);
	write_data(fd, my_rt->image.addr, my_rt->scene.width,
				my_rt->scene.height);
	close(fd);
	close_rt2(my_rt);
}