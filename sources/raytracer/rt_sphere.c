#include "miniRT.h"


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

int	rt_sphere(t_miniRT *data, t_sphere *sp, Tuple4f point, float t)
{
	Tuple4f color;
	Tuple4f	diffuse;
	Tuple4f n_vec;
	Tuple4f l_vec;

	n_vec = vt_normalize(point - sp->coor);
	if (t < sp->rayon)
		n_vec = -n_vec;
	color = rt_ambient(sp->color, data->l[0]);
	// printf("%f %f %f %f\n", color.x, color.y, color.z, color.w);
	int i = 1;
	while (data->l[i])
	{
		l_vec = vt_normalize(data->l[i]->coor - point);
		diffuse = rt_diffuse(sp->color, n_vec, l_vec, data->l[i]);
		if (diffuse.x)
			color += diffuse + rt_specular(n_vec, l_vec, data->c->vector, data->l[i]);
		i++;
	}
	color.x = 1.;
	// printf("%f %f %f %f\n", color.x, color.y, color.z, color.w);
	// exit (42);
	return(trgb_color(color));
}