/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:14:02 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 00:14:03 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

void	mt_rotate_x(t_mtx4f *result, float theta)
{
	t_mtx4f	m;
	t_mtx4f	rx;

	m = *result;
	rx = (t_mtx4f){1., 0., 0., 0.,
		0., cosf(theta), -sinf(theta), 0.,
		0., sinf(theta), cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*result, &m, &rx);
}

void	mt_rotate_y(t_mtx4f *result, float theta)
{
	t_mtx4f	m;
	t_mtx4f	ry;

	m = *result;
	ry = (t_mtx4f){cosf(theta), 0., sinf(theta), 0.,
		0., 1., 0., 0.,
		-sinf(theta), 0., cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*result, &m, &ry);
}

void	mt_rotate_z(t_mtx4f *result, float theta)
{
	t_mtx4f	m;
	t_mtx4f	rz;

	m = *result;
	rz = (t_mtx4f){cosf(theta), -sinf(theta), 0., 0.,
		sinf(theta), cosf(theta), 0., 0.,
		0., 0., 1., 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*result, &m, &rz);
}