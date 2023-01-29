#include "../../includes/miniRT.h"

int	fill_light(t_miniRT *data, char **tab)
{
	char		**tab_nb;
	t_light		*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		gestion_error(data);
	data->garbage = gbg_add(data->garbage, tmp);
	while (tab[i])
		i++;
	if (i != 4)
		gestion_error(data);
	tmp->brightness = cara_to_float(tab[2]);
	if (tmp->brightness < 0.0 || tmp->brightness > 1.0)
		gestion_error(data);
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (Tuple4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = (Tuple4f){tmp->brightness, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])};
	data->l[data->check->nb_l] = tmp;
	data->l[data->check->nb_l + 1] = NULL;
	data->check->nb_l++;
	return (0);
}

int	fill_plane(t_miniRT *data, char **tab)
{
	char		**tab_nb;
	t_plane		*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		gestion_error(data);
	data->garbage = gbg_add(data->garbage, tmp);
	while (tab[i])
		i++;
	if (i != 4)
		gestion_error(data);
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (Tuple4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	tmp->vector = (Tuple4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 0};
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = (Tuple4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])};
	data->pl[data->check->nb_pl] = tmp;
	data->pl[data->check->nb_pl + 1] = NULL;
	data->check->nb_pl++;
	return (0);
}

int	fill_sphere(t_miniRT *data, char **tab)
{
	char		**tab_nb;
	t_sphere	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		gestion_error(data);
	data->garbage = gbg_add(data->garbage, tmp);
	while (tab[i])
		i++;
	if (i != 4)
		gestion_error(data);
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (Tuple4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tmp->rayon = cara_to_float(tab[2]) / 2;
	tab_nb = ft_split(tab[3], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = (Tuple4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])};
	data->sp[data->check->nb_sp] = tmp;
	data->sp[data->check->nb_sp + 1] = NULL;
	data->check->nb_sp++;
	return (0);
}

int	fill_cylinder(t_miniRT *data, char **tab)
{
	char		**tab_nb;
	t_cylinder	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		gestion_error(data);
	data->garbage = gbg_add(data->garbage, tmp);
	while (tab[i])
		i++;
	if (i != 6)
		gestion_error(data);
	tab_nb = ft_split(tab[1], ',');
	check_tab(data, tab_nb);
	tmp->coor = (Tuple4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	tmp->vector = (Tuple4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 0};
	tmp->rayon = cara_to_float(tab[3]) / 2;
	tmp->height = cara_to_float(tab[4]);
	tab_nb = ft_split(tab[5], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = (Tuple4f){1, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])};
	data->cy[data->check->nb_cy] = tmp;
	data->cy[data->check->nb_cy + 1] = NULL;
	data->check->nb_cy++;
	return (0);
}

// si on nous envoye un nb au lieu de trois

void		init_struct(t_miniRT *data)
{
	t_light		**light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_camera	*camera;

	light = malloc(sizeof(*light) * (3));
	if (!light)
		return ;
	data->garbage = gbg_add(data->garbage, light);
	sphere = malloc(sizeof(*sphere) * (data->check->sphere + 1));
	if (!sphere)
		return ;
	data->garbage = gbg_add(data->garbage, sphere);
	plane = malloc(sizeof(*plane) * (data->check->plane + 1));
	if (!plane)
		return ;
	data->garbage = gbg_add(data->garbage, plane);
	cylinder = malloc(sizeof(*cylinder) * (data->check->cylinder + 1));
	if (!cylinder)
		return ;
	data->garbage = gbg_add(data->garbage, cylinder);
	camera = malloc(sizeof(camera));
	if (!camera)
		return ;
	data->garbage = gbg_add(data->garbage, camera);
	data->cy = cylinder;
	data->l = light;
	data->sp = sphere;
	data->pl = plane;
	data->c = camera;
}


int	fill_struct(t_miniRT *data, char *file)
{
	char		**tab;
	char		*line;
	int		fd;
	int		ret;

	ret = 1;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	init_struct(data);
	while (ret != 0)
	{
		ret = my_gnl(fd, &line);
		if ((ret == 0 && line[0] == '\r') || (ret == 0 && line[0] == '\0'))
			break;
		if (line[0] == '\r')
			continue;
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
			printf("Error fill\n");
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	close(fd);
	return (0);
}