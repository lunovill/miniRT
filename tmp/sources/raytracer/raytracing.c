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

void	ft_print_cam(t_camera *c)
{
	printf("Camera :\n\n");
	printf("Coordonees     |\t%f, %f, %f, %f\n", c->coor.x, c->coor.y, c->coor.z, c->coor.w);
	printf("Vecteur Right  |\t%f, %f, %f, %f\n", c->view.s0, c->view.s1, c->view.s2, c->view.s3);
	printf("Vecteur Up     |\t%f, %f, %f, %f\n", c->view.s4, c->view.s5, c->view.s6, c->view.s7);
	printf("Vecteur Forward|\t%f, %f, %f, %f\n", c->view.s8, c->view.s9, c->view.sa, c->view.sb);
	// printf("FOV H = %f | FOV V = %f\n\n", c->fov_h, c->fov_v);
}

int move(t_camera *c, t_key *key)
{
	int ret = 0;
	if (key->up == 1)
		c->coor += (Coor4f)c->view.s4567 * 5.0, ret = 1;
	if (key->down == 1)
		c->coor -= (Coor4f)c->view.s4567 * 5.0, ret = 1;
	if (key->right == 1)
		c->coor += (Coor4f)c->view.s0123 * 5.0, ret = 1;
	if (key->left == 1)
		c->coor -= (Coor4f)c->view.s0123 * 5.0, ret = 1;
	if (key->befor == 1)
		c->coor += (Coor4f)c->view.s89ab * 5.0, ret = 1;
	if (key->behind == 1)
		c->coor -= (Coor4f)c->view.s89ab * 5.0, ret = 1;
	if (key->rot_up == 1)
		mt_rotate_x(&c->view, -0.1), ret = 2;
	if (key->rot_down == 1)
		mt_rotate_x(&c->view, 0.1), ret = 2;
	if (key->rot_right == 1)
		mt_rotate_y(&c->view, 0.1), ret = 2;
	if (key->rot_left == 1)
		mt_rotate_y(&c->view, -0.1), ret = 2;
	return ret;
}

// static void rt_pixel_to_point(Vector4f *ray, t_miniRT *data, float x, float y)
// {

// 	// float a = tanf(data->c->fov / 2.0);
// 	// float theta = -(data->c->fov / 2.0) + data->c->fov / data->mlx->wrslt * x;
// 	// // float c = tanf(data->c->fov / 2.0);
// 	// float phi = -(data->c->fov / 2.0) + data->c->fov / data->mlx->hrslt * y;

// 	// float z = cosf(theta);
// 	// (*ray) = tanf(theta) * (Vector4f)data->c->view.s0123  - tanf(phi) * (Vector4f)data->c->view.s4567 + (Vector4f)data->c->view.s89ab;
// 	// (*ray) += data->c->coor;
// 	// (*ray) += (Vector4f)data->c->view.s89ab;
// 	normalize(&*ray);
// 	(void)data;
// }

static void rt_pixel_to_point(Vector4f *ray, t_miniRT *data, float x, float y)
{
	/* Version 1*/
	float	xRel = (2.0 * (x / data->mlx->wrslt) - 1.0) * tanf(data->c->fov / 2.0) * data->mlx->wrslt / data->mlx->hrslt;
	float	yRel = (1.0 - 2.0 * (y / data->mlx->hrslt)) * tanf(data->c->fov / 2.0);
	float	zRel = (1.0 - 2.0 * (1.0 / data->mlx->wrslt)) * tanf(data->c->fov / 2.0) * 2.0;
	float f = 1.0 / tanf(data->c->fov / 2.0);
	(*ray) = xRel * (Vector4f)data->c->view.s0123 * f + yRel * (Vector4f)data->c->view.s4567 * f + zRel * (Vector4f)data->c->view.s89ab * f;

	/* Version 2*/
	// cr_cross_mt(&*org, (Coor4f){0.0, 0.0, 0.0, 1.0}, &data->c->view);
	// float	fov_coeff = tanf(data->c->fov / 2.0 * M_PI / 180.0);
	// float	xRel = (2.0 * (x + 0.5) / data->mlx->wrslt - 1.0) * fov_coeff * data->mlx->wrslt / data->mlx->hrslt;
	// float	yRel = (1.0 - 2.0 * (y + 0.5) / data->mlx->hrslt) * fov_coeff;
	// Vector4f ray = (Vector4f){xRel, yRel, 1.0, 0.0};
	// cr_cross_mt(&*drt, ray, &data->c->view);
	// *drt -= *org;
	// normalize(&*drt);
}

int	raytracing(t_miniRT *data)
{
	int	x;
	int	y;
	// Coor4f		org;
	Vector4f	ray;

	y = 0;
	while (y < data->mlx->hrslt)
	{
		x = 0;
		while (x < data->mlx->wrslt)
		{
			rt_pixel_to_point(&ray, data, x, y);
			// if (y == 0.0)
			// 	printf("%f ,",ray.x);
			// if (y == 250.0)
			// 	printf("%f ,",ray.x);
			// if (y == 499.0)
			// 	printf("%f ,",ray.x);
			mlx_put_pixel(data->mlx->scene, x, y, rt_intersection(data, data->c->coor, ray));
			x++;
		}
		y++;
	}
	// exit (42);
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, data->mlx->scene->img, 0, 0);
	move(data->c, data->mlx->key);
	// usleep(20000);
	return (0);
}
