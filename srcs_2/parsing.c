#include "../includes/miniRT.h"

int		check_begin(t_miniRT *data, char **tab)
{
	int i;

	i = 0;
	if (strchr(tab[i], "A") == 0)
		data->check->light = data->check->light + 2;
	else if (strchr(tab[i], "C") == 0)
		data->check->camera++;
	else if (strchr(tab[i], "L") == 0)
		data->check->light++;
	else if (strchr(tab[i], "pl") == 0)
		data->check->plane++;
	else if (strchr(tab[i], "sp") == 0)
		data->check->sphere++;
	else if (strchr(tab[i], "cy") == 0)
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
    if (fd = open(file, O_RDONLY) < 0)
        return (-1);
    while (ret = get_next_line(fd, &line) != 0)
    {
        tab = ft_split(line);
        data->check->line++;
        if (check_begin(data, tab) == -1)
        {
            return (-1);
            close(fd);
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