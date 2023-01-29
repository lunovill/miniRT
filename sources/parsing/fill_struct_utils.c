#include "miniRT.h"

int	check_tab(t_miniRT *data, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		gestion_error(data, 2);
	return (0);
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

void	fill_ambiant(t_miniRT *data, char **tab)
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
	if (i != 3)
		gestion_error(data, 2);
	tmp->brightness = cara_to_float(tab[1]);
	if (tmp->brightness < 0.0 || tmp->brightness > 1.0)
		gestion_error(data, 2);
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	if ((ft_atoi(tab_nb[0]) < 0 || ft_atoi(tab_nb[0]) > 255) ||
			(ft_atoi(tab_nb[1]) < 0 || ft_atoi(tab_nb[1]) > 255) ||
			(ft_atoi(tab_nb[2]) < 0 || ft_atoi(tab_nb[2]) > 255))
		gestion_error(data, 2);
	tmp->color = (Tuple4f){tmp->brightness, ft_atoi(tab_nb[0]), ft_atoi(tab_nb[1]), ft_atoi(tab_nb[2])};
	tmp->coor = (Tuple4f){0., 0., 0., 1.};
	data->l[0] = tmp;
	data->garbage = gbg_add(data->garbage, data->l[0]);
}

void	fill_camera(t_miniRT *data, char **tab)
{
	char		**tab_nb;
	t_camera	*tmp;
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
	tmp->coor = (Tuple4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 1};
	tab_nb = ft_split(tab[2], ',');
	check_tab(data, tab_nb);
	tmp->vector = (Tuple4f){cara_to_float(tab_nb[0]), cara_to_float(tab_nb[1]), cara_to_float(tab_nb[2]), 0};
	if ((tmp->vector.s0 < -1.0 || tmp->vector.s0 > 1.0) ||
			(tmp->vector.s1 < -1.0 || tmp->vector.s1 > 1.0) ||
			(tmp->vector.s2 < -1.0 || tmp->vector.s2 > 1.0))
		gestion_error(data, 2);
	tmp->fov = cara_to_float(tab[3]) * M_PI / 180.0;
	data->c = tmp;
	data->garbage = gbg_add(data->garbage, data->c);
}