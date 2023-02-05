/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:06:58 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 03:06:59 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	trgb_max(float c)
{
	if (c > 255.)
		return (255);
	return (c);
}

int	trgb_color(t_tpl4f color)
{
	int	r;
	int	g;
	int	b;

	color.x = 1.;
	color.yzw *= 255.;
	color.y = trgb_max(color.y);
	color.z = trgb_max(color.z);
	color.w = trgb_max(color.w);
	r = color.y;
	g = color.z;
	b = color.w;
	return (r << 16 | g << 8 | b);
}
