#include "miniRT.h"

void	fill_light(t_miniRT *data, char **tab)
{
	char		**tab_nb;
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
	tmp->color.x = cara_to_float(tab[2]);
	if (tmp->color.x < 0.0 || tmp->color.x > 1.0)
		gestion_error(data, 2);
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (t_tpl4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
tmp->color = (t_tpl4f){tmp->color.x, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])} ;
tmp->color.yzw /= 255.;
	data->l[data->check->nb_l] = tmp;
	data->garbage = gbg_add(data->garbage, data->l[data->check->nb_l]);
	data->l[data->check->nb_l + 1] = NULL;
	data->check->nb_l++;
}

void	fill_plane(t_miniRT *data, char **tab)
{
	char		**tab_nb;
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
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (t_tpl4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	tmp->vector = (t_tpl4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 0};
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
tmp->color = (t_tpl4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])} ;
tmp->color.yzw /= 255.;
	data->pl[data->check->nb_pl] = tmp;
	data->garbage = gbg_add(data->garbage, data->pl[data->check->nb_pl]);
	data->pl[data->check->nb_pl + 1] = NULL;
	data->check->nb_pl++;
}

void	fill_sphere(t_miniRT *data, char **tab)
{
	char		**tab_nb;
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
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (t_tpl4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tmp->rayon = cara_to_float(tab[2]) / 2;
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
tmp->color = (t_tpl4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])} ;
tmp->color.yzw /= 255.;
	data->sp[data->check->nb_sp] = tmp;
	data->garbage = gbg_add(data->garbage, data->sp[data->check->nb_sp]);
	data->sp[data->check->nb_sp + 1] = NULL;
	data->check->nb_sp++;
}

void	fill_cylinder(t_miniRT *data, char **tab)
{
	char		**tab_nb;
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
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (t_tpl4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	tmp->vector = (t_tpl4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 0};
	tmp->rayon = cara_to_float(tab[3]) / 2;
	tmp->height = cara_to_float(tab[4]);
	tab_nb = ft_split(tab[5], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
tmp->color = (t_tpl4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])} ;
tmp->color.yzw /= 255.;
	data->cy[data->check->nb_cy] = tmp;
	data->garbage = gbg_add(data->garbage, data->cy[data->check->nb_cy]);
	data->cy[data->check->nb_cy + 1] = NULL;
	data->check->nb_cy++;
}

void		init_struct(t_miniRT *data)
{
	t_light		**light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_camera	*camera;

	light = malloc(sizeof(*light) * (data->check->light + 1));
	if (!light)
		return ;
	sphere = malloc(sizeof(*sphere) * (data->check->sphere + 1));
	if (!sphere)
		return ;
	plane = malloc(sizeof(*plane) * (data->check->plane + 1));
	if (!plane)
		return ;
	cylinder = malloc(sizeof(*cylinder) * (data->check->cylinder + 1));
	if (!cylinder)
		return ;
	camera = malloc(sizeof(camera));
	if (!camera)
		return ;	
	data->cy = cylinder;
	data->l = light;
	data->sp = sphere;
	data->pl = plane;
	data->c = camera;
	data->garbage = gbg_add(data->garbage, data->l);
	data->garbage = gbg_add(data->garbage, data->sp);
	data->garbage = gbg_add(data->garbage, data->pl);
	data->garbage = gbg_add(data->garbage, data->cy);
	data->garbage = gbg_add(data->garbage, data->c);
}

void	fill_struct(t_miniRT *data, char *file)
{
	char		**tab;
	char		*line;
	int			fd;
	int			ret;

	ret = 1;
	if ((fd = open(file, O_RDONLY)) < 0)
		gestion_error(data, 2);
	init_struct(data);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line, 1);
		if (line[0] == '\r' || line[0] == '\0')
		{
			ft_free(line);
			continue;
		}
		tab = ft_split(line, ' ');
		if (ft_strncmp(tab[0], "A", 2) == 0)
			fill_ambiant(data, tab);
		else if (ft_strncmp(tab[0], "C", 2) == 0)
			fill_camera(data, tab);
		else if (ft_strncmp(tab[0], "L", 2) == 0)
			fill_light(data, tab);
		else if (ft_strncmp(tab[0], "pl", 3) == 0)
			fill_plane(data, tab);
		else if (ft_strncmp(tab[0], "sp", 3) == 0)
			fill_sphere(data, tab);
		else if (ft_strncmp(tab[0], "cy", 3) == 0)
			fill_cylinder(data, tab);
		else
		{
			ft_free(line);
			close(fd);
			gestion_error(data, 2);
		}
		ft_free(line);
	}
	get_next_line(fd, &line, 0);
	close(fd);
}