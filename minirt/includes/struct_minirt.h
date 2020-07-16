/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_minirt.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:31:01 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/09 18:02:27 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MINIRT_H
# define STRUCT_MINIRT_H

# include "minirt.h"

/*
**	VECTOR
*/

typedef struct	s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

/*
**	RAY
*/

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

/*
**	MATRIX
*/

typedef struct	s_matrix
{
	t_vec3			right;
	t_vec3			up;
	t_vec3			forward;
	t_vec3			translation;
}					t_matrix;

/*
**	QUADRATIC
*/

typedef struct	s_quadratic
{
	double			a;
	double			b;
	double			c;
}					t_quadratic;

/*
**	COLOR
*/

typedef struct	s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

/*
**	DIRECTIVE
*/

typedef struct	s_camera
{
	t_vec3			origin;
	t_vec3			direction;
	double			fov;
}					t_camera;

typedef struct	s_light
{
	t_vec3			origin;
	double			intensity;
	t_color			color;
}					t_light;

/*
**	OBJECTS
*/

typedef struct	s_plane
{
	t_vec3 			origin;
	t_vec3 			direction;
	t_color			color;
}					t_plane;

typedef struct	s_cylinder
{
	t_vec3			origin;
	t_vec3			direction;
	double			diameter;
	double			height;
	t_color			color;
}					t_cylinder;

typedef struct	s_triangle
{
	t_vec3			p1;
	t_vec3			p2;
	t_vec3			p3;
	t_color			color;	
}					t_triangle;

typedef struct	s_square
{
	t_vec3			origin;
	t_vec3			direction;
	double			height;
	t_color			color;
}					t_square;

typedef struct	s_sphere
{
	t_vec3			origin;
	double			radius;
	t_color			color;
}					t_sphere;

typedef enum	e_obj_type
{
	SP,
	PL,
	TR,
	SQ,
	CY,
}					t_obj_type;

typedef struct	s_object
{
	t_obj_type		type;
	t_color			color;
	void			*content;
	struct s_object	*next;
}					t_object;

/*
**	INTERSECTION
*/

typedef struct	s_ray_res
{
	t_vec3			hit_point;
	t_vec3			hit_normal;
	t_color			color;
}					t_ray_res;

/*
**	SCENE
*/

typedef struct	s_scene
{
	int				width;
	int				height;
	double			ambient_intensity;
	t_color			ambient_color;
	t_object		*objects;
	t_list			*light_lst;
	t_list			*cam_lst;
	void			*selected_cam;
	int				cam_index;
}					t_scene;

/*
**	IMAGE
*/

typedef	struct	s_image 
{
	void			*img_ptr;
	void			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image;

/*
**	GENERAL STRUCT
*/

typedef struct	s_minirt
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_scene			scene;
	t_image			image;
	int				save;
	char			*line;
	char			**split;
	int				selected_type;
	int				selected_index;
	void			*selected;
}					t_minirt;

#endif