#include "miniRT.h"
#define SHININESS 150.0 // Entre 10 et 200

Tuple4f	rt_ambient(Tuple4f color, t_light *l)
{
	Tuple4f ambient;
	ambient.x = l->color.x;
	ambient.yzw = (color.yzw) * (l->color.yzw) * l->color.x;
	return (ambient);
}

Tuple4f	rt_diffuse(Tuple4f color, Tuple4f n_vec, Tuple4f l_vec, t_light *l)
{
	Tuple4f	diffuse;
	float angle;

	angle = vt_dot(l_vec, n_vec);
	if (angle > 0. && angle <= M_PI / 2.)
	{
		diffuse.x = 1.;
		diffuse.yzw = (color.yzw) * (l->color.yzw) * l->color.x * angle;
	}
	else
		diffuse = 0.;
	return (diffuse);
}

Tuple4f	rt_specular(Tuple4f n_vec, Tuple4f l_vec, Tuple4f forward, t_light *l)
{
	Tuple4f	specular;
	Tuple4f	reflect;
	float	angle;

	reflect = l_vec - n_vec * 2.0 * vt_dot(l_vec, n_vec);
	angle = vt_dot(reflect, forward);
	if (angle > 0.)
	{
		specular.x = 1.;
		specular.yzw = l->color.x * (l->color.yzw) * powf(angle, SHININESS);
	}
	else
		specular = 0.;
	return (specular);
}