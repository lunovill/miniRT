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

int	rt_plane(t_plane *pl, Coor4f orgc, Vector4f ray, float t, t_light **l)
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
			color.yzw += l[i]->color.x * l[i]->color.yzw * angle;
		i++;
	}
	color.x = 1;
	color.y = (color.y > 255.0) ? 255.0 : color.y;
	color.z = (color.z > 255.0) ? 255.0 : color.z;
	color.w = (color.w > 255.0) ? 255.0 : color.w;
	return (trgb_color(color));
}