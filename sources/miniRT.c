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
	int i = 0;
	int j = 0;
	int k = 0;
	printf("Camera:\n%f %f %f %f / %f %f %f %f / %f\n", 
	data->c->coor.s0, data->c->coor.s1, data->c->coor.s2, data->c->coor.s3,
	data->c->vector.s0, data->c->vector.s1, data->c->vector.s2, data->c->vector.s3, data->c->fov);
	while (data->l[i])
	{
		printf("Light:\n%f / %f %f %f %f / %f %f %f %f\n",
		data->l[i]->brightness, data->l[i]->coor.s0, data->l[i]->coor.s1, data->l[i]->coor.s2, data->l[i]->coor.s3,
		data->l[i]->color.s0, data->l[i]->color.s1, data->l[i]->color.s2, data->l[i]->color.s3);
		i++;
	}
	while (data->sp[j])
	{
		printf("sphere:\n%f / %f %f %f %f / %f %f %f %f\n",
		data->sp[j]->rayon, data->sp[j]->coor.s0, data->sp[j]->coor.s1, data->sp[j]->coor.s2, data->sp[j]->coor.s3,
		data->sp[j]->color.s0, data->sp[j]->color.s1, data->sp[j]->color.s2, data->sp[j]->color.s3);
		j++;
	}
	printf("check :\n%d %d %d %d\n", data->check->nb_cy, data->check->nb_pl, data->check->nb_sp, data->check->light);
	while (data->pl[k])
	{
		printf("plan:\n%f %f %f %f / %f %f %f %f / %f %f %f %f\n",
		data->pl[k]->coor.s0, data->pl[k]->coor.s1, data->pl[k]->coor.s2, data->pl[k]->coor.s3,
		data->pl[k]->vector.s0, data->pl[k]->vector.s1, data->pl[k]->vector.s2, data->pl[k]->vector.s3,
		data->pl[k]->color.s0, data->pl[k]->color.s1, data->pl[k]->color.s2, data->pl[k]->color.s3);
		k++;
	}
	data->mlx = mlx_init_window(NULL, 500, 500);
	if (!data->mlx)
		return (rt_free(data, ERROR_MLX));
	mt_view(&data->c->view, data->c->coor, data->c->vector);
	mt_projection(&data->c->prjt, data->c, data->mlx->wrslt / data->mlx->hrslt);
	data->mlx->key = mlx_init_key();
	mlx_loop_hook(data->mlx->init, raytracing, data);
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, mlx_key_press, data);
	mlx_hook(data->mlx->win, KeyRelease, KeyReleaseMask, mlx_key_release,
		data->mlx);
	mlx_hook(data->mlx->win, DestroyNotify, NoEventMask, rt_free, data);
	mlx_loop(data->mlx->init);
	return (0);
}