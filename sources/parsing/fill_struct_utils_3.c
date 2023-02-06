/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <hucoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:46:52 by hucoulon          #+#    #+#             */
/*   Updated: 2023/02/05 20:15:33 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_light_utils(t_miniRT *data, t_light *tmp, char **tab)
{
	char		**tab_nb;

	tmp->color.x = c_to_f(tab[2], 0, 1, 0);
	if (tmp->color.x < 0.0 || tmp->color.x > 1.0)
		gestion_error(data, 2);
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (t_tpl4f){c_to_f(tab_nb[0], 0, 1, 0),
		c_to_f(tab_nb[1], 0, 1, 0),
		c_to_f(tab_nb[2], 0, 1, 0), 1};
	ft_ftab(tab_nb);
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255)
		|| (ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255)
		|| (ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
	tmp->color = (t_tpl4f){tmp->color.x, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]),
		ft_atoi(tab_nb[2])};
	tmp->color.yzw /= 255.;
	ft_ftab(tab_nb);
}

void	fill_ambiant_utils(t_miniRT *data, t_light *tmp, char **tab)
{
	char		**tab_nb;

	tmp->color.x = c_to_f(tab[1], 0, 1, 0);
	if (tmp->color.x < 0.0 || tmp->color.x > 1.0)
		gestion_error(data, 2);
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255)
		|| (ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255)
		|| (ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
	tmp->color = (t_tpl4f){tmp->color.x, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]),
		ft_atoi(tab_nb[2])};
	tmp->color.yzw /= 255.;
	tmp->coor = (t_tpl4f){0., 0., 0., 1.};
	ft_ftab(tab_nb);
}

void	fill_camera_utils(t_miniRT *data, t_camera *tmp, char **tab)
{
	char		**tab_nb;

	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (t_tpl4f){c_to_f(tab_nb[0], 0, 1, 0),
		c_to_f(tab_nb[1], 0, 1, 0),
		c_to_f(tab_nb[2], 0, 1, 0), 1};
	ft_ftab(tab_nb);
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	tmp->vector = (t_tpl4f){c_to_f(tab_nb[0], 0, 1, 0),
		c_to_f(tab_nb[1], 0, 1, 0),
		c_to_f(tab_nb[2], 0, 1, 0), 0};
	if ((tmp->vector.s0 < -1.0 || tmp->vector.s0 > 1.0)
		|| (tmp->vector.s1 < -1.0 || tmp->vector.s1 > 1.0)
		|| (tmp->vector.s2 < -1.0 || tmp->vector.s2 > 1.0))
		gestion_error(data, 2);
	tmp->fov = c_to_f(tab[3], 0, 1, 0) * M_PI / 180.0;
	ft_ftab(tab_nb);
}
