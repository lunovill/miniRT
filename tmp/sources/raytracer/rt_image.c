/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:40:18 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:40:19 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void ray_generator(Vector4f *ray, t_miniRT *data, float x, float y)
{
	float f = 1.0 / tanf(data->c->fov_h / 2.0);
	// printf("fov = %f\n\n", f);
	float px = (2.0 * x / data->mlx->wrslt - 1.0) * tanf(data->c->fov_h / 2.0) * data->mlx->wrslt / data->mlx->hrslt;
	float py = (1.0 - 2.0 * y / data->mlx->hrslt) * tanf(data->c->fov_v / 2.0);
	(*ray) = (Vector4f){px * f, py * f, -f, 1.0};
	// (*ray) = (Vector4f){px, py, -1, 1.0};
	// (*ray) /= sqrtf(px * px + py * py + 1.0);
	// if ((x == 0.0 && y == 0.0) || (x == 0.0 && y == 499.0) || (x == 499.0 && y == 0.0) || (x == 499.0 && y == 499.0))
		// printf("%f %f %f %f\n", px, py, -1.0, 1.0);
	(*ray).xyz += data->c->coor.xyz;
	(*ray).xyz += data->c->vector.xyz;
	(*ray).xyz /= sqrtf((*ray).x * (*ray).x + (*ray).y * (*ray).y + (*ray).z * (*ray).z);
}

float	ray_to_sphere(Coor4f ray, Vector4f drt, Coor4f sp, float r)
{
	float	a = drt.x * drt.x + drt.y * drt.y + drt.z * drt.z;
	float	b = 2.0 * (drt.x * (ray.x - sp.x) + drt.y * (ray.y - sp.y) + drt.z * (ray.z - sp.z));
	float	c = (ray.x - sp.x) * (ray.x - sp.x) + (ray.y - sp.y) * (ray.y - sp.y) + (ray.z - sp.z) * (ray.z - sp.z) - r * r;
	float	d = b * b - 4.0 * a * c;
	float	t2 = (-b + sqrtf(d)) / (2.0 * a);
	float	t1 = (-b - sqrtf(d)) / (2.0 * a);
	if (t1 > 0.0)
		return (t1);
	if (t2 > 0.0)
		return (t2);
	return (0.0);
}

Color4f	rt_color_pixel(t_sphere *sp, Coor4f orgc, Vector4f ray, float t, t_light **l)
{
	Coor4f	p_intst = orgc + t * ray;
	Vector4f normal = p_intst - sp->orgc;
	normal.xyz /= sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
	Color4f color;
	color.yzw = l[0]->color.x * (sp->color.yzw + l[0]->color.x * l[0]->color.yzw);
	int i = 1;
	while (l[i])
	{
		Vector4f l_vec = l[i]->orgc - p_intst;
		l_vec.xyz /= sqrtf(l_vec.x * l_vec.x + l_vec.y * l_vec.y + l_vec.z * l_vec.z);
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
	return(color);
}

void	refresh(t_miniRT *data)
{
	Vector4f	ray;
	float x = 0.0;
	while (x < data->mlx->hrslt)
	{
		float y = 0.0;
		while (y < data->mlx->wrslt)
		{
			ray_generator(&ray, data, y, x);
			int i = 0, tmp = 0;
			float d, min = 0.0;
			while(data->sp[i])
			{
				d = ray_to_sphere(data->c->coor, ray, data->sp[i]->orgc, data->sp[i]->rayon);
				if (d > 0.0 && (!min || d < min))
				{
					min = d;
					tmp = i;
				}
				i++;
			}
			if (!min)
				mlx_put_pixel(data->mlx->scene, y, x, trgb_color(data->l[0]->color * data->l[0]->color.x));
			else
				mlx_put_pixel(data->mlx->scene, y, x, trgb_color(rt_color_pixel(data->sp[tmp], data->c->coor, ray, min, data->l)));
			y += 1.0;
		}
		// exit(42);
		x += 1.0;
	}
}

int	rt_image(t_miniRT *data)
{
	refresh(data);
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, data->mlx->scene->img, 0, 0);
	return (0);
}
