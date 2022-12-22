#include "../includes/miniRT.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_miniRT	*data;

	if (argc != 2 || (check_name(argv[1]) == 0))
	{
		printf("Error\nBad arguments\n");
		return (0);
	}
    data = init_miniRT();
	if (parsing(data, argv[1]) != 0)
	{
		printf("Error parsing\n");
        return (-1);
	}
//    if (fill_struct(data, argv[1]) != 0)
//        return (-1);
	return (0);
}