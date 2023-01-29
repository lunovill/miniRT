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

// CODE ERREUR
# define ERROR_MALLOC 1
# define ERROR_MLX 2

# include <X11/keysymdef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "libmt.h"

# include "mlxRT.h"


typedef struct	s_check_file
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
	Tuple4f		coor;
	Tuple4f		vector;
	Matrix4f	view;
	float		fov;
}				t_camera;

typedef struct s_light
{
	Tuple4f		coor;
	float		brightness;
	Tuple4f		color;
}				t_light;

typedef struct s_sphere
{
	Tuple4f		coor;
	float		rayon;
	float		t1;
	float		t2;
	Tuple4f			color;
}				t_sphere;

typedef struct s_plane
{
	Tuple4f		coor;
	Tuple4f		vector;
	Tuple4f		color;
}				t_plane;

typedef struct s_cylinder
{
	Tuple4f		coor;
	Tuple4f		vector;
	float		rayon;
	float		height;
	Tuple4f		color;
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

/*			MINILIBX			*/
int		mlx_key_press(int keycode, t_miniRT *main);

/*			CAMERA				*/
void	cm_view(Matrix4f *view, Tuple4f coor, Tuple4f vector);

/*			RAYTRACING			*/
Tuple4f	rt_ambient(Tuple4f color, t_light *l);
Tuple4f	rt_diffuse(Tuple4f color, Tuple4f n_vec, Tuple4f l_vec, t_light *l);
Tuple4f	rt_specular(Tuple4f n_vec, Tuple4f l_vec, Tuple4f forward, t_light *l);
int		rt_intersection(t_miniRT *data, t_rayon r);
float	rt_intersection_sp(t_rayon r, t_sphere **sp, int *object);
float	rt_intersection_pl(t_rayon r, t_plane **pl, int *object);
int		rt_sphere(t_miniRT *data, t_sphere *sp, Tuple4f point, float t);
int		rt_plane(t_miniRT *data, t_plane *pl, Tuple4f point);
int		raytracer(t_miniRT *main);
int		minirt(t_miniRT *data);

/*			UTILS				*/
int		trgb_color(Tuple4f color);

/*			FREE				*/
int		rt_free(t_miniRT *main, int code_error);

// void		mt_projection(Matrix4f *prjt, t_camera *c, float window);
// float		rt_intersection_pl(t_plane **pl, int *object, Tuple4f rorg, Tuple4f rdrt);
// int			rt_sphere(t_sphere *sp, Tuple4f orgc, Tuple4f ray, float t, t_light **l);
// int			rt_plane(t_plane *pl, Tuple4f orgc, Tuple4f ray, float t, t_light **l);
// float		rt_intersection_pl(t_plane **pl, int *object, Tuple4f c_coor, Tuple4f r_dir);
// int			rt_plane(t_plane *pl, Tuple4f orgc, Tuple4f ray, float t, t_light **l);
// float		rt_intersection_cy(t_cylinder **cy, int *object, Tuple4f c_coor, Tuple4f r_dir);
// int			rt_cylinder(t_cylinder *cy, Tuple4f orgc, Tuple4f ray, float t, t_light **l);

/*      	PARSING			*/
 t_miniRT	*init_minirt(void);
 void		parsing(t_miniRT *data, char *file);
 void		fill_struct(t_miniRT *data, char *file);
 int		rgb_color(int r, int g, int b);
 int		check_tab(t_miniRT *data, char **tab);
 float		cara_to_float(char *str);
 void		fill_ambiant(t_miniRT *data, char **tab);
 void		fill_camera(t_miniRT *data, char **tab);

/*					ERROR				*/
 void		gestion_error(t_miniRT *data, int i);

#endif
