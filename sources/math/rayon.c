/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:14:17 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 02:52:40 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

t_rayon	ry_init(t_tpl4f origin, t_tpl4f vector)
{
	t_rayon	r;

	r.origin = origin;
	r.vector = vector;
	return (r);
}

t_tpl4f	ry_distance(t_rayon r, float t)
{
	return (r.origin + t * r.vector);
}
