#include "miniRT.h"

// static float	ray_to_cylinder(t_tpl4f c_coor, t_tpl4f r_dir, t_cylinder *cy, t_tpl4f normal)
// {
// 	float	res0;
// 	float	res1;
// 	float	disc;
// 	float	a;
// 	float	b;
// 	float	c;

// 	(void)normal;
// 	(void)cy;
// 	a = (r_dir.s0 * r_dir.s0 + r_dir.s2 * r_dir.s2);
// 	b = (2 * c_coor.s0 * r_dir.s0) + (2 * c_coor.s2 * r_dir.s2);
// 	c = (c_coor.s0 * c_coor.s0) + (c_coor.s2 * c_coor.s2) -1;
// 	disc = (b * b) - 4 * a * c;
// 	if (disc < 0)
// 		return (0);
// 	res0 = ((b * -1) - sqrtf(disc)) / (2 * a);
// 	res1 = ((b * -1) + sqrtf(disc)) / (2 * a);
// 	if (res0 > 0.0)
// 		return (res0);
// 	if (res1 > 0.0)
// 		return (res1);
// 	return (0.0);
// }

static float	ray_to_cylinder(t_rayon r, t_cylinder *cy)
{
	float	a;
	float	b;
	float	c;
	float	disc;
	float	check_cap0;
	float	check_cap1;
//	float	do_cap_x;
//	float	do_cap_z;
//	float	do_cap_res;
	float	swap;

	a = (r.vector.s0 * r.vector.s0 + r.vector.s2 * r.vector.s2);
 	b = (2 * (r.origin.s0 - cy->coor.s0) * r.vector.s0) + (2 * (r.origin.s2 - cy->coor.s2) * r.vector.s2);
 	c = ((r.origin.s0 - cy->coor.s0) * (r.origin.s0 - cy->coor.s0)) + ((r.origin.s2 - cy->coor.s2) * (r.origin.s2 - cy->coor.s2)) - (cy->rayon * cy->rayon);
	disc = (b * b) - 4 * (a * c);
	if (disc < 0)
		return (0);
 	cy->t1 = ((b * -1) - sqrtf(disc)) / (2 * a);
 	cy->t2 = ((b * -1) + sqrtf(disc)) / (2 * a);
	if (cy->t1 > cy->t2)
	{
		swap = cy->t2;
		cy->t2 = cy->t1;
		cy->t1 = swap;
	}
//	do_cap_x = (((r.origin.s0 - cy->coor.s0) + (((cy->coor.s1 - cy->height) - (r.origin.s1 - cy->coor.s1)) / r.vector.s1)) * r.vector.s0);
//	do_cap_z = (((r.origin.s2 - cy->coor.s2) + (((cy->coor.s1 - cy->height) - (r.origin.s1 - cy->coor.s1)) / r.vector.s1)) * r.vector.s2);
//	do_cap_res = ((do_cap_x * do_cap_x) + (do_cap_z * do_cap_z));
//	if (do_cap_res > (cy->rayon))
//		return (do_cap_res);
	check_cap0 = (r.origin.s1 - cy->coor.s1) + cy->t1 * r.vector.s1;
	check_cap1 = (r.origin.s1 - cy->coor.s1) + cy->t2 * r.vector.s1;
	if (check_cap0 < (cy->coor.s1 - cy->height) && check_cap1 < (cy->coor.s1 - cy->height))
		return (0);
	if (check_cap0 > (cy->coor.s1 + cy->height) && check_cap1 > (cy->coor.s1 + cy->height))
		return (0);
	if (check_cap0 < (cy->coor.s1 - cy->height) || check_cap0 > (cy->coor.s1 + cy->height))
		return (cy->t2);
	if (check_cap1 < (cy->coor.s1 - cy->height) || check_cap1 > (cy->coor.s1 + cy->height))
		return (cy->t1);
	if (cy->t2 < cy->t1 && cy->t2 > 0)
		return (cy->t2);
	if (cy->t1 > 0)
		return (cy->t1);
	return (0);
}

// float	rt_intersection_cy(t_cylinder **cy, int *object, t_tpl4f c_coor, t_tpl4f r_dir)
// {
// 	float	d;
// 	float	d_min;
// 	int		i;

// 	d_min = 0.0;
// 	*object = -1;
// 	i = 0;
// 	if (cy)
// 		while (cy[i])
// 		{
// 			d = ray_to_cylinder(c_coor, r_dir, cy[i], cy[i]->vector);
// 			if (d > 0 && (!d_min || d < d_min))
// 			{
// 				d_min = d;
// 				*object = i;
// 			}
// 			i++;
// 		}
// 	return (d_min);
// }

float	rt_intersection_cy(t_rayon r, t_cylinder **cy, int *object)
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
			d = ray_to_cylinder(r, cy[i]);
			if (d > 0 && (!d_min || d < d_min))
			{
				d_min = d;
				*object = i;
			}
			i++;
		}
	return (d_min);
}

int	rt_cylinder(t_cylinder *cy, t_tpl4f orgc, t_tpl4f ray, float t, t_light **l)
{
	t_tpl4f	p_intst = orgc + t * ray;
	t_tpl4f	color;
	color.yzw = l[0]->color.x * (cy->color.ywz + l[0]->color.x * 
	l[0]->color.yzw);
	int i = 1;
	while (l[i])
	{
		t_tpl4f l_vec = l[i]->coor - p_intst;
		vt_normalize(l_vec);
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

// int	rt_cylinder(t_cylinder *cy, t_tpl4f orgc, t_tpl4f ray, float t, t_light **l)
// {
// 	t_tpl4f	p_intst = orgc + t * ray;
// 	t_tpl4f	color;
// 	color.yzw = l[0]->color.x * (cy->color.ywz + l[0]->color.x * 
// 	l[0]->color.yzw);
// 	int i = 1;
// 	while (l[i])
// 	{
// 		t_tpl4f l_vec = l[i]->coor - p_intst;
// 		vt_normalize(l_vec);
// 		float angle = cy->vector.x * l_vec.x + cy->vector.y * l_vec.y + cy->vector.z * l_vec.z;
// 		if (angle > 0.0 && angle <= M_PI / 2)
// 			color.yzw += l[i]->color.x * l[i]->color.yzw * angle;
// 		i++;
// 	}
// 	color.x = 1;
// 	color.y = (color.y > 255.0) ? 255.0 : color.y;
// 	color.z = (color.z > 255.0) ? 255.0 : color.z;
// 	color.w = (color.w > 255.0) ? 255.0 : color.w;
// 	return (trgb_color(color));
// }