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
	prjt.s37bf = cy->coor;
	prjt.scdef = (t_tpl4f){0., 0., 0., 1.};
	new.origin = mt_cross_tp(&prjt, r.origin);
	new.vector = mt_cross_tp(&prjt, r.vector);
	return (new);
}

static float	ray_to_cylinder(t_rayon r, t_cylinder *cy)
{
	float	a;
	float	b;
	float	c;
	float	d;

	a = r.vector.x * r.vector.x + r.vector.y * r.vector.y;
	b = 2. * (r.vector.x * (r.origin.x - cy->coor.x) + r.vector.y * (r.origin.y - cy->coor.y));
	c = (r.origin.x - cy->coor.x) * (r.origin.x - cy->coor.x) + (r.origin.y - cy->coor.y) * (r.origin.y - cy->coor.y) -  cy->rayon * cy->rayon;

	d = b * b - 4. * a * c;
	if (d < 0.)
		return (0.);
	cy->t1 = (-b - sqrtf(d)) / (2. * a);
	cy->t2 = (-b + sqrtf(d)) / (2. * a);
	if (cy->t1 > 0.)
	{
		float z1 = (r.origin.z - cy->coor.z) + cy->t1 * r.vector.z;
		if (z1 >= -cy->height / 2. && z1 <= cy->height / 2.)
			return (cy->t1);
	}
	if (cy->t2 > 0.)
	{
		float z2 = (r.origin.z - cy->coor.z) + cy->t2 * r.vector.z;
		if (z2 > -cy->height / 2. && z2 <= cy->height / 2.)
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

int	rt_cylinder(t_miniRT *data, t_cylinder *cy, t_tpl4f point, float t)
{
	t_tpl4f	color;
	t_rayon	r;
	float	shadow;
	int		i;

	cy->normal = vt_normalize(point - vt_dot(point, cy->vector) * cy->vector);
	if (vt_dot(cy->normal, data->c->view.s37bf - point) < 0)
		point -= cy->normal * EPSILON * 100;
	else
		point += cy->normal * EPSILON * 100;
	color = rt_ambient(cy->color, data->l[0]);
	i = 0;
	while (data->l[++i])
	{
		r = ry_init(point, vt_normalize(data->l[i]->coor - point));
		shadow = rt_shadow(data, r);
		if (vt_dot(cy->normal, data->c->view.s37bf - point) < 0)
			cy->normal = -cy->normal;
		if (!(shadow && shadow < vt_magnitude(data->l[i]->coor - point)))
			color += rt_diffuse(cy->color, cy->normal, r.vector, data->l[i]);
	}
	return (trgb_color(color));
	(void)t;
}