#include "miniRT.h"


static float	rt_intersection_cy(t_cylinder **cy, int *object, Coor4f rorg, Vector4f rdrt)
{
	return (0.0);
	object = 0;
	(void)cy;
	(void)rorg;
	(void)rdrt;
}

static float	rt_intersection_pl(t_plane **pl, int *object, Coor4f rorg, Vector4f rdrt)
{
	return (0.0);
	object = 0;
	(void)pl;
	(void)rorg;
	(void)rdrt;
}

int	rt_cylinder(t_cylinder *cy)
{
	return (0);
	(void)cy;
}

int	rt_plane(t_plane *pl)
{
	return (0);
	(void)pl;
}

int	rt_intersection(t_miniRT *data, Coor4f rorg, Vector4f rdrt)
{
	float	d[3];
	int		object[3];
	float	d_min;
	int		color;

	d[0] = 0.0;
	object[0] = -1;
	if (data->sp)
		d[0] = rt_intersection_sp(data->sp, &object[0], rorg, rdrt);
	d[1] = 0.0;
	object[1] = -1;
	if (data->cy)
		d[1] = rt_intersection_cy(data->cy, &object[1], rorg, rdrt);
	d[2] = 0.0;
	object[2] = -1;
	if (data->pl)
		d[2] = rt_intersection_pl(data->pl, &object[2], rorg, rdrt);
	d_min = d[0];
	if (d[1] && (!d_min || d[1] < d_min))
		d_min = d[1];	
	if (d[2] && (!d_min || d[2] < d_min))
		d_min = d[2];
	if (d_min && d_min == d[0])
		color = rt_sphere(data->sp[object[0]], rorg, rdrt, d_min, data->l);
	else if (d_min && d_min == d[1])
		color = rt_cylinder(data->cy[object[1]]);
	else if (d_min && d_min == d[2])
		color = rt_plane(data->pl[object[2]]);
	else
		color = trgb_color(data->l[0]->color * data->l[0]->color.x);
	return (color);
}