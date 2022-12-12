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

int	rt_image(t_miniRT *main)
{
	// if (main->mlx->key->up == 1)
	// {
	// 	main->sp[0]->coor.z -= 0.5;
	// 	main->mlx->key->up = 2;
	// } 
	// rt_filled_circle(main->mlx, main->sp[0]);
	mlx_put_image_to_window(main->mlx->init, main->mlx->win,
		main->mlx->data->img, 0, 0);
	return (0);
}
