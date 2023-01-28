#include "miniRT.h"
# define DIFFUSE 0.9 // Entre 0 et 1
# define SPECULAR 0.9 // Entre 0 et 1
# define SHININESS 200.0 // Entre 10 et 200


static float	ray_to_sphere(t_rayon r, t_sphere *sp)
{
	float	a = vt_dot(r.vector, r.vector);
	float	b = 2. * vt_dot(r.vector, (r.origin - sp->coor));
	float	c = vt_dot((r.origin - sp->coor), (r.origin - sp->coor)) - sp->rayon * sp->rayon;
	float	d = b * b - 4. * a * c;
	if (d < 0.)
		return (0.);
	sp->t1 = (-b - sqrtf(d)) / (2. * a);
	sp->t2 = (-b + sqrtf(d)) / (2. * a);
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

// int	rt_sphere(t_sphere *sp, Tuple4f point, Tuple4f forward,  t_light **l, int i)
// {
// 	Tuple4f	normal;
// 	Tuple4f color;
// 	Tuple4f ambient;
// 	Tuple4f diffuse;
// 	Tuple4f specular;
// 	Tuple4f l_vec;
// 	float	angle;
// 	float	a_reflect;
// 	Tuple4f	reflect;

// 	normal = vt_normalize(point - sp->coor);
// 	color.x  = l[i]->color.x;
// 	color.yzw = sp->color.yzw / 255.0;
// 	l_vec = vt_normalize(l[i]->coor - point);
// 	ambient.x = l[0]->color.x;
// 	ambient.yzw = color.yzw * l[0]->color.yzw / 255.0;
// 	angle = vt_dot(l_vec, normal);
// 	if (angle > 0.0 && M_PI / 2.0)
// 	{
// 		diffuse.x = l[i]->color.x * angle;
// 		diffuse.yzw = l[i]->color.yzw;
// 		reflect = -l_vec - normal * 2.0 * vt_dot(-l_vec, normal);
// 		a_reflect = vt_dot(reflect, forward);
// 		if (a_reflect <= 0.0)
// 			specular = 0.0;
// 		else
// 		{
// 			specular.x = l[i]->color.x * l[i]->color.x * powf(a_reflect, SHININESS);
// 			specular.yzw = l[i]->color.yzw / 255.0;
// 		}
// 	}
// 	else
// 	{
// 		diffuse = 0.0;
// 		specular = 0.0;
// 	}
// 	ambient.yzw *= 255.0;
// 	diffuse.yzw *= 255.0;
// 	// printf("%f %f %f %f\n", ambient.x, ambient.y, ambient.z, ambient.w);
// 	return (trgb_color(ambient) + trgb_color(diffuse));
// }

int	rt_sphere(t_sphere *sp, t_rayon r, float t, t_light **l)
{
	Tuple4f	p_intst = r.origin + t * r.vector;
	Tuple4f normal = p_intst - sp->coor;
    normal = vt_normalize(normal);
	if (t < sp->rayon)
		normal = -normal;
	Tuple4f color;
	color.yzw = (sp->color.yzw / 255.0) * (l[0]->color.yzw / 255.0) * l[0]->color.x;
	color *= 255.0;
	int i = 1;
	while (l[i])
	{
		Tuple4f l_vec = l[i]->coor - p_intst;
        l_vec = vt_normalize(l_vec);
		float angle = vt_dot(l_vec, normal);
		if (angle > 0. && angle <= M_PI / 2.)
			color.yzw += l[i]->color.x * l[i]->color.yzw * angle;
		i++;
	}
	color.x = 1.;
	color.y = (color.y > 255.0) ? 255.0 : color.y;
	color.z = (color.z > 255.0) ? 255.0 : color.z;
	color.w = (color.w > 255.0) ? 255.0 : color.w;
	return(trgb_color(color));
}