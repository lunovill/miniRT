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
	mlx->data = NULL;
	mlx->key = NULL;
	mlx->init = mlx_init();
	if (!mlx->init)
		return (mlx_close(mlx), NULL);
	mlx->data = malloc(sizeof(t_data));
	if (!mlx->data)
		return (mlx_close(mlx), NULL);
	return (mlx);
}

t_mlx	*mlx_init_window(char *window_name, int width, int height)
{
	t_mlx	*mlx;

	mlx = ft_malloc_window();
	mlx_get_screen_size(mlx->init, &mlx->wrslt, &mlx->hrslt);
	if (!window_name)
		window_name = "miniRT";
	if (0 < width && width <= mlx->wrslt && 0 < height && height <= mlx->hrslt)
	{
		mlx->wrslt = width;
		mlx->hrslt = height;
	}
	mlx->win = mlx_new_window(mlx->init, mlx->wrslt, mlx->hrslt, window_name);
	if (!mlx->win)
		return (mlx_close(mlx), NULL);
	mlx->data->img = mlx_new_image(mlx->init, width, height);
	if (!mlx->data->img)
		return (mlx_close(mlx), NULL);
	mlx->data->addr = mlx_get_data_addr(mlx->data->img, &mlx->data->bpp,
			&mlx->data->sline, &mlx->data->endian);
	return (mlx);
}
