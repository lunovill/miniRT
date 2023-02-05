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

void	cm_move(t_camera *c, t_key *key)
{
	if (key->up == 1)
		c->view.s37bf += (Tuple4f)c->view.s456d * c->pz * 0.5;
	if (key->down == 1)
		c->view.s37bf -= (Tuple4f)c->view.s456d * c->pz * 0.5;
	if (key->right == 1)
		c->view.s37bf += (Tuple4f)c->view.s012c * c->pz * 0.5;
	if (key->left == 1)
		c->view.s37bf -= (Tuple4f)c->view.s012c * c->pz * 0.5;
	if (key->befor == 1)
		c->view.s37bf += (Tuple4f)c->view.s89ae * c->pz;
	if (key->behind == 1)
		c->view.s37bf -= (Tuple4f)c->view.s89ae * c->pz;
	if (key->rot_up == 1)
		mt_rotate_x(&c->view, -0.1);
	if (key->rot_down == 1)
		mt_rotate_x(&c->view, 0.1);
	if (key->rot_right == 1)
		mt_rotate_y(&c->view, 0.1);
	if (key->rot_left == 1)
		mt_rotate_y(&c->view, -0.1);
}
