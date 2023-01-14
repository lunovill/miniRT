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
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/gbg_collector.h"

# include "mlxRT.h"

typedef float Matrix4f __attribute__((ext_vector_type(4*4)));
typedef float Vector4f __attribute__((ext_vector_type(4)));
typedef float Coor4f __attribute__((ext_vector_type(4)));
typedef float Color4f __attribute__((ext_vector_type(4)));

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
	Coor4f		coor;
	Vector4f	vector;
	Matrix4f	view;
	Matrix4f	prjt;
	Matrix4f	trsfrm;
	float		fov;
	float		near;
	float		far;
}				t_camera;

typedef struct s_light
{
	Coor4f		coor;
	float		brightness;
	Color4f			color;
}				t_light;

typedef struct s_sphere
{
	Coor4f		coor;
	float		rayon;
	Color4f			color;
}				t_sphere;

typedef struct s_plane
{
	Coor4f		coor;
	Vector4f	vector;
	Color4f			color;
}				t_plane;

typedef struct s_cylinder
{
	Coor4f		coor;
	Vector4f	vector;
	float		rayon;
	float		height;
	Color4f			color;
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

int		mlx_key_press(int keycode, t_miniRT *main);

void 	cr_cross_mt(Coor4f *result, Coor4f coor, Matrix4f *mtx);
void	mt_cross_cr(Coor4f *result, Matrix4f *mtx, Coor4f coor);
void	mt_cross_mt(Matrix4f *result, Matrix4f *m1, Matrix4f *m2);
void	cross_product(Vector4f *result, Vector4f u, Vector4f v);
void	normalize(Vector4f *result);
void	mt_view(Matrix4f *view, Coor4f coor, Vector4f vector);
void	mt_projection(Matrix4f *prjt, t_camera *c, float window);
float	rt_intersection_sp(t_sphere **sp, int *object, Coor4f rorg, Vector4f rdrt);
float	rt_intersection_pl(t_plane **pl, int *object, Coor4f rorg, Vector4f rdrt);
int	rt_sphere(t_sphere *sp, Coor4f orgc, Vector4f ray, float t, t_light **l);
int	rt_plane(t_plane *pl, Coor4f orgc, Vector4f ray, float t, t_light **l);
int		rt_intersection(t_miniRT *data, Coor4f rorg, Vector4f rdrt);
int		raytracing(t_miniRT *main);
int		rt_free(t_miniRT *main, int code_error);
int		trgb_color(Color4f color);
int		minirt(t_miniRT *main);

// /*      fonction        */

// t_miniRT    *init_minirt(void);
// int     	parsing(t_miniRT *data, char *file);
// int     	fill_struct(t_miniRT *data, char *file);
// int			rgb_color(int r, int g, int b);
// int			check_tab(t_miniRT *data, char **tab);
// float		cara_to_float(char *str);
// int			fill_ambiant(t_miniRT *data, char **tab);
// int			fill_camera(t_miniRT *data, char **tab);

// /*					mon_get_next_line					*/

// int			my_gnl(int fd, char **line);
// char		*ft_strdup(char const *s1);
// char		*ft_substr(char const *s, unsigned int start, size_t len);

// /*					Error				*/

// void		gestion_error(t_miniRT *data);

#endif
