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

t_miniRT    *test(t_miniRT *main)
{
	main->c = malloc(sizeof(t_camera));
	main->c->coor = (Coor4f){0, 0, 0, 1};
	main->c->vector = (Vector4f){0, 0, 1, 0};
	main->c->fov = 130;
	mt_view(&main->c->view, main->c->coor, main->c->vector);
	mt_perspective(&main->c->prspct, main->c->fov, main->mlx->hrslt / main->mlx->wrslt);
	printf("%f %f %f %f\n", main->c->view.s0, main->c->view.s1, main->c->view.s2, main->c->view.s3);
	printf("%f %f %f %f\n", main->c->view.s4, main->c->view.s5, main->c->view.s6, main->c->view.s7);
	printf("%f %f %f %f\n", main->c->view.s8, main->c->view.s9, main->c->view.sa, main->c->view.sb);
	printf("%f %f %f %f\n\n", main->c->view.sc, main->c->view.sd, main->c->view.se, main->c->view.sf);
    // main->sp = malloc(sizeof(t_sphere *) * 2);
    // main->garbage = gbg_add(main->garbage, main->sp);
    // main->sp[0] = malloc(sizeof(t_sphere));
    // main->garbage = gbg_add(main->garbage, main->sp[0]);
	// main->sp[0]->orgc = (Coor4f){150, 150, 50, 1};
	// main->sp[0]->rayon = 100;
	// main->sp[0]->color = trgb_color(1, 255, 255, 255);
    // main->sp[1] = NULL;
	// main->pl = NULL;
	// main->cy = NULL;
	// rt_camcoor(main);
    return (main);
}

int	minirt(t_miniRT *main)
{
	main->mlx = mlx_init_window(NULL, 500, 500);
	if (!main->mlx)
		return (rt_free(main, ERROR_MLX));
	main->mlx->key = mlx_init_key();
	main = test(main);
	mlx_loop_hook(main->mlx->init, rt_image, main);
	mlx_hook(main->mlx->win, KeyPress, KeyPressMask, mlx_key_press, main);
	mlx_hook(main->mlx->win, KeyRelease, KeyReleaseMask, mlx_key_release,
		main->mlx);
	mlx_hook(main->mlx->win, DestroyNotify, NoEventMask, rt_free, main);
	mlx_loop(main->mlx->init);
	return (0);
}

int	main(void)
{
	t_miniRT	*main;

	main = malloc(sizeof(*main));
	if (!main)
		return (rt_free(main, ERROR_MALLOC));
	main->mlx = NULL;
	main->garbage = NULL;
	minirt(main);
	return (0);
}
