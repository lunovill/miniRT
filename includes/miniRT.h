/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:15:54 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/22 20:15:55 by lunovill         ###   ########.fr       */
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
	float		pz;
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
void		fill_struct(t_miniRT *data, char *file);
int			rgb_color(int r, int g, int b);
int			check_tab(t_miniRT *data, char **tab);
float		cara_to_float(char *str);
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
void		cm_move(t_camera *c, t_key *key);

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
int			rt_sphere(t_miniRT *data, t_sphere *sp, t_tpl4f point, float t);
int			rt_plane(t_miniRT *data, t_plane *pl, t_tpl4f point);
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
