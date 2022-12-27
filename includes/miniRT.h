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
# include "mlxRT.h"

typedef float Matrix4f __attribute__((ext_vector_type(16)));
typedef float Vector4f __attribute__((ext_vector_type(4)));
typedef float Coor4f __attribute__((ext_vector_type(4)));

typedef struct s_camera
{
	Coor4f		coor;
	Vector4f	vector;
	Matrix4f	view;
	Matrix4f	prspct;
	Matrix4f	trsfrm;
	float		fov;
	float		near;
	float		far;
}				t_camera;

typedef struct s_light
{
	Coor4f		coor;
	float		brightness;
	int			color;
}				t_light;

typedef struct s_sphere
{
	Coor4f		orgc;
	Coor4f		camc;
	float		rayon;
	int			color;
}				t_sphere;

typedef struct s_plane
{
	Coor4f		orgc;
	Coor4f		camc;
	Vector4f	vector;
	int			color;
}				t_plane;

typedef struct s_cylinder
{
	Coor4f		orgc;
	Coor4f		camc;
	Vector4f	vector;
	float		rayon;
	float		height;
	int			color;
}				t_cylinder;

typedef struct s_miniRT
{
	t_mlx		*mlx;
	t_camera	*c;
	t_light		**l;
	t_sphere	**sp;
	t_plane		**pl;
	t_cylinder	**cy;
	t_garbage	*garbage;
}				t_miniRT;

int		mlx_key_press(int keycode, t_miniRT *main);

void 	cr_cross_mt(Coor4f *result, Coor4f coor, Matrix4f *mtx);
void	mt_cross_cr(Coor4f *result, Matrix4f *mtx, Coor4f coor);
void	mt_cross_mt(Matrix4f *result, Matrix4f *m1, Matrix4f *m2);
void	mt_view(Matrix4f *view, Coor4f coor, Vector4f vector);
void	mt_perspective(Matrix4f *prspct, t_camera *c, float window);
void	rt_camcoor(t_miniRT *main);
void    mt_rotate_x(Matrix4f *rx, float theta);
void    mt_rotate_y(Matrix4f *ry, float theta);
void    mt_rotate_z(Matrix4f *rz, float theta);
// void	rt_draw_pixel(t_mlx *mlx, Coor4f coor, float fov, int color);
void	rt_draw_pixel(t_mlx *mlx, Coor4f coor, int color);
// void	rt_line(t_mlx *mlx, Coor4f coor);
// void	rt_empty_circle(t_mlx *mlx, t_sphere *sp);
// void	rt_filled_circle(t_mlx *mlx, t_sphere *sp);
int		rt_image(t_miniRT *main);
int		rt_free(t_miniRT *main, int code_error);
int		rgb_color(int r, int g, int b);
int		minirt(t_miniRT *main);

#endif
