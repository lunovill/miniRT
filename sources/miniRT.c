/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:38:49 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:38:50 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// t_miniRT    *test(t_miniRT *main)
// {
//     main->sp = malloc(sizeof(t_sphere *) * 2);
//     main->garbage = gbg_add(main->garbage, main->sp);
//     main->sp[0] = malloc(sizeof(t_sphere));
//     main->garbage = gbg_add(main->garbage, main->sp[0]);
// 	main->sp[0]->coor.x = 200;
// 	main->sp[0]->coor.y = 250;
// 	main->sp[0]->coor.z = 10;
// 	main->sp[0]->rayon = 200;
// 	main->sp[0]->color = trgb_color(0, 255, 255, 255);
//     main->sp[1] = NULL;
//     return (main);
// }

int	minirt(t_miniRT *main)
{
	main->mlx = mlx_init_window(NULL, 500, 500);
	if (!main->mlx)
		return (rt_free(main, ERROR_MLX));
	main->mlx->key = mlx_init_key();
	// main = test(main);
	mlx_loop_hook(main->mlx->init, rt_image, main);
	mlx_hook(main->mlx->win, KeyPress, KeyPressMask, mlx_key_press, main);
	mlx_hook(main->mlx->win, KeyRelease, KeyReleaseMask, mlx_key_release,
		main->mlx);
	mlx_hook(main->mlx->win, DestroyNotify, NoEventMask, rt_free, main);
	mlx_loop(main->mlx->init);
	return (0);
}

// int	main(void)
// {
// 	t_miniRT	*main;

// 	main = malloc(sizeof(*main));
// 	if (!main)
// 		return (rt_free(main, ERROR_MALLOC));
// 	main->mlx = NULL;
// 	main->garbage = NULL;
// 	minirt(main);
// 	return (0);
// }
