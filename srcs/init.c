#include "../includes/miniRT.h"

t_miniRT	*init_minirt(void)
{
	t_miniRT		*data;
	t_check_file	*tmp;
	t_garbage		*gbg;

	data = malloc(sizeof(*data));
	if (!data)
		return (NULL);
	gbg = NULL;
	data->garbage = gbg;
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	data->garbage = gbg_add(data->garbage, tmp);
	tmp->camera = 0;
	tmp->light = 0;
	tmp->sphere = 0;
	tmp->plane = 0;
	tmp->cylinder = 0;
	tmp->line = 0;
	tmp->nb_cy = 0;
	tmp->nb_sp = 0;
	tmp->nb_pl = 0;
	data->check = tmp;
	return (data);
}