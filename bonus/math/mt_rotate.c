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

void	mt_rotate_x(Matrix4f *result, float theta)
{
	Matrix4f	m;
	Matrix4f	rx;

	m = *result;
	rx = (Matrix4f){1., 0., 0., 0.,
		0., cosf(theta), -sinf(theta), 0.,
		0., sinf(theta), cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*result, &m, &rx);
}

void	mt_rotate_y(Matrix4f *result, float theta)
{
	Matrix4f	m;
	Matrix4f	ry;

	m = *result;
	ry = (Matrix4f){cosf(theta), 0., sinf(theta), 0.,
		0., 1., 0., 0.,
		-sinf(theta), 0., cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*result, &m, &ry);
}

void	mt_rotate_z(Matrix4f *result, float theta)
{
	Matrix4f	m;
	Matrix4f	rz;

	m = *result;
	rz = (Matrix4f){cosf(theta), -sinf(theta), 0., 0.,
		sinf(theta), cosf(theta), 0., 0.,
		0., 0., 1., 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*result, &m, &rz);
}
