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

void	ft_print_sp(t_sphere **sp)
{
	int i = 0;
	printf("Spheres :\n\n");
	while(sp[i])
	{
		printf("Index : %i\n", i);
		printf("Coordonees  |\t%f %f %f %f\n", sp[i]->orgc.x, sp[i]->orgc.y, sp[i]->orgc.z, sp[i]->orgc.w);
		printf("Camera coor |\t%f %f %f %f\n\n", sp[i]->camc.x, sp[i]->camc.y, sp[i]->camc.z, sp[i]->camc.w);
		i++;
	}
}

void	ft_print_cam(t_camera *c)
{
	printf("Camera :\n\n");
	printf("Coordonees |\t%f, %f, %f, %f\n", c->coor.x, c->coor.y, c->coor.z, c->coor.w);
	printf("Vecteur    |\t%f, %f, %f, %f\n", c->vector.x, c->vector.y, c->vector.z, c->vector.w);
	printf("FOV = %f\n\n", c->fov);
	printf("Matrice vue:\n%f, %f, %f, %f\n", c->view.s0, c->view.s1, c->view.s2, c->view.s3);
	printf("%f, %f, %f, %f\n", c->view.s4, c->view.s5, c->view.s6, c->view.s7);
	printf("%f, %f, %f, %f\n", c->view.s8, c->view.s9, c->view.sa, c->view.sb);
	printf("%f, %f, %f, %f\n\n", c->view.sc, c->view.sd, c->view.se, c->view.sf);
	printf("Matrce projection:\n%f, %f, %f, %f\n", c->prspct.s0, c->prspct.s1, c->prspct.s2, c->prspct.s3);
	printf("%f, %f, %f, %f\n", c->prspct.s4, c->prspct.s5, c->prspct.s6, c->prspct.s7);
	printf("%f, %f, %f, %f\n", c->prspct.s8, c->prspct.s9, c->prspct.sa, c->prspct.sb);
	printf("%f, %f, %f, %f\n\n", c->prspct.sc, c->prspct.sd, c->prspct.se, c->prspct.sf);
	printf("Matrice tranformation:\n%f, %f, %f, %f\n", c->trsfrm.s0, c->trsfrm.s1, c->trsfrm.s2, c->trsfrm.s3);
	printf("%f, %f, %f, %f\n", c->trsfrm.s4, c->trsfrm.s5, c->trsfrm.s6, c->trsfrm.s7);
	printf("%f, %f, %f, %f\n", c->trsfrm.s8, c->trsfrm.s9, c->trsfrm.sa, c->trsfrm.sb);
	printf("%f, %f, %f, %f\n\n", c->trsfrm.sc, c->trsfrm.sd, c->trsfrm.se, c->trsfrm.sf);
}

int	minirt(t_miniRT *data)
{
	data->mlx = mlx_init_window(NULL, 500, 500);
	if (!data->mlx)
		return (rt_free(data, ERROR_MLX));
	mt_view(&data->c->view, data->c->coor, data->c->vector);
	mt_perspective(&data->c->prspct, data->c, (float)data->mlx->hrslt / (float)data->mlx->wrslt);
	mt_cross_mt(&data->c->trsfrm, &data->c->view, &data->c->prspct);
	data->mlx->key = mlx_init_key();
	ft_print_cam(data->c);
	rt_camcoor(data);
	ft_print_sp(data->sp);
	mlx_loop_hook(data->mlx->init, rt_image, data);
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, mlx_key_press, data);
	mlx_hook(data->mlx->win, KeyRelease, KeyReleaseMask, mlx_key_release,
		data->mlx);
	mlx_hook(data->mlx->win, DestroyNotify, NoEventMask, rt_free, data);
	mlx_loop(data->mlx->init);
	return (0);
}
