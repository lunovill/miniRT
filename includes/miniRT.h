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
}				t_check_file;

typedef struct s_camera
{
	Tuple4f		coor;
	Tuple4f	vector;
	Matrix4f	view;
	Matrix4f	prjt;
	Matrix4f	trsfrm;
	float		fov;
	float		near;
	float		far;
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
	Tuple4f	vector;
	Tuple4f			color;
}				t_plane;

typedef struct s_cylinder
{
	Tuple4f		coor;
	Tuple4f	vector;
	float		rayon;
	float		height;
	Tuple4f			color;
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
int		raytracer(t_miniRT *main);
int		minirt(t_miniRT *data);

/*			FREE				*/
int		rt_free(t_miniRT *main, int code_error);

// void		mt_projection(Matrix4f *prjt, t_camera *c, float window);
// float		rt_intersection_sp(t_sphere **sp, int *object, Tuple4f rorg, Tuple4f rdrt);
// float		rt_intersection_pl(t_plane **pl, int *object, Tuple4f rorg, Tuple4f rdrt);
// int			rt_sphere(t_sphere *sp, Tuple4f orgc, Tuple4f ray, float t, t_light **l);
// int			rt_plane(t_plane *pl, Tuple4f orgc, Tuple4f ray, float t, t_light **l);
// int			rt_intersection(t_miniRT *data, Tuple4f rorg, Tuple4f rdrt);
// int			trgb_color(Tuple4f color);
// float		rt_intersection_pl(t_plane **pl, int *object, Tuple4f c_coor, Tuple4f r_dir);
// int			rt_plane(t_plane *pl, Tuple4f orgc, Tuple4f ray, float t, t_light **l);
// float		rt_intersection_cy(t_cylinder **cy, int *object, Tuple4f c_coor, Tuple4f r_dir);
// int			rt_cylinder(t_cylinder *cy, Tuple4f orgc, Tuple4f ray, float t, t_light **l);

/*      	PARSING			*/

 t_miniRT	*init_minirt(void);
 int		parsing(t_miniRT *data, char *file);
 int		fill_struct(t_miniRT *data, char *file);
 int		rgb_color(int r, int g, int b);
 int		check_tab(t_miniRT *data, char **tab);
 float		cara_to_float(char *str);
 int		fill_ambiant(t_miniRT *data, char **tab);
 int		fill_camera(t_miniRT *data, char **tab);

/*					mon_get_next_line					*/
int			my_gnl(int fd, char **line);
char		*ft_strdup(char const *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/*					ERROR				*/
 void		gestion_error(t_miniRT *data);

#endif
