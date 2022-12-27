/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:38:49 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:38:50 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_miniRT    *test(t_miniRT *data)
{
	data->c = malloc(sizeof(t_camera));
	data->c->coor = (Coor4f){0., 0., 0., 1.};
	data->c->vector = (Vector4f){0., 0., 1., 0.};
	data->c->fov = 180. * M_PI / 180;
	data->c->near = 0.1;
	data->c->far = 100.;
	mt_view(&data->c->view, data->c->coor, data->c->vector);
	mt_perspective(&data->c->prspct, data->c, (float)data->mlx->hrslt / (float)data->mlx->wrslt);
	mt_cross_mt(&data->c->trsfrm, &data->c->view, &data->c->prspct);
    return (data);
}

int	minirt(t_miniRT *data)
{
	data->mlx = mlx_init_window(NULL, 500, 500);
	if (!data->mlx)
		return (rt_free(data, ERROR_MLX));
	data->mlx->key = mlx_init_key();
	data = test(data);
	mlx_loop_hook(data->mlx->init, rt_image, data);
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, mlx_key_press, data);
	mlx_hook(data->mlx->win, KeyRelease, KeyReleaseMask, mlx_key_release,
		data->mlx);
	mlx_hook(data->mlx->win, DestroyNotify, NoEventMask, rt_free, data);
	mlx_loop(data->mlx->init);
	return (0);
}

int	main(void)
{
	t_miniRT	*data;

	data = malloc(sizeof(*data));
	if (!data)
		return (rt_free(data, ERROR_MALLOC));
	data->mlx = NULL;
	data->garbage = NULL;
	minirt(data);
	return (0);
}
