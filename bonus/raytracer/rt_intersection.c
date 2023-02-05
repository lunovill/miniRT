#include "miniRT.h"

int	rt_intersection(t_miniRT *data, t_rayon r)
{
	float	d[OBJETS];
	int		object[OBJETS];
	float	d_min;
	int		color;
	int i;

	i = 1;
	color = 0;
	d[SPHERE] = 0.0;
	object[SPHERE] = -1;
	if (data->sp)
		d[SPHERE] = rt_intersection_sp(r, data->sp, &object[SPHERE]);
	// if (d[0])
		// printf("sp = %f i = %i\n", d[0], object[0]);
	// d[CYLINDER] = 0.0;
	// object[CYLINDER] = -1;
	// if (data->cy)
	// 	d[1] = rt_intersection_cy(r, data->cy, &object[CYLINDER]);
	d[PLANE] = 0.0;
	object[PLANE] = -1;
	if (data->pl)
		d[PLANE] = rt_intersection_pl(r, data->pl, &object[PLANE]);
	d_min = d[SPHERE];
	// if (d[CYLINDER] && (!d_min || d[CYLINDER] < d_min))
	// 	d_min = d[CYLINDER];	
	if (d[PLANE] && (!d_min || d[PLANE] < d_min))
		d_min = d[2];
	if (d_min && d_min == d[SPHERE])
		color = rt_sphere(data, data->sp[object[SPHERE]], tp_rayon(r, d_min), d_min);
	// else if (d_min && d_min == d[CYLINDER])
	// 	color = rt_cylinder(data->cy[object[CYLINDER]], rorg, rdrt, d_min, data->l);
	else if (d_min && d_min == d[PLANE])
		color = rt_plane(data, data->pl[object[PLANE]], tp_rayon(r, d_min), d_min);
	// else
	// 	color = trgb_color(data->l[0]->color * data->l[0]->color.x);
	return (color);
}