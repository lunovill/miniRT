#include "miniRT.h"

int	rt_intersection(t_miniRT *data, t_rayon r)
{
	float	d[3];
	int		object[3];
	float	d_min;
	int		color;
	int i;

	i = 1;
	color = 0;
	d[0] = 0.0;
	object[0] = -1;
	if (data->sp)
		d[0] = rt_intersection_sp(r, data->sp, &object[0]);
	// d[1] = 0.0;
	// object[1] = -1;
	// if (data->cy)
	// 	d[1] = rt_intersection_cy(r, data->cy, &object[1]);
	d[2] = 0.0;
	object[2] = -1;
	if (data->pl)
		d[2] = rt_intersection_pl(r, data->pl, &object[2]);
	d_min = d[0];
	// if (d[1] && (!d_min || d[1] < d_min))
	// 	d_min = d[1];	
	if (d[2] && (!d_min || d[2] < d_min))
		d_min = d[2];
	if (d_min && d_min == d[0])
		color = rt_sphere(data, data->sp[object[0]], tp_rayon(r, d_min), d_min);
	// else if (d_min && d_min == d[1])
	// 	color = rt_cylinder(data->cy[object[1]], rorg, rdrt, d_min, data->l);
	else if (d_min && d_min == d[2])
		color = rt_plane(data, data->pl[object[2]], tp_rayon(r, d_min));
	// else
	// 	color = trgb_color(data->l[0]->color * data->l[0]->color.x);
	return (color);
}