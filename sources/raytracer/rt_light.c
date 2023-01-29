#include "miniRT.h"
# define SHININESS 200.0 // Entre 10 et 200

Tuple4f	rt_ambient(Tuple4f color, t_light *l)
{
	Tuple4f ambient;
	ambient.x = l->color.x;
	// ambient.yzw = color.yzw * l->color.yzw * l->color.x;
	ambient.yzw = (color.yzw / 255.) * (l->color.yzw / 255.) * l->color.x;
	return (ambient);
	// return (0.);
}

Tuple4f	rt_diffuse(Tuple4f color, Tuple4f n_vec, Tuple4f l_vec, t_light *l)
{
	Tuple4f	diffuse;
	float angle;

	angle = vt_dot(l_vec, n_vec);
	if (angle > 0.)
	{
		diffuse.x = 1.;
		// diffuse.yzw = color.yzw * l->color.yzw * l->color.x * angle;
		diffuse.yzw = (color.yzw / 255.) * (l->color.yzw / 255.) * l->color.x * angle;
		// printf("%f %f %f %f\n", diffuse.x, diffuse.y, diffuse.z, diffuse.w);
	}
	else
		diffuse = 0.;
	return (diffuse);
	// return (0.);
}

Tuple4f	rt_specular(Tuple4f n_vec, Tuple4f l_vec, Tuple4f forward, t_light *l)
{
	Tuple4f	specular;
	Tuple4f	reflect;
	float	angle;

	reflect = -l_vec - n_vec * 2.0 * vt_dot(-l_vec, n_vec);
	angle = vt_dot(reflect, forward);
	if (angle > 0.)
	{
		specular.x = 1.;
		specular.yzw = l->color.x * (l->color.yzw / 255.) * powf(angle, SHININESS);
	}
	else
		specular = 0.;
	// return (specular);
	return (0.);
}