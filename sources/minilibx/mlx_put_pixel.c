/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:39:40 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:39:41 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxRT.h"

void	mlx_put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->sline + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
