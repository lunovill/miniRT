#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


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
}

int	main(int argc, char **argv)
{
	float tmp;
	if (argc != 2)
		return (0);
	tmp = cara_to_float(argv[1]);
	printf("%4.f\n", tmp);
}