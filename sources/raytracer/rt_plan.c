#include "../../includes/miniRT.h"

static float	ray_to_plane(Coor4f c_coor, Vector4f r_dir, t_plane *pl)
{
	Coor4f n = (Coor4f){((pl->vector.s0 + 1) * pl->coor.s0), ((pl->vector.s1 + 1) * pl->coor.s1), ((pl->vector.s2 + 1) * pl->coor.s2), 0};
	float a;
	float b;
	float c;
	
	if (r_dir.s0 == 0 || n.s0 == 0)
		a = 0;
	else
		a = (c_coor.s0 - pl->coor.s0 * n.s0) / (r_dir.s0 * n.s0);
	if (r_dir.s1 == 0 || n.s1 == 0)
		b = 0;
	else
		b = (c_coor.s1 - pl->coor.s1 * n.s1) / (r_dir.s1 * n.s1);
	if (r_dir.s2 == 0 || n.s2 == 0)
		c = 0;
	else
		c = (c_coor.s2 - pl->coor.s2 * n.s2) / (r_dir.s2 * n.s2);
	float	res = (a + b + c) * -1;
	return (res);
}

float	rt_intersection_pl(t_plane **pl, int *object, Coor4f c_coor, Vector4f r_dir)
{
	float			d;
	float			d_min;
	int	i;

	d_min = 0.0;
	*object = -1;
	i = 0;
	if (pl)
		while (pl[i])
		{
			d = ray_to_plane(c_coor, r_dir, pl[i]);
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
	Vector4f normal = p_intst - pl->coor;
	// normal.xyz /= sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    normalize(&normal);
	Color4f color;
	color.yzw = l[0]->color.x * (pl->color.yzw + l[0]->color.x * l[0]->color.yzw);
	int i = 1;
	while (l[i])
	{
		Vector4f l_vec = l[i]->coor - p_intst;
		// l_vec.xyz /= sqrtf(l_vec.x * l_vec.x + l_vec.y * l_vec.y + l_vec.z * l_vec.z);
        normalize(&l_vec);
		float angle = normal.x * l_vec.x + normal.y * l_vec.y + normal.z * l_vec.z;
		if (angle > 0.0 && angle <= M_PI / 2)
		{
			color.yzw += l[i]->color.x * l[i]->color.yzw * angle;
		}
		i++;
	}
	color.x = 1;
	color.y = (color.y > 255.0) ? 255.0 : color.y;
	color.z = (color.z > 255.0) ? 255.0 : color.z;
	color.w = (color.w > 255.0) ? 255.0 : color.w;
	return(trgb_color(color * color.x));
}