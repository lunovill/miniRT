#include "miniRT.h"

static float	ray_to_plane(Coor4f rorg, Vector4f rdrt, Coor4f pl, Vector4f normal)
{
	float x = rorg.x - pl.x; 
	float y = rorg.y - pl.y; 
	float z = rorg.z - pl.z; 
	float t = -((normal.x * x + normal.y * y + normal.z * z) / (normal.x * rdrt.x + normal.y * rdrt.y + normal.z * rdrt.z));
	if (t > 0.0)
		return (t);
	return (0.0);
}

// static float	ray_to_plane(Tuple4f c_coor, Tuple4f r_dir, t_plane *pl, Tuple4f normal)
// {
// 	float	res;
// 	float	a;
// 	float	b;
// 	float	c;

// 	if (r_dir.s0 == 0 || normal.s0 == 0)
// 		a = 0;
// 	else
// 		a = (c_coor.s0 - pl->coor.s0 * normal.s0) / (r_dir.s0 * normal.s0);
// 	if (r_dir.s1 == 0 || normal.s1 == 0)
// 		b = 0;
// 	else
// 		b = (c_coor.s1 - pl->coor.s1 * normal.s1) / (r_dir.s1 * normal.s1);
// 	if (r_dir.s2 == 0 || normal.s2 == 0)
// 		c = 0;
// 	else
// 		c = (c_coor.s2 - pl->coor.s2 * normal.s2) / (r_dir.s2 * normal.s2);
// 	res = (a + b + c) * -1;
// 	if (res > 0)
// 		return (res);
// 	return (0);
// }


float	rt_intersection_pl(t_plane **pl, int *object, Coor4f rorg, Vector4f rdrt)
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
			d = ray_to_plane(rorg, rdrt, pl[i]->coor, pl[i]->vector);
			if (d > 0 && (!d_min || d < d_min))
			{
				d_min = d;
				*object = i;
			}
			i++;
		}
	return (d_min);
}

// float	rt_intersection_pl(t_plane **pl, int *object, Tuple4f c_coor, Tuple4f r_dir)
// {
// 	float	d;
// 	float	d_min;
// 	int		i;

// 	d_min = 0.0;
// 	*object = -1;
// 	i = 0;
// 	if (pl)
// 		while (pl[i])
// 		{
// 			d = ray_to_plane(c_coor, r_dir, pl[i], pl[i]->vector);
// 			if (d > 0 && (!d_min || d < d_min))
// 			{
// 				d_min = d;
// 				*object = i;
// 			}
// 			i++;
// 		}
// 	return (d_min);
// }

static float distance(Coor4f p1, Coor4f p2)
{
	return (sqrtf((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z)));
}

int	rt_plane(t_miniRT *data, t_plane *pl, Coor4f orgc, Vector4f ray, float t, t_light **l)
{
	Coor4f	p_intst = orgc + t * ray;
	Coor4f	color;
	color.yzw = l[0]->color.x * (pl->color.ywz + l[0]->color.x * 
	l[0]->color.yzw);
	int i = 1;
	while (l[i])
	{
		Vector4f l_vec = l[i]->coor - p_intst;
		normalize(&l_vec);
		float angle = pl->vector.x * l_vec.x + pl->vector.y * l_vec.y + pl->vector.z * l_vec.z;
		if (angle > 0.0 && angle <= M_PI / 2)
		{
			float	shade = rt_shade(data, p_intst, l_vec);
			if (shade && shade < distance(p_intst, l[i]->coor))
				color.yzw -= color.yzw * l[i]->color.x * angle;
			else
				color.yzw += l[i]->color.x * l[i]->color.yzw * angle + (pl->color.yzw * l[i]->color.x * angle);
		}
		i++;
	}
	color.x = 1.0;
	color.y = (color.y > 255.0) ? 255.0 : color.y;
	color.z = (color.z > 255.0) ? 255.0 : color.z;
	color.w = (color.w > 255.0) ? 255.0 : color.w;
	return (trgb_color(color));
	(void)data;
}