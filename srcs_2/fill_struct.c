#include "../includes/miniRT.h"

int	trgb_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

float	cara_to_float(char *str)
{
	int				neg;
	float			n;
	float			div;
	unsigned int	i;

	div = 1;
	i = 0;
	n = 0;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1 || str[i] == '.')
	{
		if (str[i] == '.')
		{
			i++;
			div = pow(10, (ft_strlen(str) - i));
		}
		else
		{
			n *= 10;
			n += str[i++] - '0';
		}
	}
	return ((n * neg) / div);
}

int	fill_ambiant(t_miniRT *data, char **tab)
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
	if (i != 3)
		gestion_error(data);
	tmp->brightness = cara_to_float(tab[1]);
	if (tmp->brightness < 0.0 || tmp->brightness > 1.0)
		gestion_error(data);
	tab_nb = ft_split(tab[2], ',');
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = trgb_color(0, ft_atoi(tab_nb[0]), 
			ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2]));
	tmp->camc = (Coor4f){0, 0, 0, 1};
	tmp->orgc = (Coor4f){0, 0, 0, 2};
	data->l[0] = tmp;
	return (0);
}

int	fill_camera(t_miniRT *data, char **tab)
{
char			**tab_coor;
	char		**tab_vect;
	t_camera	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (0);
	data->garbage = gbg_add(data->garbage, tmp);
	while (tab[i])
		i++;
	if (i != 4)
		gestion_error(data);
	tab_coor = ft_split(tab[1], ',');
	tmp->coor = (Coor4f){cara_to_float(tab_coor[0]), cara_to_float(tab_coor[1]), cara_to_float(tab_coor[2]), 1};
	tab_vect = ft_split(tab[2], ',');
	tmp->vector = (Vector4f){cara_to_float(tab_vect[0]), cara_to_float(tab_vect[1]), cara_to_float(tab_vect[2]), 0};
	if ((tmp->vector.s0 < -1.0 || tmp->vector.s0 > 1.0) ||
			(tmp->vector.s1 < -1.0 || tmp->vector.s1 > 1.0) ||
			(tmp->vector.s2 < -1.0 || tmp->vector.s2 > 1.0))
		gestion_error(data);
	tmp->fov = cara_to_float(tab[3]);
	tmp->matrix = (Matrix4f){1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	data->c = tmp;
	return (0);
}

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
	tmp->orgc = (Coor4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[3], ',');
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = trgb_color(0, ft_atoi(tab_nb[0]), 
			ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2]));
	tmp->camc = (Coor4f){0, 0, 0, 2};
	data->l[1] = tmp;
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
	tmp->orgc = (Coor4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[2], ',');
	tmp->vector = (Vector4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 0};
	tab_nb = ft_split(tab[3], ',');
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = trgb_color(0, ft_atoi(tab_nb[0]), 
			ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2]));
	tmp->camc = (Coor4f){0, 0, 0, 2};
	data->pl[data->check->nb_pl] = tmp;
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
	tmp->orgc = (Coor4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tmp->rayon = cara_to_float(tab[2]);
	tab_nb = ft_split(tab[3], ',');
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = trgb_color(0, ft_atoi(tab_nb[0]), 
			ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2]));
	tmp->camc = (Coor4f){0, 0, 0, 2};
	data->sp[data->check->nb_sp] = tmp;
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
	tmp->orgc = (Coor4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[2], ',');
	tmp->vector = (Vector4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 0};
	tmp->rayon = cara_to_float(tab[3]);
	tmp->height = cara_to_float(tab[4]);
	tab_nb = ft_split(tab[5], ',');
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data);
	tmp->color = trgb_color(0, ft_atoi(tab_nb[0]), 
			ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2]));
	tmp->camc = (Coor4f){0, 0, 0, 2};
	data->cy[data->check->nb_cy] = tmp;
	data->check->nb_cy++;
	return (0);
}

// rayon , diameter / 2 ou simplement diameter

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
