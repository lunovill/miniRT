/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:19:42 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 00:19:43 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	cm_move(t_camera *c, t_key *key)
{
	if (key->up == 1)
		return (c->view.s37bf += (t_tpl4f)c->view.s456d * P_Z * 0.5, 1);
	if (key->down == 1)
		return (c->view.s37bf -= (t_tpl4f)c->view.s456d * P_Z * 0.5, 1);
	if (key->right == 1)
		return (c->view.s37bf += (t_tpl4f)c->view.s012c * P_Z * 0.5, 1);
	if (key->left == 1)
		return (c->view.s37bf -= (t_tpl4f)c->view.s012c * P_Z * 0.5, 1);
	if (key->befor == 1)
		return (c->view.s37bf += (t_tpl4f)c->view.s89ae * P_Z, 1);
	if (key->behind == 1)
		return (c->view.s37bf -= (t_tpl4f)c->view.s89ae * P_Z, 1);
	if (key->rot_up == 1)
		return (mt_rotate_x(&c->view, 0.1), 1);
	if (key->rot_down == 1)
		return (mt_rotate_x(&c->view, -0.1), 1);
	if (key->rot_right == 1)
		return (mt_rotate_y(&c->view, -0.1), 1);
	if (key->rot_left == 1)
		return (mt_rotate_y(&c->view, 0.1), 1);
	return (0);
}
