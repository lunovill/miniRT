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

void refresh(t_mlx *mlx)
{
	int x = 0;
	while (x < mlx->hrslt)
	{
		int y = 0;
		while (y < mlx->wrslt)
			mlx_put_pixel(mlx->scene, y++, x, 0);
		x++;
	}
}

int move(t_camera *c, t_key *key)
{
	int ret = 0;
	if (key->up == 1)
		c->coor.y += .1, ret = 1;
	if (key->down == 1)
		c->coor.y -= .1, ret = 1;
	if (key->right == 1)
		c->coor.x += .1, ret = 1;
	if (key->left == 1)
		c->coor.x -= .1, ret = 1;
	mt_view(&c->view, c->coor, c->vector);
	mt_cross_mt(&c->trsfrm, &c->view, &c->prspct);
	return ret;
}

int	rt_image(t_miniRT *data)
{
	Coor4f point = {0., 0., 1., 1.};
	Coor4f result;
	cr_cross_mt(&result, point, &data->c->view);
	cr_cross_mt(&point, result, &data->c->prspct);
	rt_draw_pixel(data->mlx, result, rgb_color(255, 255, 255));
	// int i = 50;
	// while (i--)
	// {
	// 	cr_cross_mt(&result, point, &data->c->view);
	// 	// printf("%f, %f, %f, %f\n\n", result.x, result.y, result.z, result.w);
	// 	rt_draw_pixel(data->mlx, result, rgb_color(255, 255, 255));
	// 	// if (!(0 <= result.x && result.x < data->mlx->wrslt && 0 <= result.y && result.y < data->mlx->hrslt))
	// 		// mlx_put_pixel(data->mlx->scene, result.x, result.y, rgb_color(255, 255, 255));
	// 	// printf("%f, %f, %f, %f\n\n", point.x, point.y, point.z, point.w);
	// 	point.x += .01;
	// }
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, data->mlx->scene->img, 0, 0);
	// move(data->c, data->mlx->key);
	if (move(data->c, data->mlx->key))
		refresh(data->mlx);
	usleep(20000);
	return (0);
}
