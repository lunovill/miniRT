/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:49:52 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/25 03:49:53 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_rayon	ry_projection(t_rayon r, t_cylinder *cy)
{
	t_mtx4f	prjt;
	t_rayon	new;

	cy->vector = vt_normalize(cy->vector);
	if (equalt(cy->vector, (t_tpl4f){0., 1., 0., 0.}))
	{
		prjt.s4567 = vt_cross((t_tpl4f){1., 0., 0., 0.}, cy->vector);
		prjt.s4567 = vt_normalize(prjt.s4567);
		prjt.s0123 = vt_cross(cy->vector, (t_tpl4f)prjt.s4567);
		prjt.s0123 = vt_normalize((t_tpl4f)prjt.s0123);
	}
	else
	{
		prjt.s0123 = vt_cross(cy->vector, (t_tpl4f){0., 1., 0., 0.});
		prjt.s0123 = vt_normalize(prjt.s0123);
		prjt.s4567 = vt_cross((t_tpl4f)prjt.s0123, cy->vector);
		prjt.s4567 = vt_normalize((t_tpl4f)prjt.s4567);
	}
	prjt.s89ab = cy->vector;
	prjt.s37bf = (t_tpl4f){0., 0., 0., 1.};
	prjt.scdef = (t_tpl4f){0., 0., 0., 1.};
	new.origin = mt_cross_tp(&prjt, r.origin);
	new.vector = mt_cross_tp(&prjt, r.vector);
	return (new);
}

static float	ray_to_cylinder(t_rayon r, t_cylinder *cy)
{
	float	tab[6];

	tab[0] = r.vector.x * r.vector.x + r.vector.y * r.vector.y;
	tab[1] = 2. * (r.vector.x * (r.origin.x - cy->coor.x)
			+ r.vector.y * (r.origin.y - cy->coor.y));
	tab[2] = (r.origin.x - cy->coor.x) * (r.origin.x - cy->coor.x) + (r.origin.y
			- cy->coor.y) * (r.origin.y - cy->coor.y) - cy->rayon * cy->rayon;
	tab[3] = tab[1] * tab[1] - 4. * tab[0] * tab[2];
	if (tab[3] < 0.)
		return (0.);
	cy->t1 = (-tab[1] - sqrtf(tab[3])) / (2. * tab[0]);
	cy->t2 = (-tab[1] + sqrtf(tab[3])) / (2. * tab[0]);
	if (cy->t1 > 0.)
	{
		tab[4] = (r.origin.z - cy->coor.z) + cy->t1 * r.vector.z;
		if (tab[4] >= -cy->height / 2. && tab[4] <= cy->height / 2.)
			return (cy->t1);
	}
	if (cy->t2 > 0.)
	{
		tab[5] = (r.origin.z - cy->coor.z) + cy->t2 * r.vector.z;
		if (tab[5] > -cy->height / 2. && tab[5] <= cy->height / 2.)
			return (cy->t2);
	}
	return (0.);
}

float	rt_intersection_cy(t_rayon r, t_cylinder **cy, int *object)
{
	float	d;
	float	d_min;
	int		i;

	d_min = 0.0;
	*object = -1;
	i = 0;
	if (cy)
	{
		while (cy[i])
		{
			d = ray_to_cylinder(ry_projection(r, cy[i]), cy[i]);
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

int	rt_cylinder(t_miniRT *data, t_cylinder *cy, t_tpl4f point)
{
	t_tpl4f	color;
	t_rayon	r;
	float	shadow;
	int		i;

	cy->normal = vt_normalize(vt_normalize(point - cy->coor) - vt_dot(vt_normalize(point - cy->coor), cy->vector) * cy->vector);
	if (vt_dot(cy->normal, data->c->view.s37bf - point) < 0)
		cy->normal = -cy->normal;
		// return (255);
	point += cy->normal * EPSILON * 100.;
	color = rt_ambient(cy->color, data->l[0]);
	i = 0;
	while (data->l[++i])
	{
		r = ry_init(point, vt_normalize(data->l[i]->coor - point));
		shadow = rt_shadow(data, r);
		if (!(shadow && shadow < vt_magnitude(data->l[i]->coor - point)))
			color += rt_diffuse(cy->color, cy->normal, r.vector, data->l[i]);
	}
	return (trgb_color(color));
}
