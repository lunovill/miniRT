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

// static void rt_pixel_to_point(Tuple4f *ray, t_miniRT *data, float x, float y)
// {
// 	float i_x;
// 	float i_y;
// 	Tuple4f	clip;

// 	float size = tanf(data->c->fov / 2.0);
// 	clip = data->c->coor + (Tuple4f)data->c->view.s89ab + (Tuple4f)data->c->view.s4567 * size - (Tuple4f)data->c->view.s0123 * size;
// 	i_x = 2.0 * size / data->mlx->wrslt;
// 	i_y = 2.0 * size / data->mlx->hrslt;
// 	// if ((x == 0.0 && y == 0.0) || (x == 0.0 && y == 250.0))
// 	// {
// 	// 	printf("size = %f\n clip (0.0, 0.0, 1.0) = (%f, %f, %f)\n i_xy = %f %f\n\n", size, clip.x, clip.y, clip.z, i_x, i_y);
// 	// 	printf("Right = %f %f %f\nUp =     %f %f %f\nDown =  %f %f %f", data->c->view.s0, data->c->view.s1,  data->c->view.s2, data->c->view.s4, data->c->view.s5, data->c->view.s6, data->c->view.s8, data->c->view.s9, data->c->view.sa);
// 	// }
// 	(*ray) = clip + (Tuple4f)data->c->view.s0123 * i_x * x - (Tuple4f)data->c->view.s4567 * i_y * y;
// 	// (*ray) *= 1 / size;
// 	normalize(&*ray);
// }

// void rt_pixel_to_point(Tuple4f *ray, t_miniRT *data, float x, float y)
// {
// 	float f = 1.0 / tanf(data->c->fov / 2.0);
// 	// printf("fov = %f\n\n", f);
// 	float px = (2.0 * x / data->mlx->wrslt - 1.0) * tanf(data->c->fov / 2.0) * data->mlx->wrslt / data->mlx->hrslt;
// 	float py = (1.0 - 2.0 * y / data->mlx->hrslt) * tanf(data->c->fov / 2.0);
// 	(*ray) = (Tuple4f){px * f, py * f, -f, 1.0};
// 	// (*ray) = (Tuple4f){px, py, -1, 1.0};
// 	// (*ray) /= sqrtf(px * px + py * py + 1.0);
// 	// if ((x == 0.0 && y == 0.0) || (x == 0.0 && y == 499.0) || (x == 499.0 && y == 0.0) || (x == 499.0 && y == 499.0))
// 		// printf("%f %f %f %f\n", px, py, -1.0, 1.0);
// 	(*ray).xyz += data->c->coor.xyz;
// 	(*ray).xyz += data->c->vector.xyz;
// 	(*ray).xyz /= sqrtf((*ray).x * (*ray).x + (*ray).y * (*ray).y + (*ray).z * (*ray).z);
// }

int	raytracer(t_miniRT *data)
{
ft_print_cam(data->c);
exit(42);
	// int	x;
	// int	y;
	// Tuple4f	ray;

	// y = 0;
	// while (y < data->mlx->hrslt)
	// {
	// 	x = 0;
	// 	while (x < data->mlx->wrslt)
	// 	{
	// 		rt_pixel_to_point(&ray, data, x, y);
	// 		// if (y == 0.0)
	// 		// 	printf("%f ,",ray.x);
	// 		// if (y == 250.0)
	// 		// 	printf("%f ,",ray.x);
	// 		// if (y == 499.0)
	// 		// 	printf("%f ,",ray.x);
	// 		mlx_put_pixel(data->mlx->scene, x, y, rt_intersection(data, data->c->coor, ray));
	// 		x++;
	// 	}
	// 	y++;
	// }
	// // exit (42);
	// mlx_put_image_to_window(data->mlx->init, data->mlx->win, data->mlx->scene->img, 0, 0);
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
