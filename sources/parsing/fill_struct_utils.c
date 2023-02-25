/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <hucoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:36:33 by hucoulon          #+#    #+#             */
/*   Updated: 2023/02/25 05:48:19 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

float	c_to_f(char *str, float n, float div, unsigned int i)
{
	int				neg;

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
	fill_ambiant_utils(data, tmp, tab);
	data->l[0] = tmp;
	data->l[1] = NULL;
	data->garbage = gbg_add(data->garbage, data->l[0]);
}

void	fill_camera(t_miniRT *data, char **tab)
{
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
	fill_camera_utils(data, tmp, tab);
	data->c = tmp;
	data->garbage = gbg_add(data->garbage, data->c);
}

void	fill_struct_utils(t_miniRT *data, char *line, int fd)
{
	char	**tab;

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
	ft_ftab(tab);
}
