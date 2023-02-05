/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:40:18 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:40:19 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_rayon	ray_for_pixel(t_miniRT *data, float px, float py, float aspect)
{
	t_rayon	r;
	float	x;
	float	y;
	Tuple4f	pixel;

	float f = tanf(data->c->fov / 2.);
	x = (2. * (px + 0.5) / (float)data->mlx->wrslt - 1.) * aspect * f;
	y = (1. - 2. * (py + 0.5) / (float)data->mlx->hrslt) * f;
	pixel = (Tuple4f){x, y, data->c->pz, 1.};
	r.origin = mt_cross_tp(&data->c->view, (Tuple4f){0., 0., 0., 1.});
	r.vector = mt_cross_tp(&data->c->view, pixel);
	r.vector = vt_normalize(r.vector - r.origin);
	return (r);
}

int	raytracer(t_miniRT *data)
{
	int	x;
	int	y;
	int	move;
	t_rayon	r;

	y = 0;
	while (y < data->mlx->hrslt)
	{
		x = 0;
		while (x < data->mlx->wrslt)
		{
			r = ray_for_pixel(data, x, y, data->mlx->wrslt/ data->mlx->hrslt);
			mlx_put_pixel(data->mlx->scene, x, y, rt_intersection(data, r));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, data->mlx->scene->img, 0, 0);
	move = cm_move(data->c, data->mlx->key);
	// if (move == 2)
	// 	printf("%f, %f, %f, %f\n\n", data->c->view.s8, data->c->view.s9, data->c->view.sa, data->c->view.se);
	return (0);
}
