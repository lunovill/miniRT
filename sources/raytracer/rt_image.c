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

void refresh(t_miniRT *main)
{
	int j, i = 0;
	int color = trgb_color(0, 0, 0, 0);

	while (i < main->mlx->hrslt)
	{
		j = 0;
		while (j < main->mlx->wrslt)
			mlx_put_pixel(main->mlx, j++, i, color);
		i++;
	}
}

// void	rt(t_mlx *mlx, t_camera *c, t_sphere *sp)
// {
// 	float x, y, z;

// 	x = sp->camc.x - sp->rayon;
// 	while (x <= sp->camc.x + sp->rayon)
// 	{ 
// 		y = sp->camc.y - sp->rayon;
// 		while (y <= sp->camc.z + sp->rayon)
// 		{
// 			z = sp->camc.z - sp->rayon;
// 			while (z <= sp->camc.z + sp->rayon)
// 			{
// 				rt_draw_pixel(mlx, c, x, y, z, sp->color);
// 				z++;
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	rt_cammove(t_miniRT *main, t_camera *c, t_key *key)
// {
// 	if (key->up == 1)
// 		c->coor.y++;
// 	if (key->left == 1)
// 		c->coor.x--;
// 	if (key->down == 1)
// 		c->coor.y--;
// 	if (key->right == 1)
// 		c->coor.x++;
// 	if (key->befor == 1)
// 		c->coor.z++;
// 	if (key->behind == 1)
// 		c->coor.z--;
// 	mt_view(c->coor, c->vector);
// 	int i = 0;
// 	if (i)
// 		rt_camcoor(main);
// }

int	rt_image(t_miniRT *main)
{
	Coor4f point = {1, 1, 1, 1};
	Coor4f point_t;
	Matrix4f transf;

	mt_cross_mt(&transf, &main->c->view, &main->c->prspct);
	cr_cross_mt(&point_t, point, &transf);
	rt_draw_pixel(main->mlx, point_t, main->c->fov, trgb_color(1, 255, 255, 255));
	// printf("%f %f %f %f\n", point.x, point.y, point.z, point.w);
	// printf("%f %f %f %f\n\n", point_t.x, point_t.y, point_t.z, point_t.w);
	refresh(main);
	// rt(main->mlx, main->c, main->sp[0]);
	// rt_filled_circle(main->mlx, main->sp[0]);
	mlx_put_image_to_window(main->mlx->init, main->mlx->win,
		main->mlx->data->img, 0, 0);
	// rt_cammove(main, main->c, main->mlx->key);
	return (0);
}
