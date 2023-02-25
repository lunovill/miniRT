/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:04:57 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 01:04:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rt_intersection(t_miniRT *data, t_rayon r)
{
	int		i;
	int		object[OBJETS];
	float	d_min;
	float	d[OBJETS];

	i = 1;
	d[SPHERE] = rt_intersection_sp(r, data->sp, &object[SPHERE]);
	d[CYLINDER] = rt_intersection_cy(r, data->cy, &object[CYLINDER]);
	d[PLANE] = rt_intersection_pl(r, data->pl, &object[PLANE]);
	d_min = d[SPHERE];
	if (d[CYLINDER] && (!d_min || d[CYLINDER] < d_min))
		d_min = d[CYLINDER];
	if (d[PLANE] && (!d_min || d[PLANE] < d_min))
		d_min = d[2];
	if (d_min && d_min == d[SPHERE])
		return (rt_sphere(data, data->sp[object[SPHERE]],
				ry_distance(r, d_min)));
	else if (d_min && d_min == d[CYLINDER])
		return (rt_cylinder(data, data->cy[object[CYLINDER]],
				ry_distance(r, d_min)));
	else if (d_min && d_min == d[PLANE])
		return (rt_plane(data, data->pl[object[PLANE]],
				ry_distance(r, d_min)));
	return (0);
}
