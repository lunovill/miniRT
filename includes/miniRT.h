/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <hucoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:15:54 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/06 16:04:38 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <X11/keysymdef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "libmt.h"
# include "mlxRT.h"

//		 CODE ERREUR
# define ERROR_MALLOC 1
# define ERROR_MLX 2

// 		 OBJETS
# define SPHERE 0
# define CYLINDER 1
# define PLANE 2
# define OBJETS 3

//		CAMERA
# define P_Z 10

typedef struct s_check_file
{
	int			camera;
	int			light;
	int			sphere;
	int			plane;
	int			cylinder;
	int			line;
	int			nb_sp;
	int			nb_pl;
	int			nb_cy;
	int			nb_l;
}				t_check_file;

typedef struct s_camera
{
	t_tpl4f		coor;
	t_tpl4f		vector;
	t_mtx4f		view;
	float		fov;
	int			move;
}				t_camera;

typedef struct s_light
{
	t_tpl4f		coor;
	t_tpl4f		color;
}				t_light;

typedef struct s_sphere
{
	t_tpl4f		coor;
	float		rayon;
	t_tpl4f		vector;
	float		t1;
	float		t2;
	t_tpl4f		color;
}				t_sphere;

typedef struct s_plane
{
	t_tpl4f		coor;
	t_tpl4f		vector;
	float		t;
	t_tpl4f		color;
}				t_plane;

typedef struct s_cylinder
{
	t_tpl4f		coor;
	t_tpl4f		vector;
	float		rayon;
	float		height;
	float		t1;
	float		t2;
	t_tpl4f		color;
}				t_cylinder;

typedef struct s_miniRT
{
	t_check_file	*check;
	t_mlx			*mlx;
	t_camera		*c;
	t_light			**l;
	t_sphere		**sp;
	t_plane			**pl;
	t_cylinder		**cy;
	t_garbage		*garbage;
}				t_miniRT;

/********************************************************/
/*				      	PARSING							*/
/********************************************************/
t_miniRT	*init_minirt(void);
void		parsing(t_miniRT *data, char *file);
void		fill_struct_utils(t_miniRT *data, char *line, int fd);
void		init_struct(t_miniRT *data);
void		fill_cylinder_utils(t_miniRT *data, t_cylinder *tmp, char **tab);
void		fill_sphere_utils(t_miniRT *data, t_sphere *tmp, char **tab);
void		fill_plane_utils(t_miniRT *data, t_plane *tmp, char **tab);
void		fill_light_utils(t_miniRT *data, t_light *tmp, char **tab);
void		fill_ambiant_utils(t_miniRT *data, t_light *tmp, char **tab);
void		fill_camera_utils(t_miniRT *data, t_camera *tmp, char **check_tab);
void		fill_light(t_miniRT *data, char **tab);
void		fill_plane(t_miniRT *data, char **tab);
void		fill_sphere(t_miniRT *data, char **tab);
void		fill_cylinder(t_miniRT *data, char **tab);
void		fill_struct(t_miniRT *data, char *file);
int			rgb_color(int r, int g, int b);
int			check_tab(t_miniRT *data, char **tab);
float		c_to_f(char *str, float n, float div, unsigned int i);
void		fill_ambiant(t_miniRT *data, char **tab);
void		fill_camera(t_miniRT *data, char **tab);

/********************************************************/
/*						MINILIBX						*/
/********************************************************/
int			mlx_key_press(int keycode, t_miniRT *main);

/********************************************************/
/*						CAMERA							*/
/********************************************************/
void		cm_init(t_mtx4f *view, t_tpl4f coor, t_tpl4f vector);
int			cm_move(t_camera *c, t_key *key);

/********************************************************/
/*						RAYTRACING						*/
/********************************************************/
t_tpl4f		rt_ambient(t_tpl4f color, t_light *l);
t_tpl4f		rt_diffuse(t_tpl4f color, t_tpl4f n_vec, t_tpl4f l_vec, t_light *l);
t_tpl4f		rt_specular(t_tpl4f n_vec, t_tpl4f l_vec,
				t_tpl4f forward, t_light *l);
float		rt_shadow(t_miniRT *data, t_rayon r);
int			rt_intersection(t_miniRT *data, t_rayon r);
float		rt_intersection_sp(t_rayon r, t_sphere **sp, int *object);
float		rt_intersection_pl(t_rayon r, t_plane **pl, int *object);
float		rt_intersection_cy(t_rayon r, t_cylinder **cy, int *object);
int			rt_sphere(t_miniRT *data, t_sphere *sp, t_tpl4f point, float t);
int			rt_plane(t_miniRT *data, t_plane *pl, t_tpl4f point);
int			rt_cylinder(t_cylinder *cy, t_tpl4f orgc, t_tpl4f ray, float t, t_light **l);
int			raytracer(t_miniRT *main);
int			minirt(t_miniRT *data);

/********************************************************/
/*						UTILS							*/
/********************************************************/
int			trgb_color(t_tpl4f color);

/********************************************************/
/*						FREE							*/
/********************************************************/
int			rt_free(t_miniRT *main, int code_error);

/********************************************************/
/*						ERROR							*/
/********************************************************/
void		gestion_error(t_miniRT *data, int i);

#endif
