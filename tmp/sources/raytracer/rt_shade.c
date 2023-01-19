#include "miniRT.h"

static float	rt_intersectio_cy(t_cylinder **cy, int *object, Coor4f rorg, Vector4f rdrt)
{
	return (0.0);
	object = 0;
	(void)cy;
	(void)rorg;
	(void)rdrt;
}

float	rt_shade(t_miniRT *data, Coor4f rorg, Vector4f rdrt)
{
	float	d[3];
	int		object[3];
	float	d_min;

	d[0] = 0.0;
	object[0] = -1;
	if (data->sp)
		d[0] = rt_intersection_sp(data->sp, &object[0], rorg, rdrt);
	d[1] = 0.0;
	object[1] = -1;
	if (data->cy)
		d[1] = rt_intersectio_cy(data->cy, &object[1], rorg, rdrt);
	d[2] = 0.0;
	object[2] = -1;
	if (data->pl)
		d[2] = rt_intersection_pl(data->pl, &object[2], rorg, rdrt);
	d_min = d[0];
	if (d[1] && (!d_min || d[1] < d_min))
		d_min = d[1];	
	if (d[2] && (!d_min || d[2] < d_min))
		d_min = d[2];
    return (d_min);
}