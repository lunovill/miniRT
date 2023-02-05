/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:15:25 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 02:15:27 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	ray_to_sphere(t_rayon r, t_sphere *sp)
{
	float	a;
	float	b;
	float	c;
	float	d;

	a = vt_dot(r.vector, r.vector);
	b = 2. * vt_dot(r.vector, (r.origin - sp->coor));
	c = vt_dot((r.origin - sp->coor),
			(r.origin - sp->coor)) - sp->rayon * sp->rayon;
	d = b * b - 4. * a * c;
	if (d < 0.)
		return (0.);
	sp->t1 = (-b - sqrtf(d)) / (2. * a);
	sp->t2 = (-b + sqrtf(d)) / (2. * a);
	if (sp->t1 > 0.)
		return (sp->t1);
	if (sp->t2 > 0.)
		return (sp->t2);
	return (0.);
}

float	rt_intersection_sp(t_rayon r, t_sphere **sp, int *object)
{
	float	d;
	float	d_min;
	int		i;

	d_min = 0.0;
	*object = -1;
	i = 0;
	if (sp)
	{
		while (sp[i])
		{
			d = ray_to_sphere(r, sp[i]);
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

int	rt_sphere(t_miniRT *data, t_sphere *sp, t_tpl4f point, float t)
{
	t_tpl4f	color;
	t_tpl4f	diffuse;
	t_rayon	r;
	float	shadow;
	int		i;

	sp->vector = vt_normalize(point - sp->coor);
	if (t < sp->rayon)
		sp->vector = -sp->vector;
	point += sp->vector * EPSILON * 100.;
	color = rt_ambient(sp->color, data->l[0]);
	i = 0;
	while (data->l[++i])
	{
		r = ry_init(point, vt_normalize(data->l[i]->coor - point));
		shadow = rt_shadow(data, r);
		if (!(shadow && shadow < vt_magnitude(data->l[i]->coor - point)))
		{
			diffuse = rt_diffuse(sp->color, sp->vector, r.vector, data->l[i]);
			if (diffuse.x)
				color += diffuse + rt_specular(
						sp->vector, r.vector, data->c->view.s89ae, data->l[i]);
		}
	}
	return (trgb_color(color));
}
