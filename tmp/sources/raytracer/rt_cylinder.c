#include "miniRT.h"

static float	ray_to_cylinder(Tuple4f c_coor, Tuple4f r_dir, t_cylinder *cy, Tuple4f normal)
{
	float	res0;
	float	res1;
	float	disc;
	float	a;
	float	b;
	float	c;

	(void)normal;
	(void)cy;
	a = (r_dir.s0 * r_dir.s0 + r_dir.s2 * r_dir.s2);
	b = (2 * c_coor.s0 * r_dir.s0) + (2 * c_coor.s2 * r_dir.s2);
	c = (c_coor.s0 * c_coor.s0) + (c_coor.s2 * c_coor.s2) - (cy->rayon * cy->rayon);
	// a = (r_dir.s0 * r_dir.s0) + (r_dir.s1 * r_dir.s1) - (r_dir.s2 * r_dir.s2);
	// b = 2 * (c_coor.s0 * r_dir.s0 + c_coor.s1 * r_dir.s1 - c_coor.s2 * r_dir.s2);
	// c = (c_coor.s0 * c_coor.s0) + (c_coor.s1 * c_coor.s1) - (c_coor.s2 * c_coor.s2) - (cy->rayon * cy->rayon);
	disc = (b * b) - 4 * a * c;
	if (disc < 0)
		return (0);
	res0 = ((b * -1) - sqrtf(disc)) / (2 * a);
	res1 = ((b * -1) + sqrtf(disc)) / (2 * a);
	if (res0 > 0.0)
		return (res0);
	if (res1 > 0.0)
		return (res1);
	return (0.0);
}

float	rt_intersection_cy(t_cylinder **cy, int *object, Tuple4f c_coor, Tuple4f r_dir)
{
	float	d;
	float	d_min;
	int		i;

	d_min = 0.0;
	*object = -1;
	i = 0;
	if (cy)
		while (cy[i])
		{
			d = ray_to_cylinder(c_coor, r_dir, cy[i], cy[i]->vector);
			if (d > 0 && (!d_min || d < d_min))
			{
				d_min = d;
				*object = i;
			}
			i++;
		}
	return (d_min);
}

int	rt_cylinder(t_miniRT *data, t_cylinder *cy, Tuple4f orgc, Tuple4f ray, float t, t_light **l)
{
	(void)data;
	Tuple4f	p_intst = orgc + t * ray;
	Tuple4f	color;
	color.yzw = l[0]->color.x * (cy->color.ywz + l[0]->color.x * 
	l[0]->color.yzw);
	int i = 1;
	while (l[i])
	{
		Tuple4f l_vec = l[i]->coor - p_intst;
		normalize(&l_vec);
		float angle = cy->vector.x * l_vec.x + cy->vector.y * l_vec.y + cy->vector.z * l_vec.z;
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