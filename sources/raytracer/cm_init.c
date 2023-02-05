/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:19:25 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 00:19:28 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cm_init(t_mtx4f *view, t_tpl4f coor, t_tpl4f vector)
{
	vector = vt_normalize(vector);
	if (equalt(vector, (t_tpl4f){0., 1., 0., 0.}))
	{
		(*view).s4567 = vt_cross((t_tpl4f){1., 0., 0., 0.}, vector);
		(*view).s4567 = vt_normalize((*view).s4567);
		(*view).s0123 = vt_cross(vector, (t_tpl4f)(*view).s4567);
		(*view).s0123 = vt_normalize((t_tpl4f)(*view).s0123);
	}
	else
	{
		(*view).s0123 = vt_cross(vector, (t_tpl4f){0., 1., 0., 0.});
		(*view).s0123 = vt_normalize((*view).s0123);
		(*view).s4567 = vt_cross((t_tpl4f)(*view).s0123, vector);
		(*view).s4567 = vt_normalize((t_tpl4f)(*view).s4567);
	}
	(*view).s89ab = vector;
	(*view).s37bf = coor;
	(*view).scdef = (t_tpl4f){0., 0., 0., 1.};
}
