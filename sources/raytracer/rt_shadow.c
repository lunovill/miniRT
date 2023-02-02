#include "miniRT.h"

float	rt_shadow(t_miniRT *data, t_rayon r)
{
	float	d[OBJETS];
	int		object[OBJETS];
	float	d_min;

	d[SPHERE] = 0.0;
	object[SPHERE] = -1;
	if (data->sp)
		d[SPHERE] = rt_intersection_sp(r, data->sp, &object[SPHERE]);
	// d[CYLINDER] = 0.0;
	// object[1] = -1;
	// if (data->cy)
	// 	d[CYLINDER] = rt_intersectio_cy(r, data->cy, &object[CYLINDER]);
	d[PLANE] = 0.0;
	object[PLANE] = -1;
	if (data->pl)
		d[PLANE] = rt_intersection_pl(r, data->pl, &object[PLANE]);
	d_min = d[SPHERE];
	// if (d[CYLINDER] && (!d_min || d[CYLINDER] < d_min))
	// 	d_min = d[CYLINDER];	
	if (d[PLANE] && (!d_min || d[PLANE] < d_min))
		d_min = d[PLANE];
    return (d_min);
}