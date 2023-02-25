/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <hucoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:37:06 by hucoulon          #+#    #+#             */
/*   Updated: 2023/02/25 04:15:57 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_miniRT	*init_minirt(void)
{
	t_miniRT		*data;
	t_check_file	*tmp;

	data = malloc(sizeof(*data));
	if (!data)
		return (NULL);
	data->mlx = NULL;
	data->garbage = NULL;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp->camera = 0;
	tmp->ambiance = 0;
	tmp->light = 0;
	tmp->sphere = 0;
	tmp->plane = 0;
	tmp->cylinder = 0;
	tmp->line = 0;
	tmp->nb_cy = 0;
	tmp->nb_sp = 0;
	tmp->nb_pl = 0;
	tmp->nb_l = 1;
	data->check = tmp;
	data->garbage = gbg_add(data->garbage, data->check);
	return (data);
}
