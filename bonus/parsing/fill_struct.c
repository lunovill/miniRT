/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <hucoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:37:01 by hucoulon          #+#    #+#             */
/*   Updated: 2023/02/05 19:48:32 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_light(t_miniRT *data, char **tab)
{
	t_light		*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		gestion_error(data, 2);
	while (tab[i])
		i++;
	if (i != 4)
		gestion_error(data, 2);
	fill_light_utils(data, tmp, tab);
	data->l[data->check->nb_l] = tmp;
	data->garbage = gbg_add(data->garbage, data->l[data->check->nb_l]);
	data->l[data->check->nb_l + 1] = NULL;
	data->check->nb_l++;
}

void	fill_plane(t_miniRT *data, char **tab)
{
	t_plane		*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		gestion_error(data, 2);
	while (tab[i])
		i++;
	if (i != 4)
		gestion_error(data, 2);
	fill_plane_utils(data, tmp, tab);
	data->pl[data->check->nb_pl] = tmp;
	data->garbage = gbg_add(data->garbage, data->pl[data->check->nb_pl]);
	data->pl[data->check->nb_pl + 1] = NULL;
	data->check->nb_pl++;
}

void	fill_sphere(t_miniRT *data, char **tab)
{
	t_sphere	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		gestion_error(data, 2);
	while (tab[i])
		i++;
	if (i != 4)
		gestion_error(data, 2);
	fill_sphere_utils(data, tmp, tab);
	data->sp[data->check->nb_sp] = tmp;
	data->garbage = gbg_add(data->garbage, data->sp[data->check->nb_sp]);
	data->sp[data->check->nb_sp + 1] = NULL;
	data->check->nb_sp++;
}

void	fill_cylinder(t_miniRT *data, char **tab)
{
	t_cylinder	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		gestion_error(data, 2);
	while (tab[i])
		i++;
	if (i != 6)
		gestion_error(data, 2);
	fill_cylinder_utils(data, tmp, tab);
	data->cy[data->check->nb_cy] = tmp;
	data->garbage = gbg_add(data->garbage, data->cy[data->check->nb_cy]);
	data->cy[data->check->nb_cy + 1] = NULL;
	data->check->nb_cy++;
}		

void	fill_struct(t_miniRT *data, char *file)
{
	char		*line;
	int			fd;
	int			ret;

	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		gestion_error(data, 2);
	init_struct(data);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line, 1);
		if (line[0] == '\r' || line[0] == '\0')
		{
			ft_free(line);
			continue ;
		}
		fill_struct_utils(data, line, fd);
		ft_free(line);
	}
	get_next_line(fd, &line, 0);
	close(fd);
}
