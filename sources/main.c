/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 04:45:04 by lunovill          #+#    #+#             */
/*   Updated: 2023/02/05 04:45:05 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

int	main(int argc, char **argv)
{
	t_miniRT	*data;

	if (argc != 2 || (check_name(argv[1]) == 0))
	{
		printf("Error\nBad arguments\n");
		return (0);
	}
	data = init_minirt();
	parsing(data, argv[1]);
	fill_struct(data, argv[1]);
	minirt(data);
	gbg_remove(data->garbage);
	free(data);
	return (0);
}
