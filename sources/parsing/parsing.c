#include "miniRT.h"

int	check_begin(t_miniRT *data, char **tab)
{
	if (ft_strncmp(tab[0], "A", 2) == 0)
		data->check->light = data->check->light + 2;
	else if (ft_strncmp(tab[0], "C", 2) == 0)
		data->check->camera++;
	else if (ft_strncmp(tab[0], "L", 2) == 0)
		data->check->light++;
	else if (ft_strncmp(tab[0], "pl", 3) == 0)
		data->check->plane++;
	else if (ft_strncmp(tab[0], "sp", 3) == 0)
		data->check->sphere++;
	else if (ft_strncmp(tab[0], "cy", 3) == 0)
		data->check->cylinder++;
	else
		return (-1);
	return (0);
}

int	check_nb_utils(char **tab, int i, int j)
{
	int	min;
	int	p;

	p = 0;
	min = 0;
	while (tab[i][j])
	{
		if (ft_isdigit(tab[i][j]) == 1 || tab[i][j] == '.' ||
				tab[i][j] == 13 || tab[i][j] == '-')
		{
			if (tab[i][j] == '.')
				p++;
			else if (tab[i][j] == '-')
				min++;
		}
		else
			return (-1);
		j++;
	}
	if (p > 1 || min > 1)
		return (-1);
	return (0);
}

int	check_nb(char **tab)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (tab[i])
	{
		tmp = ft_split(tab[i], ',');
		j = 0;
		while (tmp[j])
		{
			k = 0;
			if (check_nb_utils(tmp, j, k) == -1)
				return (-1);
			j++;
		}
		if (j != 1 && j != 3)
			return (-1);
		i++;
	}
	return (0);
}

int	parsing_utils(t_miniRT *data, int fd)
{
	char	**tab;
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line, 1);
		if (line[0] == '\r' || line[0] == '\0')
			continue ;
		tab = ft_split(line, ' ');
		data->check->line++;
		if (check_begin(data, tab) == -1 || check_nb(tab) == -1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	get_next_line(fd, &line, 0);
	close(fd);
	return (0);
}

void	parsing(t_miniRT *data, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		gestion_error(data, 1);
	if (parsing_utils(data, fd) == -1)
		gestion_error(data, 1);
	if (data->check->camera != 1)
		gestion_error(data, 1);
	if (data->check->line - (data->check->sphere + data->check->cylinder + \
		data->check->plane + data->check->light) != 0)
		gestion_error(data, 1);
}
