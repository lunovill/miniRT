#include "../includes/miniRT.h"

int	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
		return (0);
	i = i - 3;
	if (str[i] == '.')
	{
		if (str[i + 1] == 'r')
		{
			if (str[i + 2] == 't')
			{
				if (str[i - 1] == '/')
					return (0);
                return (1);
			}
		}
	}
	return (0);
}

int		check_begin(t_miniRT *data, char **tab)
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

int     parsing(t_miniRT *data, char *file)
{
    int fd;
    int ret;
    char    *line;
    char    **tab;

    ret = 1;
    if ((fd = open(file, O_RDONLY)) < 0)
        return (-1);
    while (ret != 0)
    {
        ret = my_gnl(fd, &line);
        if (line[0] == '\r')
            continue;
        tab = ft_split(line, ' ');
        data->check->line++;
        if (check_begin(data, tab) == -1)
        {
            close(fd);
            return (-1);
        }
        free(line);
    }
    close(fd);
    if (data->check->camera != 1 || data->check->light != 3)
        return (-1);
    if (data->check->line - (data->check->sphere + data->check->cylinder + data->check->plane + 3) != 0)
        return (-1);
    return (0);
}