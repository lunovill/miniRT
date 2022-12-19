#include "../includes/miniRT.h"

t_miniRT    *init_miniRT()
{
    t_miniRT    *data;

    data = malloc(sizeof(*data));
    if (!data)
        return (1);
    data->check->camera = 0;
    data->check->light = 0;
    data->check->sphere = 0;
    data->check->plane = 0;
    data->check->cylinder = 0;
    data->check->line = 0;
//    data->c == NULL;
//    data->cy == NULL;
//    data->sp == NULL;
//    data->pl == NULL;
//    data->l == NULL;
    return (data);
}