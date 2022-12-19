#include "../includes/miniRT.h"

// attention si dans la str il y a pluisieur point il faut le verif avant ou dans le if il y a un point en regardant si il div != 0
// mais je ne sais pas quoi mettre en sortie en cas d'erreur

float   cara_to_float(char *str)
{
    int             neg;
    float           n;
    int             div;
    unsigned int    i;

    div = 0;
    i = 0;
    n = 0;
    neg = 1;
    if (str[i] == '-')
        neg = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (ft_isdigit_dot(str[i]))
    {
        if (str[i] == '.')
        {
            div = pow(10, (ft_strlen(str) - i));
            i++;
        }
        else
        {
            n *= 10;
            n += str[i++] - '0';
        }
    }
    return (((n * (float)neg) % (float)div));
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
    data->cy = cylinder;
    data->l = light;
    data->sp = sphere;
    data->pl = plane;
}

int     fill_struct(t_miniRT *data, char *file)
{
    int     fd;
    int     ret;
    char    *line;
    char    **tab;

    ret = 1;
    line = NULL;
    if (fd = open(file, O_RDONLY) < 0)
        return (-1);
    init_struct(data);
    while (ret = get_next_line(fd, &line) != 0)
    {
        tab = ft_split(line);
        if (strchr(tab[0], "A") == 0)
            fill_ambiant(data, tab);
	    else if (strchr(tab[0], "C") == 0)
            fill_camera(data, tab);
	    else if (strchr(tab[0], "L") == 0)
            fill_light(data, tab);
	    else if (strchr(tab[0], "pl") == 0)
            fill_plane(data, tab);
	    else if (strchr(tab[0], "sp") == 0)
            fill_sphere(data, tab);
	    else if (strchr(tab[0], "cy") == 0)
            fill_cylinder(data, tab);
        else
        {
            close(fd);
            return (-1);
        }
        free(line);
    }
    close(fd);
    return (0);
}