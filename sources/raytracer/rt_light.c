/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:26:24 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 01:26:26 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tpl4f	rt_ambient(t_tpl4f color, t_light *l)
{
	t_tpl4f	ambient;

	ambient.x = l->color.x;
	ambient.yzw = (color.yzw) * (l->color.yzw) * l->color.x;
	return (ambient);
}

t_tpl4f	rt_diffuse(t_tpl4f color, t_tpl4f n_vec, t_tpl4f l_vec, t_light *l)
{
	t_tpl4f	diffuse;
	float	angle;

	angle = vt_dot(l_vec, n_vec);
	if (angle > 0. && angle <= M_PI / 2.)
	{
		diffuse.x = 1.;
		diffuse.yzw = (color.yzw) * (l->color.yzw) * l->color.x * angle;
	}
	else
		diffuse = 0.;
	return (diffuse);
}
