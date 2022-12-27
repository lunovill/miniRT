#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/miniRT.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
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
    while (ft_isdigit(str[i]) || str[i] == '.')
    {
        if (str[i] == '.')
        {
            printf("%lu / %d\n", strlen(str), i);
            i++;
            div = pow(10, (strlen(str) - i));
        }
        else
        {
            n *= 10;
            n += str[i++] - '0';
            printf("%.f\n", n);
        }
    }
    return ((n * neg) / div);
}*/

int    trgb_color(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_atoi(const char *str)
{
	int				morl;
	int				n;
	unsigned int	i;

	i = 0;
	n = 0;
	morl = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		morl = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		n *= 10;
		n += str[i++] - '0';
	}
	return (n * morl);
}

int	main(int argc, char **argv)
{/*
	int     tmp;

    tmp = 0;
    if (argc != 4)
    {
        printf("Wrong number of args");
        return (0);
    }
	tmp = trgb_color(tmp, ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));   
	printf("%d\n", tmp);*/
    t_miniRT    *data;
    t_camera    *cam;

    data = malloc(sizeof(*data));
    if (!data)
        return (0);
    cam = malloc(sizeof(*cam));
    if (!cam)
        return (0);
    cam->matrix = (Matrix4f){1.0, 2.0, 3.0};
    data->c = cam;
    printf("%f %f %f %f\n", data->c->matrix.s0, data->c->matrix.s1, data->c->matrix.s2, data->c->matrix.s3);
}