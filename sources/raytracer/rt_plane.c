#include "miniRT.h"


static float	ray_to_plane(Tuple4f c_coor, Tuple4f r_dir, t_plane *pl, Tuple4f normal)
{
	float	res;
	float	a;
	float	b;
	float	c;

	if (r_dir.s0 == 0 || normal.s0 == 0)
		a = 0;
	else
		a = (c_coor.s0 - pl->coor.s0 * normal.s0) / (r_dir.s0 * normal.s0);
	if (r_dir.s1 == 0 || normal.s1 == 0)
		b = 0;
	else
		b = (c_coor.s1 - pl->coor.s1 * normal.s1) / (r_dir.s1 * normal.s1);
	if (r_dir.s2 == 0 || normal.s2 == 0)
		c = 0;
	else
		c = (c_coor.s2 - pl->coor.s2 * normal.s2) / (r_dir.s2 * normal.s2);
	res = (a + b + c) * -1;
	if (res > 0)
		return (res);
	return (0);
}

float	rt_intersection_pl(t_plane **pl, int *object, Tuple4f c_coor, Tuple4f r_dir)
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
			d = ray_to_plane(c_coor, r_dir, pl[i], pl[i]->vector);
			if (d > 0 && (!d_min || d < d_min))
			{
				d_min = d;
				*object = i;
			}
			i++;
		}
	return (d_min);
}

int	rt_plane(t_plane *pl, Tuple4f orgc, Tuple4f ray, float t, t_light **l)
{
	Tuple4f	p_intst = orgc + t * ray;
	Tuple4f	color;
	color.yzw = l[0]->color.x * (pl->color.ywz + l[0]->color.x * 
	l[0]->color.yzw);
	int i = 1;
	while (l[i])
	{
		Tuple4f l_vec = l[i]->coor - p_intst;
		normalize(&l_vec);
		float angle = pl->vector.x * l_vec.x + pl->vector.y * l_vec.y + pl->vector.z * l_vec.z;
		if (angle > 0.0 && angle <= M_PI / 2)
			color.yzw += l[i]->color.x * l[i]->color.yzw * angle;
		i++;
	}
	color.x = 1;
	color.y = (color.y > 255.0) ? 255.0 : color.y;
	color.z = (color.z > 255.0) ? 255.0 : color.z;
	color.w = (color.w > 255.0) ? 255.0 : color.w;
	return (trgb_color(color));
}