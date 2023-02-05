/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:39:11 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:39:13 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	mlx_key_press(int keycode, t_miniRT *data)
{
	if (keycode == XK_Escape)
		return (rt_free(data, 0));
	else if (data->mlx->key->up == 1 || data->mlx->key->right == 1
		|| data->mlx->key->down == 1 || data->mlx->key->left == 1)
		return (1);
	else if (keycode == XK_Up)
		data->mlx->key->up = 1;
	else if (keycode == XK_Right)
		data->mlx->key->right = 1;
	else if (keycode == XK_Down)
		data->mlx->key->down = 1;
	else if (keycode == XK_Left)
		data->mlx->key->left = 1;
	else if (keycode == XK_w)
		data->mlx->key->rot_up = 1;
	else if (keycode == XK_s)
		data->mlx->key->rot_down = 1;
	else if (keycode == XK_d)
		data->mlx->key->rot_right = 1;
	else if (keycode == XK_a)
		data->mlx->key->rot_left = 1;
	else if (keycode == K_Home)
		data->mlx->key->befor = 1;
	else if (keycode == K_End)
		data->mlx->key->behind = 1;
	return (1);
}

int	mlx_key_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Up)
		mlx->key->up = 2;
	else if (keycode == XK_Right)
		mlx->key->right = 2;
	else if (keycode == XK_Down)
		mlx->key->down = 2;
	else if (keycode == XK_Left)
		mlx->key->left = 2;
	else if (keycode == XK_w)
		mlx->key->rot_up = 2;
	else if (keycode == XK_s)
		mlx->key->rot_down = 2;
	else if (keycode == XK_d)
		mlx->key->rot_right = 2;
	else if (keycode == XK_a)
		mlx->key->rot_left = 2;
	else if (keycode == K_Home)
		mlx->key->befor = 2;
	else if (keycode == K_End)
		mlx->key->behind = 2;
	return (1);
}
