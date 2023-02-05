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

t_tpl4f	mt_cross_tp(t_mtx4f *m, t_tpl4f t)
{
	t_tpl4f	result;

	result.x = vt_dot((t_tpl4f)(*m).s0123, t);
	result.y = vt_dot((t_tpl4f)(*m).s4567, t);
	result.z = vt_dot((t_tpl4f)(*m).s89ab, t);
	result.w = vt_dot((t_tpl4f)(*m).scdef, t);
	return (result);
}

void	mt_cross_mt(t_mtx4f *result, t_mtx4f *m1, t_mtx4f *m2)
{
	(*result).s0 = vt_dot((t_tpl4f)(*m1).s0123, (t_tpl4f)(*m2).s048c);
	(*result).s1 = vt_dot((t_tpl4f)(*m1).s0123, (t_tpl4f)(*m2).s159d);
	(*result).s2 = vt_dot((t_tpl4f)(*m1).s0123, (t_tpl4f)(*m2).s26ae);
	(*result).s3 = vt_dot((t_tpl4f)(*m1).s0123, (t_tpl4f)(*m2).s37bf);
	(*result).s4 = vt_dot((t_tpl4f)(*m1).s4567, (t_tpl4f)(*m2).s048c);
	(*result).s5 = vt_dot((t_tpl4f)(*m1).s4567, (t_tpl4f)(*m2).s159d);
	(*result).s6 = vt_dot((t_tpl4f)(*m1).s4567, (t_tpl4f)(*m2).s26ae);
	(*result).s7 = vt_dot((t_tpl4f)(*m1).s4567, (t_tpl4f)(*m2).s37bf);
	(*result).s8 = vt_dot((t_tpl4f)(*m1).s89ab, (t_tpl4f)(*m2).s048c);
	(*result).s9 = vt_dot((t_tpl4f)(*m1).s89ab, (t_tpl4f)(*m2).s159d);
	(*result).sa = vt_dot((t_tpl4f)(*m1).s89ab, (t_tpl4f)(*m2).s26ae);
	(*result).sb = vt_dot((t_tpl4f)(*m1).s89ab, (t_tpl4f)(*m2).s37bf);
	(*result).sc = vt_dot((t_tpl4f)(*m1).scdef, (t_tpl4f)(*m2).s048c);
	(*result).sd = vt_dot((t_tpl4f)(*m1).scdef, (t_tpl4f)(*m2).s159d);
	(*result).se = vt_dot((t_tpl4f)(*m1).scdef, (t_tpl4f)(*m2).s26ae);
	(*result).sf = vt_dot((t_tpl4f)(*m1).scdef, (t_tpl4f)(*m2).s37bf);
}
