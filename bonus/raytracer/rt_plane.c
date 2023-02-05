#include "miniRT.h"

static float	ray_to_plane(t_rayon r, t_plane *pl)
{
	float x = r.origin.x - pl->coor.x; 
	float y = r.origin.y - pl->coor.y; 
	float z = r.origin.z - pl->coor.z; 
	float t = -(vt_dot(pl->vector, (Tuple4f){x, y, z, 0}) / vt_dot(pl->vector, r.vector));
	if (t > 0.)
		return (t);
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
	return (d_min);
}

int	rt_plane(t_miniRT *data, t_plane *pl, Tuple4f point, float t)
{
	Tuple4f	color;
	Tuple4f	diffuse;
	Tuple4f l_vec;

	point += pl->vector * EPSILON;
	color = rt_ambient(pl->color, data->l[0]);
	int i = 1;
	while (data->l[i])
	{
		l_vec = data->l[i]->coor - point;
		t_rayon r;
		r.origin = point;
		r.vector = vt_normalize(l_vec);
		if (vt_dot(pl->vector, r.vector) < 0)
			pl->vector = -pl->vector;
		if (vt_dot(pl->vector, data->c->view.s37bf - point) < 0)
			pl->vector = -pl->vector;
		float shadow = rt_shadow(data, r);
		if (!(shadow && shadow < vt_magnitude(l_vec)))
		{
			l_vec = r.vector;
			diffuse = rt_diffuse(pl->color, pl->vector, l_vec, data->l[i]);
			if (diffuse.x)
				color += diffuse;// + rt_specular(pl->vector, l_vec, data->c->view.s89ae, data->l[i]);
		}
		i++;
	}
	color.x = 1.;
	return (trgb_color(color));
	(void)t;
}