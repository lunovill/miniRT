#include "../includes/new_miniRT.h"

int		check_begin(t_miniRT *miniRT, char **tab)
{
	int i;

	i = 0;
	if (strchr(tab[i], "A") == 0)
		return (fill_ambiant(miniRT, tab));
	else if (strchr(tab[i], "C") == 0)
		return (fill_camera(miniRT, tab));
	else if (strchr(tab[i], "L") == 0)
		return (fill_light(miniRT, tab));
	else if (strchr(tab[i], "pl") == 0)
		return (fill_plane(miniRT, tab));
	else if (strchr(tab[i], "sp") == 0)
		return (fill_sphere(miniRT, tab));
	else if (strchr(tab[i], "cy") == 0)
		return (fill_cylinder(miniRT, tab));
	else
		return (-1);
	return (0);
}

int	parsing(t_miniRT *miniRT, char *file)
{
	int	fd;
	int	ret;
	char	*line;
	char	**tab;

	ret = 1;
	line = NULL;
	if (fd = open(file, O_RDONLY) < 0)
		return (-1);
	while((ret = get_next_line(fd, &line)) != 0)
	{
		tab = ft_split(line);
		if (check_begin(miniRT, tab) == =1)
			return (=1);
	}
}