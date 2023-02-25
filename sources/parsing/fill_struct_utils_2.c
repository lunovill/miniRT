/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <hucoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:53:50 by hucoulon          #+#    #+#             */
/*   Updated: 2023/02/05 20:16:05 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_cylinder_utils(t_miniRT *data, t_cylinder *tmp, char **tab)
{
	char	**tab_nb;

	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (t_tpl4f){c_to_f(tab_nb[0], 0, 1, 0),
		c_to_f(tab_nb[1], 0, 1, 0), c_to_f(tab_nb[2], 0, 1, 0), 1};
	ft_ftab(tab_nb);
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	tmp->vector = (t_tpl4f){c_to_f(tab_nb[0], 0, 1, 0),
		c_to_f(tab_nb[1], 0, 1, 0),
		c_to_f(tab_nb[2], 0, 1, 0), 0};
	tmp->rayon = c_to_f(tab[3], 0, 1, 0) / 2;
	tmp->height = c_to_f(tab[4], 0, 1, 0);
	ft_ftab(tab_nb);
	tab_nb = ft_split(tab[5], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255)
		|| (ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255)
		|| (ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
	tmp->color = (t_tpl4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]),
		ft_atoi(tab_nb[2])};
	tmp->color.yzw /= 255.;
	ft_ftab(tab_nb);
}

void	fill_sphere_utils(t_miniRT *data, t_sphere *tmp, char **tab)
{
	char		**tab_nb;

	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (t_tpl4f){c_to_f(tab_nb[0], 0, 1, 0),
		c_to_f(tab_nb[1], 0, 1, 0),
		c_to_f(tab_nb[2], 0, 1, 0), 1};
	tmp->rayon = c_to_f(tab[2], 0, 1, 0) / 2;
	ft_ftab(tab_nb);
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255)
		|| (ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255)
		|| (ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
	tmp->color = (t_tpl4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]),
		ft_atoi(tab_nb[2])};
	tmp->color.yzw /= 255.;
	ft_ftab(tab_nb);
}

void	fill_plane_utils(t_miniRT *data, t_plane *tmp, char **tab)
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
	tmp->normal = (t_tpl4f){c_to_f(tab_nb[0], 0, 1, 0),
		c_to_f(tab_nb[1], 0, 1, 0),
		c_to_f(tab_nb[2], 0, 1, 0), 0};
	ft_ftab(tab_nb);
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255)
		|| (ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255)
		|| (ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
	tmp->color = (t_tpl4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]),
		ft_atoi(tab_nb[2])};
	tmp->color.yzw /= 255.;
	ft_ftab(tab_nb);
}

void	init_struct_utils(t_miniRT *data)
{
	t_cylinder	**cylinder;
	t_camera	*camera;

	cylinder = malloc(sizeof(*cylinder) * (data->check->cylinder + 1));
	if (!cylinder)
		return ;
	data->cy = cylinder;
	data->garbage = gbg_add(data->garbage, data->cy);
	camera = malloc(sizeof(camera));
	if (!camera)
		return ;
	data->c = camera;
	data->garbage = gbg_add(data->garbage, data->c);
}

void	init_struct(t_miniRT *data)
{
	t_light		**light;
	t_sphere	**sphere;
	t_plane		**plane;

	light = malloc(sizeof(*light) * (data->check->light + 1));
	if (!light)
		return ;
	data->l = light;
	data->garbage = gbg_add(data->garbage, data->l);
	sphere = malloc(sizeof(*sphere) * (data->check->sphere + 1));
	if (!sphere)
		return ;
	data->sp = sphere;
	data->garbage = gbg_add(data->garbage, data->sp);
	plane = malloc(sizeof(*plane) * (data->check->plane + 1));
	if (!plane)
		return ;
	data->pl = plane;
	data->garbage = gbg_add(data->garbage, data->pl);
	init_struct_utils(data);
}
