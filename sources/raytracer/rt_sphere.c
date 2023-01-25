#include "miniRT.h"

static float	ray_to_sphere(t_rayon r, t_sphere *sp)
{
	float	a = vt_dot(r.vector, r.vector);
	float	b = 2. * vt_dot(r.vector, (r.origin - sp->coor));
	float	c = vt_dot((r.origin - sp->coor), (r->origin - sp->coor)) - sp->rayon * sp->rayon;
	float	d = b * b - 4. * a * c;
	if (d < 0.)
		return (0.);
	float	sp->t1 = (-b - sqrtf(d)) / (2. * a);
	float	sp->t2 = (-b + sqrtf(d)) / (2. * a);
	if (sp->t1 > 0.)
		return (sp->t1);
	if (sp->t2 > 0.)
		return (sp->t2);
	return (0.);
}

float	rt_intersection_sp(t_rayon r ,t_sphere **sp, int *object)
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
			d = ray_to_sphere(r, sp[i]);
			if (d > 0 && (!d_min || d < d_min))
			{
				d_min = d;
				*object = i;
			}
			i++;
		}
	return (d_min);
}

int	rt_sphere(t_sphere *sp, Tuple4f orgc, Tuple4f ray, float t, t_light **l)
{
	Tuple4f	p_intst = orgc + t * ray;
	Tuple4f normal = p_intst - sp->coor;
    normalize(&normal);
	if (t < sp.rayon)
		normal = -normal;
	Tuple4f color;
	color.yzw = l[0]->color.x * (sp->color.yzw + l[0]->color.x * l[0]->color.yzw);
	int i = 1;
	while (l[i])
	{
		Tuple4f l_vec = l[i]->coor - p_intst;
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