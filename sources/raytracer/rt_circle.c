/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_filled_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:39:57 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:39:59 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// L'algorithme de cercle de Bresenham
// (http://fredericgoset.ovh/mathematiques/courbes/fr/bresenham_circle.html)

void	rt_empty_circle(t_mlx *mlx, t_sphere *sp)
{
	float	r;
	float	x;
	float	y;

	if (sp->camc.z)
		r  = sp->rayon / sp->camc.z;
	else
		r  = sp->rayon;
	x = 0;
	y = r;
	mlx->color = sp->color;
	while (x <= y)
	{
		mlx_put_pixel(mlx, sp->camc.x + x, sp->camc.y - y, mlx->color);
		mlx_put_pixel(mlx, sp->camc.x - x, sp->camc.y - y, mlx->color);
		mlx_put_pixel(mlx, sp->camc.x + y, sp->camc.y - x, mlx->color);
		mlx_put_pixel(mlx, sp->camc.x - y, sp->camc.y - x, mlx->color);
		mlx_put_pixel(mlx, sp->camc.x + y, sp->camc.y + x, mlx->color);
		mlx_put_pixel(mlx, sp->camc.x - y, sp->camc.y + x, mlx->color);
		mlx_put_pixel(mlx, sp->camc.x + x, sp->camc.y + y, mlx->color);
		mlx_put_pixel(mlx, sp->camc.x - x, sp->camc.y + y, mlx->color);
		x++;
		if (0 < (x + 1) * (x + 1) + (y - 0.5f) * (y - 0.5f) - r * r)
			y--;
	}
}

static void	rt_filling_circle(t_mlx *mlx, t_sphere *sp, float x, float y)
{
	Coor4f	line;

	line = (Coor4f){sp->camc.x + x, sp->camc.x - x, sp->camc.y - y, sp->camc.y - y};
	rt_line(mlx, line);
	line = (Coor4f){sp->camc.x + y, sp->camc.x - y, sp->camc.y - x, sp->camc.y - x};
	rt_line(mlx, line);
	line = (Coor4f){sp->camc.x + y, sp->camc.x - y, sp->camc.y + x, sp->camc.y + x};
	rt_line(mlx, line);
	line = (Coor4f){sp->camc.x + x, sp->camc.x - x, sp->camc.y + y, sp->camc.y + y};
	rt_line(mlx, line);
}

void	rt_filled_circle(t_mlx *mlx, t_sphere *sp)
{
	float	r;
	float	x;
	float	y;

	if (sp->camc.z)
		r  = sp->rayon / sp->camc.z;
	else
		r  = sp->rayon;
	x = 0;
	y = r;
	mlx->color = sp->color;
	while (x <= y)
	{
		rt_filling_circle(mlx, sp, x, y);
		x++;
		if (0 < (x + 1) * (x + 1) + (y - 0.5f) * (y - 0.5f) - r * r)
			y--;
	}
}
