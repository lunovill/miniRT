#include "../includes/miniRT.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_miniRT	*data;

	if (argc != 2)
	{
		printf("Error\nBad number of arguments\n");
		return (0);
	}
    data = init_miniRT();
    if (parsing(data, argv[1]) != 0)
        return (-1);
    if (fill_struc(data, argv[1]) != 0)
        return (-1);
}