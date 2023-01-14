#include "miniRT.h"

static float	ray_to_sphere(Coor4f rorg, Vector4f rdrt, Coor4f sp, float r)
{
	float	a = rdrt.x * rdrt.x + rdrt.y * rdrt.y + rdrt.z * rdrt.z;
	float	b = 2.0 * (rdrt.x * (rorg.x - sp.x) + rdrt.y * (rorg.y - sp.y) + rdrt.z * (rorg.z - sp.z));
	float	c = (rorg.x - sp.x) * (rorg.x - sp.x) + (rorg.y - sp.y) * (rorg.y - sp.y) + (rorg.z - sp.z) * (rorg.z - sp.z) - r * r;
	float	d = b * b - 4.0 * a * c;
	float	t1 = (-b - sqrtf(d)) / (2.0 * a);
	float	t2 = (-b + sqrtf(d)) / (2.0 * a);
	if (t1 > 0.0)
		return (t1);
	if (t2 > 0.0)
		return (t2);
	return (0.0);
}

float	rt_intersection_sp(t_sphere **sp, int *object, Coor4f rorg, Vector4f rdrt)
{
	float			d;
	float			d_min;
	int	i;

	d_min = 0.0;
	*object = -1;
	i = 0;
	if (sp)
		while (sp[i])
		{
			d = ray_to_sphere(rorg, rdrt, sp[i]->coor, sp[i]->rayon);
			if (d > 0 && (!d_min || d < d_min))
			{
				d_min = d;
				*object = i;
			}
			i++;
		}
	return (d_min);
}

int	rt_sphere(t_sphere *sp, Coor4f orgc, Vector4f ray, float t, t_light **l)
{
	Coor4f	p_intst = orgc + t * ray;
	Vector4f normal = p_intst - sp->coor;
    normalize(&normal);
	Color4f color;
	color.yzw = l[0]->color.x * (sp->color.yzw + l[0]->color.x * l[0]->color.yzw);
	int i = 1;
	while (l[i])
	{
		Vector4f l_vec = l[i]->coor - p_intst;
        normalize(&l_vec);
		float angle = normal.x * l_vec.x + normal.y * l_vec.y + normal.z * l_vec.z;
		if (angle > 0.0 && angle <= M_PI / 2)
			color.yzw += l[i]->color.x * l[i]->color.yzw * angle;
		i++;
	}
	color.x = 1;
	color.y = (color.y > 255.0) ? 255.0 : color.y;
	color.z = (color.z > 255.0) ? 255.0 : color.z;
	color.w = (color.w > 255.0) ? 255.0 : color.w;
	return(trgb_color(color));
}