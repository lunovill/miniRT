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

int	minirt(t_miniRT *data)
{
	data->mlx = mlx_init_window(NULL, 950, 950);
	if (!data->mlx)
		return (rt_free(data, ERROR_MLX));
	cm_init(&data->c->view, data->c->coor, data->c->vector);
	data->c->pz = 10;
	mlx_loop_hook(data->mlx->init, raytracer, data);
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, mlx_key_press, data);
	mlx_hook(data->mlx->win, KeyRelease, KeyReleaseMask, mlx_key_release,
		data->mlx);
	mlx_hook(data->mlx->win, DestroyNotify, NoEventMask, rt_free, data);
	mlx_loop(data->mlx->init);
	return (0);
}
