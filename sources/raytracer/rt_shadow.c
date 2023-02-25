/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:13:15 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 02:13:17 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	rt_shadow(t_miniRT *data, t_rayon r)
{
	float	d[OBJETS];
	int		object[OBJETS];
	float	d_min;

	d_min = 0.;
	if (data->sp)
		d[SPHERE] = rt_intersection_sp(r, data->sp, &object[SPHERE]);
	if (data->cy)
		d[CYLINDER] = rt_intersection_cy(r, data->cy, &object[CYLINDER]);
	if (data->pl)
		d[PLANE] = rt_intersection_pl(r, data->pl, &object[PLANE]);
	d_min = d[SPHERE];
	if (d[CYLINDER] && (!d_min || d[CYLINDER] < d_min))
		d_min = d[CYLINDER];
	if (d[PLANE] && (!d_min || d[PLANE] < d_min))
		d_min = d[PLANE];
	return (d_min);
}
