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

// int move(t_camera *c, t_key *key)
// {
// 	int ret = 0;
// 	if (key->up == 1)
// 		c->coor.y += .1, ret = 1;
// 	if (key->down == 1)
// 		c->coor.y -= .1, ret = 1;
// 	if (key->right == 1)
// 		c->coor.x += .1, ret = 1;
// 	if (key->left == 1)
// 		c->coor.x -= .1, ret = 1;
// 	if (key->rot_up == 1)
// 		c->vector.y += .1, ret = 1;
// 	if (key->rot_down == 1)
// 		c->vector.y -= .1, ret = 1;
// 	if (key->rot_right == 1)
// 		c->vector.x += .1, ret = 1;
// 	if (key->rot_left == 1)
// 		c->vector.x -= .1, ret = 1;
// 	if (key->befor == 1)
// 		c->vector.z += .1, ret = 1;
// 	if (key->behind == 1)
// 		c->vector.z -= .1, ret = 1;
// 	mt_view(&c->view, c->coor, c->vector);
// 	mt_cross_mt(&c->trsfrm, &c->view, &c->prspct);
// 	return ret;
// }

// static void rt_pixel_to_point(Coor4f *point, t_miniRT *data, float x, float y)
// {
// 	float	px;
// 	float	py;
// 	// Coor4f	pixel;

// 	px = (2.0 * x / data->mlx->wrslt - 1.0) * tanf(data->c->fov / 2.0) * data->mlx->wrslt / data->mlx->hrslt;
// 	py = (1.0 - 2.0 * y / data->mlx->hrslt) * tanf(data->c->fov * data->mlx->wrslt / data->mlx->hrslt / 2.0);
// 	(*point) = (Coor4f){px, py, -1.0, 1.0};
// 	// pixel = (*point);
// 	// cr_cross_mt(&(*point), pixel, &data->c->view);
// 	// if ((x == 0.0 && y == 0.0) || (x == 0.0 && y == 499.0) || (x == 499.0 && y == 0.0) || (x == 499.0 && y == 499.0))
// 		// printf("%f %f %f %f\n", (*point).x, (*point).y, (*point).z, (*point).w);
// }

static void rt_pixel_to_point(Vector4f *ray, t_miniRT *data, float x, float y)
{
	float i_x;
	float i_y;
	Coor4f	clip;

	float size = tanf(data->c->fov / 2.0);
	clip = data->c->coor + (Vector4f)data->c->view.s89ab + (Vector4f)data->c->view.s4567 * size - (Vector4f)data->c->view.s0123 * size;
	i_x = 2.0 * size / data->mlx->wrslt;
	i_y = 2.0 * size / data->mlx->hrslt;
	(*ray) = clip  + (Vector4f)data->c->view.s0123 * i_x * x - (Vector4f)data->c->view.s4567 * i_y * y;
	// (*ray) *= 1 / size;
	normalize(&*ray);
}

int	raytracing(t_miniRT *data)
{
	int	x;
	int	y;
	Vector4f	ray;

	y = 0;
	while (y < data->mlx->hrslt)
	{
		x = 0;
		while (x < data->mlx->wrslt)
		{
			// if ((x == 0 && y == 0) || (x == 0 && y == 499) || (x == 499 && y == 0) || (x == 499 && y == 499))
				// printf("%i %i\t", x, y);
			rt_pixel_to_point(&ray, data, x, y);
			mlx_put_pixel(data->mlx->scene, x, y, rt_intersection(data, data->c->coor, ray));
			x++;
		}
		y++;
	}
	// exit (42);
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, data->mlx->scene->img, 0, 0);
	// move(data->c, data->mlx->key);
	// usleep(20000);
	return (0);
}
