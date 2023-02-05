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
	float	x;
	float	y;
	float	f;
	t_tpl4f	pixel;
	t_rayon	r;

	f = tanf(data->c->fov / 2.);
	x = (2. * (px + 0.5) / (float)data->mlx->wrslt - 1.) * aspect * f;
	y = (1. - 2. * (py + 0.5) / (float)data->mlx->hrslt) * f;
	pixel = (t_tpl4f){x, y, P_Z, 1.};
	r.origin = mt_cross_tp(&data->c->view, (t_tpl4f){0., 0., 0., 1.});
	r.vector = mt_cross_tp(&data->c->view, pixel);
	r.vector = vt_normalize(r.vector - r.origin);
	return (r);
}

int	raytracer(t_miniRT *data)
{
	int		x;
	int		y;
	t_rayon	r;

	if (data->c->move)
	{
		y = 0;
		while (y < data->mlx->hrslt)
		{
			x = 0;
			while (x < data->mlx->wrslt)
			{
				r = ray_for_pixel(data, x, y, data->mlx->wrslt / data->mlx->hrslt);
				mlx_put_pixel(data->mlx->scene, x, y, rt_intersection(data, r));
				x++;
			}
			y++;
		}
	}
	mlx_put_image_to_window(data->mlx->init,
		data->mlx->win, data->mlx->scene->img, 0, 0);
	data->c->move = cm_move(data->c, data->mlx->key);
	return (0);
}
