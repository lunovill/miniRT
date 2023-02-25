/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:30:07 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 03:30:08 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMT_H
# define LIBMT_H

# include <math.h>
# define TRUE 1
# define FALSE 0

# define EPSILON 0.0001

typedef float	t_tpl4f __attribute__((ext_vector_type(4)));
typedef float	t_mtx4f __attribute__((ext_vector_type(4*4)));

typedef struct s_rayon
{
	t_tpl4f	origin;
	t_tpl4f	vector;
}				t_rayon;

int		equalf(float a, float b);
int		equalt(t_tpl4f a, t_tpl4f b);
int		equalm(t_mtx4f m1, t_mtx4f m2);

float	vt_magnitude(t_tpl4f vector);
t_tpl4f	vt_normalize(t_tpl4f vector);
float	vt_dot(t_tpl4f u, t_tpl4f v);
t_tpl4f	vt_cross(t_tpl4f u, t_tpl4f v);

t_tpl4f	mt_cross_tp(t_mtx4f *m, t_tpl4f t);
void	mt_cross_mt(t_mtx4f *result, t_mtx4f *m1, t_mtx4f *m2);
void	mt_rotate_x(t_mtx4f *rx, float theta);
void	mt_rotate_y(t_mtx4f *ry, float theta);
void	mt_rotate_z(t_mtx4f *rz, float theta);

void	mt_inverse(t_mtx4f *ivs, t_mtx4f *mtx);

t_tpl4f	ry_distance(t_rayon r, float t);
t_rayon	ry_init(t_tpl4f origin, t_tpl4f vector);

#endif
