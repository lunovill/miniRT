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

void	ft_print_l(t_light **l)
{
	int i = 1;
	printf("Lumiere :\n\n");
	while(l[i])
	{
		printf("Index : %i\n", i);
		printf("Coordonees |\t%f %f %f %f\n", l[i]->orgc.x, l[i]->orgc.y, l[i]->orgc.z, l[i]->orgc.w);
		i++;
	}
	printf("\n");
}

void	ft_print_sp(t_sphere **sp)
{
	int i = 0;
	printf("Spheres :\n\n");
	while(sp[i])
	{
		printf("Index : %i\n", i);
		printf("Coordonees |\t%f %f %f %f\n", sp[i]->orgc.x, sp[i]->orgc.y, sp[i]->orgc.z, sp[i]->orgc.w);
		printf("Rayon      |\t%f\n", sp[i]->rayon);
		i++;
	}
	printf("\n");
}

void	ft_print_cam(t_camera *c)
{
	printf("Camera :\n\n");
	printf("Coordonees |\t%f, %f, %f, %f\n", c->coor.x, c->coor.y, c->coor.z, c->coor.w);
	printf("Vecteur    |\t%f, %f, %f, %f\n", c->vector.x, c->vector.y, c->vector.z, c->vector.w);
	printf("FOV H = %f | FOV V = %f\n\n", c->fov_h, c->fov_v);
}

int	minirt(t_miniRT *data)
{
	data->mlx = mlx_init_window(NULL, W_SSCREEN, H_SSCREEN);
	if (!data->mlx)
		return (rt_free(data, ERROR_MLX));

	data->mlx->key = mlx_init_key();
	data->c->fov_v = data->c->fov_h * data->mlx->wrslt / data->mlx->hrslt;
	data->c->fov_h = data->c->fov_h * M_PI / 180.0; 
	data->c->fov_v = data->c->fov_v * M_PI / 180.0; 
	ft_print_cam(data->c);
	ft_print_l(data->l);
	ft_print_sp(data->sp);
	mlx_loop_hook(data->mlx->init, rt_image, data);
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, mlx_key_press, data);
	mlx_hook(data->mlx->win, KeyRelease, KeyReleaseMask, mlx_key_release,
		data->mlx);
	mlx_hook(data->mlx->win, DestroyNotify, NoEventMask, rt_free, data);
	mlx_loop(data->mlx->init);
	return (0);
}

int main()
{
	t_miniRT *data;
	data  = malloc(sizeof(t_miniRT));
	data->garbage = NULL;
	// Camera
	data->c = malloc(sizeof(t_camera));
	data->garbage = gbg_add(data->garbage, data->c);
	data->c->coor = (Coor4f){0.0, 0.0, 0.0, 1};
	data->c->vector = (Vector4f){0.0, 0.0, 1.0, 0.0};
	data->c->fov_h = 160.0;
	// Lumiere Ambiante
	data->l = malloc(sizeof(t_light *) * 3);
	data->garbage = gbg_add(data->garbage, data->l);
	data->l[0] = malloc(sizeof(t_light));
	data->garbage = gbg_add(data->garbage, data->l[0]);
	data->l[0]->color = (Color4f){0.2, 255.0, 255.0, 255.0};
	// Lumiere Verte
	data->l[1] = malloc(sizeof(t_light));
	data->garbage = gbg_add(data->garbage, data->l[1]);
	data->l[1]->orgc = (Coor4f){25.0, 25.0, 25.0};
	data->l[1]->color = (Color4f){0.6, 0.0, 255.0, 0.0};
	// Lumiere Rouge
	data->l[2] = malloc(sizeof(t_light));
	data->garbage = gbg_add(data->garbage, data->l[1]);
	data->l[2]->orgc = (Coor4f){-25.0, -25.0, 25.0};
	data->l[2]->color = (Color4f){0.6, 255.0, 0.0, 0.0};
	// Lumiere Blanche
	data->l[3] = malloc(sizeof(t_light));
	data->garbage = gbg_add(data->garbage, data->l[1]);
	data->l[3]->orgc = (Coor4f){0.0, 0.0, 500.0};
	data->l[3]->color = (Color4f){0.5, 255.0, 255.0, 255.0};
	data->l[4] = NULL;
	// Sphere 0
	data->sp = malloc(sizeof(t_sphere *) * 3);
	data->garbage = gbg_add(data->garbage, data->sp);
	data->sp[0] = malloc(sizeof(t_sphere));
	data->garbage = gbg_add(data->garbage, data->sp[0]);
	data->sp[0]->orgc = (Coor4f){50.0, 50.0, 50.0};
	data->sp[0]->rayon = 10.0;
	data->sp[0]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
	// Sphere 1
	data->sp[1] = malloc(sizeof(t_sphere));
	data->garbage = gbg_add(data->garbage, data->sp[1]);
	data->sp[1]->orgc = (Coor4f){-50.0, -50.0, 50.0};
	data->sp[1]->rayon = 10.0;
	data->sp[1]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
	// Sphere 2
	data->sp[2] = malloc(sizeof(t_sphere));
	data->garbage = gbg_add(data->garbage, data->sp[2]);
	data->sp[2]->orgc = (Coor4f){-25.0, 25.0, 50.0};
	data->sp[2]->rayon = 10.0;
	data->sp[2]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
	// Sphere 3
	data->sp[3] = malloc(sizeof(t_sphere));
	data->garbage = gbg_add(data->garbage, data->sp[3]);
	data->sp[3]->orgc = (Coor4f){25.0, -25.0, 50.0};
	data->sp[3]->rayon = 10.0;
	data->sp[3]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
	// Sphere 4
	data->sp[4] = malloc(sizeof(t_sphere));
	data->garbage = gbg_add(data->garbage, data->sp[4]);
	data->sp[4]->orgc = (Coor4f){0.0, 0.0, 50.0};
	data->sp[4]->rayon = 10.0;
	data->sp[4]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
	data->sp[5] = NULL;
	minirt(data);
	return (0);
}
