/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:13:50 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 00:13:51 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

Tuple4f	mt_cross_tp(Matrix4f *m, Tuple4f t)
{
	Tuple4f	result;

	result.x = vt_dot((Tuple4f)(*m).s0123, t);
	result.y = vt_dot((Tuple4f)(*m).s4567, t);
	result.z = vt_dot((Tuple4f)(*m).s89ab, t);
	result.w = vt_dot((Tuple4f)(*m).scdef, t);
	return (result);
}

void	mt_cross_mt(Matrix4f *result, Matrix4f *m1, Matrix4f *m2)
{
	(*result).s0 = vt_dot((Tuple4f)(*m1).s0123, (Tuple4f)(*m2).s048c);
	(*result).s1 = vt_dot((Tuple4f)(*m1).s0123, (Tuple4f)(*m2).s159d);
	(*result).s2 = vt_dot((Tuple4f)(*m1).s0123, (Tuple4f)(*m2).s26ae);
	(*result).s3 = vt_dot((Tuple4f)(*m1).s0123, (Tuple4f)(*m2).s37bf);
	(*result).s4 = vt_dot((Tuple4f)(*m1).s4567, (Tuple4f)(*m2).s048c);
	(*result).s5 = vt_dot((Tuple4f)(*m1).s4567, (Tuple4f)(*m2).s159d);
	(*result).s6 = vt_dot((Tuple4f)(*m1).s4567, (Tuple4f)(*m2).s26ae);
	(*result).s7 = vt_dot((Tuple4f)(*m1).s4567, (Tuple4f)(*m2).s37bf);
	(*result).s8 = vt_dot((Tuple4f)(*m1).s89ab, (Tuple4f)(*m2).s048c);
	(*result).s9 = vt_dot((Tuple4f)(*m1).s89ab, (Tuple4f)(*m2).s159d);
	(*result).sa = vt_dot((Tuple4f)(*m1).s89ab, (Tuple4f)(*m2).s26ae);
	(*result).sb = vt_dot((Tuple4f)(*m1).s89ab, (Tuple4f)(*m2).s37bf);
	(*result).sc = vt_dot((Tuple4f)(*m1).scdef, (Tuple4f)(*m2).s048c);
	(*result).sd = vt_dot((Tuple4f)(*m1).scdef, (Tuple4f)(*m2).s159d);
	(*result).se = vt_dot((Tuple4f)(*m1).scdef, (Tuple4f)(*m2).s26ae);
	(*result).sf = vt_dot((Tuple4f)(*m1).scdef, (Tuple4f)(*m2).s37bf);
}
