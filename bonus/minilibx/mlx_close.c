/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:39:03 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:39:04 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxRT.h"

void	mlx_close(t_mlx *mlx)
{
	if (!mlx)
		return ;
	ft_free(mlx->key);
	if (mlx->scene && mlx->scene->img)
		mlx_destroy_image(mlx->init, mlx->scene->img);
	ft_free(mlx->scene);
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->init)
		mlx_destroy_display(mlx->init);
	ft_free(mlx->init);
	ft_free(mlx);
}
