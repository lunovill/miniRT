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

typedef struct s_camera
{
	Coor4f		coor;
	Vector4f	vector;
	float		fov_h;
	float		fov_v;
	float		near;
	float		far;
}				t_camera;

typedef struct s_light
{
	Coor4f		orgc;
	Color4f		color;
}				t_light;

typedef struct s_sphere
{
	Coor4f		orgc;
	float		rayon;
	Color4f		color;
}				t_sphere;

typedef struct s_miniRT
{
	t_mlx			*mlx;
	t_camera		*c;
	t_light			**l;
	t_sphere		**sp;
	t_garbage		*garbage;
}				t_miniRT;

int		mlx_key_press(int keycode, t_miniRT *main);

// void	ft_print_cam(t_camera *c);
// void	rt_draw_pixel(t_mlx *mlx, Coor4f coor, int color);
int 	trgb_color(Color4f color);
int		rt_image(t_miniRT *main);
int		rt_free(t_miniRT *main, int code_error);
// int		trgb_color(int r, int g, int b);
int		minirt(t_miniRT *main);

#endif
