/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:27:27 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 01:27:31 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	ray_to_plane(t_rayon r, t_plane *pl)
{
	float	x;
	float	y;
	float	z;

	x = r.origin.x - pl->coor.x;
	y = r.origin.y - pl->coor.y;
	z = r.origin.z - pl->coor.z;
	pl->t = -(vt_dot(pl->vector, (Tuple4f){x, y, z, 0})
			/ vt_dot(pl->vector, r.vector));
	if (pl->t > 0.)
		return (pl->t);
	return (0.);
}

float	rt_intersection_pl(t_rayon r, t_plane **pl, int *object)
{
	float	d;
	float	d_min;
	int		i;

	d_min = 0.0;
	*object = -1;
	i = 0;
	if (pl)
	{
		while (pl[i])
		{
			d = ray_to_plane(r, pl[i]);
			if (d > 0 && (!d_min || d < d_min))
			{
				d_min = d;
				*object = i;
			}
			i++;
		}
	}
	return (d_min);
}

int	rt_plane(t_miniRT *data, t_plane *pl, Tuple4f point)
{
	int		i;
	float	shadow;
	Tuple4f	color;
	Tuple4f	diffuse;
	t_rayon	r;

	point += pl->vector * EPSILON;
	color = rt_ambient(pl->color, data->l[0]);
	i = 0;
	while (data->l[++i])
	{
		r.origin = point;
		r.vector = vt_normalize(data->l[i]->coor - point);
		if (vt_dot(pl->vector, data->c->view.s37bf - point) < 0)
			pl->vector = -pl->vector;
		shadow = rt_shadow(data, r);
		if (!(shadow && shadow < vt_magnitude(data->l[i]->coor - point)))
		{
			diffuse = rt_diffuse(pl->color, pl->vector, r.vector, data->l[i]);
			if (diffuse.x)
				color += diffuse + rt_specular(
						pl->vector, r.vector, data->c->view.s89ae, data->l[i]);
		}
	}
	return (trgb_color(color));
}
