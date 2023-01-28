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

// void	ft_print_mt(char *name, Matrix4f *m)
// {
// 	printf("%s :\n", name);
// 	printf("\t%f, %f, %f, %f\n", (*m).s0, (*m).s1, (*m).s2, (*m).s3);
// 	printf("\t%f, %f, %f, %f\n", (*m).s4, (*m).s5, (*m).s6, (*m).s7);
// 	printf("\t%f, %f, %f, %f\n", (*m).s8, (*m).s9, (*m).sa, (*m).sb);
// 	printf("\t%f, %f, %f, %f\n\n", (*m).sc, (*m).sd, (*m).se, (*m).sf);
// }

void	ft_print_tp(char *name, Tuple4f t)
{
	printf("%s%f, %f, %f, %f,\n", name, t.x, t.y, t.z, t.w);
}

// int move(t_camera *c, t_key *key)
// {
// 	int ret = 0;
// 	if (key->up == 1)
// 		c->coor += (Tuple4f)c->view.s4567, ret = 1;
// 	if (key->down == 1)
// 		c->coor -= (Tuple4f)c->view.s4567, ret = 1;
// 	if (key->right == 1)
// 		c->coor += (Tuple4f)c->view.s0123, ret = 1;
// 	if (key->left == 1)
// 		c->coor -= (Tuple4f)c->view.s0123, ret = 1;
// 	if (key->befor == 1)
// 		c->coor += (Tuple4f)c->view.s89ab *0.1, ret = 1;
// 	if (key->behind == 1)
// 		c->coor -= (Tuple4f)c->view.s89ab * 0.1, ret = 1;
// 	if (key->rot_up == 1)
// 		mt_rotate_x(&c->view, -0.1), ret = 2;
// 	if (key->rot_down == 1)
// 		mt_rotate_x(&c->view, 0.1), ret = 2;
// 	if (key->rot_right == 1)
// 		mt_rotate_y(&c->view, 0.1), ret = 2;
// 	if (key->rot_left == 1)
// 		mt_rotate_y(&c->view, -0.1), ret = 2;
// 	return ret;
// }

static t_rayon	ray_for_pixel(t_miniRT *data, float px, float py, float aspect)
{
	t_rayon	r;
	float	hlf_view;
	float	hlf_width;
	float	hlf_height;
	float	x;
	float	y;
	Tuple4f	pixel;
	Matrix4f	invs;

	hlf_view = tanf(data->c->fov / 2.0);
	if (aspect >= 1.)
	{
		hlf_width = hlf_view;
		hlf_height = hlf_view / aspect;
	}
	else
	{
		hlf_width = hlf_view * aspect;
		hlf_height = hlf_view;
	}
	x = hlf_width - (px + 0.5) * hlf_width * 2. / data->mlx->wrslt;
	y = hlf_height - (py + 0.5) * hlf_height * 2. / data->mlx->hrslt;
	mt_inverse(&invs, &data->c->view);
	pixel = mt_cross_tp(&invs, (Tuple4f){x, y, -1., 1.});
	r.origin = mt_cross_tp(&invs, (Tuple4f){0., 0., 0., 1.});
	r.vector = vt_normalize(pixel - r.origin);
	return (r);
}

int	raytracer(t_miniRT *data)
{
	int	x;
	int	y;
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
	// exit(42);
	// int ret = move(data->c, data->mlx->key);
	// if (ret == 1)
	// {
	// 	mt_view(&data->c->view, data->c->coor, data->c->vector);
	// 	ft_print_cam(data->c);
	// 	// printf("%f %f %f %f\n", data->c->coor.x, data->c->coor.y, data->c->coor.z, data->c->coor.w);
	// }
	// else if (ret == 2)
	// {
	// 	data->c->vector = (Tuple4f)data->c->view.s89ab;
	// 	ft_print_cam(data->c);
	// 	// printf("%f %f %f %f\n", data->c->vector.x, data->c->vector.y, data->c->vector.z, data->c->vector.w);
	// }
	// usleep(20000);
	return (0);
}
