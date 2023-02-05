/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vt_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:14:32 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 00:14:33 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

float	vt_magnitude(Tuple4f vector)
{
	return (sqrtf(vector.x * vector.x + vector.y
			* vector.y + vector.z * vector.z));
}

float	vt_dot(Tuple4f u, Tuple4f v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w);
}

Tuple4f	vt_normalize(Tuple4f vector)
{
	return (vector / vt_magnitude(vector));
}

Tuple4f	vt_cross(Tuple4f u, Tuple4f v)
{
	Tuple4f	result;

	result.x = u.y * v.z - u.z * v.y;
	result.y = u.z * v.x - u.x * v.z;
	result.z = u.x * v.y - u.y * v.x;
	result.w = 0.;
	return (result);
}
