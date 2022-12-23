#include "../includes/miniRT.h"

// attention si dans la str il y a pluisieur point il faut le verif avant ou dans le if il y a un point en regardant si il div != 0
// mais je ne sais pas quoi mettre en sortie en cas d'erreur

float   cara_to_float(char *str)
{
    int             neg;
    float           n;
    float			div;
    unsigned int    i;

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
            div = pow(10, (strlen(str) - i));
        }
        else
        {
            n *= 10;
            n += str[i++] - '0';
        }
    }
    return ((n * neg) / div);
}

int     fill_ambiant(t_miniRT *data, char **tab)
{
    int i;
    
    i = 0;
    while (tab[i])
        i++;
    if (i != 3)
        return (-1);
    data->l[0]->brightness = c_to_fl(tab[1]);
    
}

int     fill_camera(t_miniRT *data, char **tab)
{
    
}

int     fill_light(t_miniRT *data, char **tab)
{
    
}

int     fill_plane(t_miniRT *data, char **tab)
{
    
}

int     fill_sphere(t_miniRT *data, char **tab)
{
    
}

int     fill_cylinder(t_miniRT *data, char **tab)
{
    
}

void       init_struct(t_miniRT *data)
{
    t_light     **light;
    t_sphere    **sphere;
    t_plane     **plane;
    t_cylinder  **cylinder;
    t_camera    *camera;

    light = malloc(sizeof(*light) * (3));
    if (!light)
        return ;
    sphere = malloc(sizeof(*sphere) * (data->check->sphere + 1));
    if (!sphere)
        return ;
    plane = malloc(sizeof(*plane) * (data->check->plane + 1));
    if (!plane)
        return ;
    cylinder = malloc(sizeof(*cylinder) * (data->check->cylinder + 1));
    if (!cylinder)
        return ;
    camera = malloc(sizeof(camera) * (2));
    if (!camera)
        return ;
    data->cy = cylinder;
    data->l = light;
    data->sp = sphere;
    data->pl = plane;
    data->c = camera;
}

int     fill_struct(t_miniRT *data, char *file)
{
    int     fd;
    int     ret;
    char    *line;
    char    **tab;

    ret = 1;
    if ((fd = open(file, O_RDONLY)) < 0)
        return (-1);
    init_struct(data);
    while (ret != 0)
    {
        ret = my_gnl(fd, &line);
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
            fre(line);
            close(fd);
            return (-1);
        }
        free(line);
    }
    close(fd);
    return (0);
}