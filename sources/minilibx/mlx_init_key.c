/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:39:21 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:39:22 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxRT.h"

t_key	*mlx_init_key(void)
{
	t_key	*key;

	key = malloc(sizeof(*key));
	key->up = 0;
	key->left = 0;
	key->down = 0;
	key->right = 0;
	key->befor = 0;
	key->behind = 0;
	return (key);
}
