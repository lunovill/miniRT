#include "../includes/miniRT.h"

t_miniRT    *init_miniRT()
{
    t_miniRT    *data;
    t_check_file    *tmp;

    data = malloc(sizeof(*data));
    if (!data)
        return (NULL);
    tmp = malloc(sizeof(*tmp));
    data->garbage = gbg_add(data->garbage, tmp);
    if (!tmp)
        return (NULL);
    tmp->camera = 0;
    tmp->light = 0;
    tmp->sphere = 0;
    tmp->plane = 0;
    tmp->cylinder = 0;
    tmp->line = 0;
    data->check = tmp;
    return (data);
}