#include "miniRT.h"


static float	ray_to_sphere(t_rayon r, t_sphere *sp)
{
	float		t1;
	float		t2;

	float	a = vt_dot(r.vector, r.vector);
	float	b = 2. * vt_dot(r.vector, (r.origin - sp->coor));
	float	c = vt_dot((r.origin - sp->coor), (r.origin - sp->coor)) - sp->rayon * sp->rayon;
	float	d = b * b - 4. * a * c;
	if (d < 0.)
		return (0.);
	t1 = (-b - sqrtf(d)) / (2. * a);
	t2 = (-b + sqrtf(d)) / (2. * a);
	if (t1 > 0.)
		return (t1);
	if (t2 > 0.)
		return (t2);
	return (0.);
}

float	rt_intersection_sp(t_rayon r, t_sphere **sp, int *object)
{
	float			d;
	float			d_min;
	int	i;

	d_min = 0.0;
	*object = -1;
	i = 0;
	if (sp)
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
	return (d_min);
}

int	rt_sphere(t_miniRT *data, t_sphere *sp, Tuple4f point, float t)
{
	Tuple4f color;
	Tuple4f	diffuse;
	Tuple4f n_vec;
	Tuple4f l_vec;

	n_vec = vt_normalize(point - sp->coor);
	if (t < sp->rayon)
		n_vec = -n_vec;
	point += n_vec * EPSILON * 100.;
	color = rt_ambient(sp->color, data->l[0]);
	int i = 1;
	while (data->l[i])
	{
		l_vec = data->l[i]->coor - point;
		t_rayon r;
		r.origin = point;
		r.vector = vt_normalize(l_vec);
		float shadow = rt_shadow(data, r);
		if (!(shadow && shadow < vt_magnitude(l_vec)))
		{
			l_vec = r.vector;
			diffuse = rt_diffuse(sp->color, n_vec, l_vec, data->l[i]);
			if (diffuse.x)
				color += diffuse + rt_specular(n_vec, l_vec, data->c->view.s89ae, data->l[i]);
		}
		i++;
	}
	color.x = 1.;
	return(trgb_color(color));
}