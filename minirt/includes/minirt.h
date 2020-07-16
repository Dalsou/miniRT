/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:28:01 by afoulqui          #+#    #+#             */
/*   Updated: 2020/07/16 14:53:43 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# include "libft.h"
# include "mlx.h"
# include "struct_minirt.h"
# include "keys.h"

int			main(int argc, char **argv);
void		check_arg(int argc, char **argv, t_minirt *my_rt);

/*
**	PARSING
*/

void		*parse_file(char *file, t_minirt *my_rt);
void		parse_line(t_minirt *my_rt);
t_vec3		parse_vector(t_minirt *my_rt, char *str, int orientation);
t_color		parse_color(t_minirt *my_rt, char *str_color);
int			check_nb_split(char **split);
int			check_split(char **split);
void		parse_resolution(t_minirt *my_rt);
void		parse_ambient(t_minirt *my_rt);
void		parse_camera(t_minirt *my_rt);
void		parse_light(t_minirt *my_rt);
void		parse_plane(t_minirt *my_rt);
void		parse_sphere(t_minirt *my_rt);
void		parse_cylinder(t_minirt *my_rt);
void		parse_square(t_minirt *my_rt);
void		parse_triangle(t_minirt *my_rt);
t_object	*lstnew_obj(void *content, int type, t_color color);
void		lstadd_back_obj(t_object **alst, t_object *new);

/*
**	RENDERING
*/

void		start_minirt(t_minirt *my_rt);
void		init_minirt(t_minirt *my_rt);
void		start_render(t_minirt *my_rt);
void		send_rays(t_minirt *my_rt);

/*
**	RAY
*/

t_ray		get_ray(int x, int y, t_scene scene, t_camera cam);
t_vec3		get_direction(int x, int y, t_scene scene, t_camera cam);
void		check_direction(t_vec3 *direction, t_vec3 ray_direction);
t_matrix	look_at(t_vec3 from, t_vec3 to, t_vec3 tmp);
t_vec3		multi_vec_matrix(t_vec3 vec, t_matrix matrix);

/*
**	COLOR
*/

int			get_color(t_minirt *my_rt, t_ray ray);
int			to_int(t_color color);
t_color		color_coeff(t_color color , double coeff);
t_color		color_add(t_color c1, t_color c2);
t_color		color_mult(t_color c1, t_color c2);

/*
**	INTERSECT
*/

t_object	*intersect_with_all(t_scene scene, t_ray ray, double *t_min);
double		intersect_obj(t_ray ray, t_object *obj, double *t);

/*
**	OBJECTS 
*/

int			intersect_plane(t_ray ray, t_plane plane, double *t);
int			intersect_sphere(t_ray ray, t_sphere sphere, double *t);
int			sphere_roots(double *t0, double *t1, t_ray ray, t_sphere sphere);
int			intersect_triangle(t_ray ray, t_triangle triangle, double *t);
int			check_edges(t_triangle triangle, t_vec3 p, t_vec3 n);
int			intersect_square(t_ray ray, t_square square, double *t);
int			intersect_cylinder(t_ray ray, t_cylinder cylinder, double *t);
int			cyl_roots(double *t0, double *t1, t_cylinder cylinder, t_ray ray);
void		check_t(double *t, t_cylinder cylinder, t_ray ray);

/*
**	SHADE 
*/

t_color		shade(t_scene scene, t_ray ray, t_object *object, double t);
t_color		get_light(t_light light, t_scene scene, t_ray_res ray_res,
						t_vec3 origin);
t_color		mix_colors(t_light light, double coeff, t_ray_res ray_res,
						t_vec3 origin);

/*
**	SPECULAR
*/

t_color		specular(t_light light, t_ray_res ray_res, t_vec3 origin);


/*
**	NORM
*/

t_vec3		get_norm(t_vec3 p, t_object *object);
t_vec3		plane_normal(t_plane plane);
t_vec3		sphere_normal(t_vec3 p, t_sphere sphere);
t_vec3		cylinder_normal(t_vec3 point, t_cylinder cylinder);
t_vec3		square_normal(t_square square);
t_vec3		triangle_normal(t_triangle triangle);

/*
**	SAVE
*/

void		save_bmp(t_minirt *my_rt);
void		set_header(unsigned char *header, int width, int height);
void		set_f_info(unsigned char *info, int width, int height);
void		write_data(int fd, void *image, int width, int height);

/*
**	EXIT
*/

void		freexit(t_minirt *my_rt, int error, char *error_msg);
void		close_rt2(t_minirt *my_rt);
int			close_rt(t_minirt *my_rt);
void		free_everything(t_minirt *my_rt);
void		clear_objects(t_object **lst);
void		lstclear_rt(t_list **lst);


/*
**	VECTOR
*/

t_vec3		vec3_new(double x, double y, double z);
double		vec3_len(t_vec3 vec);
t_vec3		vec3_div(t_vec3 v1, double d);
t_vec3		vec3_norm(t_vec3 vec);
double		vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_mul(t_vec3 v1, double m);
t_vec3		vec3_cross(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_invert(t_vec3 vec);

/*
**	QUADRATIC
*/

int			solve_quadratic(t_vec3 params, double *x0, double *x1);
t_vec3		new_qparams(double a, double b, double c);
void		swap_doubles(double *a, double *b);

/*
**	KEY
*/

int			key_hook(int k, t_minirt *my_rt);
void		next_cam(t_minirt *my_rt);
void		next_obj(t_minirt *my_rt);
void		type(t_minirt *my_rt);
void		*lst_find(t_minirt *my_rt, t_list *lst);
void		*lst_find2(t_minirt *my_rt);
void		translation(t_minirt *my_rt, int k);
t_vec3		*get_origin(int k, t_minirt *my_rt);
t_vec3		*object_origin(int k, t_minirt *my_rt);
void		translation2(int k, t_vec3 *origin);
void		rotation(t_minirt *my_rt, int k);
void		rot_cy(t_vec3 *origin, int k);
void		rot_sp(t_sphere *sphere, int k);
void		rot(double *sx, double *sy);

#endif