/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:39:29 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:39:30 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxRT.h"

t_mlx	*ft_malloc_window(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->init = NULL;
	mlx->win = NULL;
	mlx->scene = NULL;
	mlx->key = NULL;
	mlx->init = mlx_init();
	if (!mlx->init)
		return (mlx_close(mlx), NULL);
	mlx->scene = malloc(sizeof(t_data));
	if (!mlx->scene)
		return (mlx_close(mlx), NULL);
	return (mlx);
}

t_mlx	*mlx_init_window(char *window_name, int width, int height)
{
	int tmp_w;
	int tmp_h;
	t_mlx	*mlx;

	mlx = ft_malloc_window();
	mlx_get_screen_size(mlx->init, &tmp_w, &tmp_h);
	mlx->wrslt = tmp_w;
	mlx->hrslt = tmp_h;
	if (!window_name)
		window_name = NAME;
	if (0 < width && width <= mlx->wrslt && 0 < height && height <= mlx->hrslt)
	{
		mlx->wrslt = width;
		mlx->hrslt = height;
	}
	mlx->win = mlx_new_window(mlx->init, mlx->wrslt, mlx->hrslt, window_name);
	if (!mlx->win)
		return (mlx_close(mlx), NULL);
	mlx->scene->img = mlx_new_image(mlx->init, width, height);
	if (!mlx->scene->img)
		return (mlx_close(mlx), NULL);
	mlx->scene->addr = mlx_get_data_addr(mlx->scene->img, &mlx->scene->bpp,
			&mlx->scene->sline, &mlx->scene->endian);
	return (mlx);
}
