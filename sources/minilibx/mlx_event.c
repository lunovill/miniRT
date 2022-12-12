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

int	mlx_key_press(int keycode, t_miniRT *main)
{
	if (keycode == XK_Escape)
		return (rt_free(main, 0));
	else if (main->mlx->key->up == 1 || main->mlx->key->right == 1
		|| main->mlx->key->down == 1 || main->mlx->key->left == 1)
		return (1);
	else if (keycode == XK_w || keycode == XK_Up)
		main->mlx->key->up = 1;
	else if (keycode == XK_d || keycode == XK_Right)
		main->mlx->key->right = 1;
	else if (keycode == XK_s || keycode == XK_Down)
		main->mlx->key->down = 1;
	else if (keycode == XK_a || keycode == XK_Left)
		main->mlx->key->left = 1;
	return (1);
}

int	mlx_key_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w || keycode == XK_Up)
		mlx->key->up = 2;
	else if (keycode == XK_d || keycode == XK_Right)
		mlx->key->right = 2;
	else if (keycode == XK_s || keycode == XK_Down)
		mlx->key->down = 2;
	else if (keycode == XK_a || keycode == XK_Left)
		mlx->key->left = 2;
	return (1);
}
