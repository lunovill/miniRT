/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:40:26 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:40:28 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Algorithme de ligne de Bresenham
// (http://fredericgoset.ovh/mathematiques/courbes/fr/bresenham_line.html)

static int	ft_signe_inc(int d)
{
	if (d < 0)
		return (-1);
	else if (d > 0)
		return (1);
	else
		return (0);
}

static void	ft_straight_line(t_mlx *mlx, Coor4f coor, int inc, int set)
{
	unsigned int	x;
	unsigned int	y;

	x = coor.x;
	y = coor.z;
	if (!set)
	{
		while (x != (unsigned int)(coor.y) + inc)
		{
			mlx_put_pixel(mlx, x, y, mlx->color);
			x += inc;
		}
	}
	else
	{
		while (y != (unsigned int)(coor.w) + inc)
		{
			mlx_put_pixel(mlx, x, y, mlx->color);
			y += inc;
		}
	}
}

static void	ft_diagonal_hline(t_mlx *mlx, Coor4f coor,
int tabx[3], int taby[3])
{
	int	slope;
	int	error;
	int	error_inc;

	slope = 2 * taby[1];
	error = -tabx[1];
	error_inc = -2 * tabx[1];
	while (tabx[0] != (int)(coor.y) + tabx[2])
	{
		mlx_put_pixel(mlx, tabx[0], taby[0], mlx->color);
		error += slope;
		if (error >= 0)
		{
			taby[0] += taby[2];
			error += error_inc;
		}
		tabx[0] += tabx[2];
	}
}

static void	ft_diagonal_vline(t_mlx *mlx, Coor4f coor,
int tabx[3], int taby[3])
{
	int	slope;
	int	error;
	int	error_inc;

	slope = 2 * tabx[1];
	error = -taby[1];
	error_inc = -2 * taby[1];
	while (taby[0] != (int)(coor.w) + taby[2])
	{
		mlx_put_pixel(mlx, tabx[0], taby[0], mlx->color);
		error += slope;
		if (error >= 0)
		{
			tabx[0] += tabx[2];
			error += error_inc;
		}
		taby[0] += taby[2];
	}
}

void	rt_line(t_mlx *mlx, Coor4f coor)
{
	int	tabx[3];
	int	taby[3];

	tabx[0] = coor.x;
	tabx[1] = coor.y - coor.x;
	tabx[2] = ft_signe_inc(tabx[1]);
	tabx[1] = ft_abs(tabx[1]);
	taby[0] = coor.z;
	taby[1] = coor.w - coor.z;
	taby[2] = ft_signe_inc(taby[1]);
	taby[1] = ft_abs(taby[1]);
	if (taby[1] == 0)
		ft_straight_line(mlx, coor, tabx[2], 0);
	else if (tabx[1] == 0)
		ft_straight_line(mlx, coor, taby[2], 1);
	else if (tabx[1] >= taby[1])
		ft_diagonal_hline(mlx, coor, tabx, taby);
	else
		ft_diagonal_vline(mlx, coor, tabx, taby);
}
